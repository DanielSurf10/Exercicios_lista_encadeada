import os

valgrind = 'valgrind -q --leak-check=full --show-leak-kinds=all'
exam = os.listdir("exam")
subjects = []

for a in exam:
	with open(f"exam/{a}/subject.txt", 'r') as arq:
		subjects.append(arq.readline().split(":")[1].strip())

print("-" * 50)
print(f"|{'Exercícios'.center(48)}|")
print(f"|{'de'.center(48)}|")
print(f"|{'lista'.center(48)}|")
print(f"|{'encadeada'.center(48)}|")
print("-" * 50)

print()
for sub in range(len(subjects)):
	print(f"{sub} - {subjects[sub]}")
print()

choice = int(input("Qual é a sua escolha: "))
print("-" * 50)

tests = os.listdir(f'grading/{exam[choice]}/tests')
original_file = f'grading/{exam[choice]}/{subjects[choice]}.c'
for_test_file = f'rendu/{exam[choice]}/{subjects[choice]}.c'

os.system(f"mkdir -p trace/{exam[choice]}")
os.system(f"rm -f trace/{exam[choice]}/trace")
os.system(f"rm -f trace/{exam[choice]}/trace_all")

for main in tests:

	os.system(f"cc -I . {original_file} grading/{exam[choice]}/tests/{main} linked_list.a -o original")
	os.system(f"cc -I . {for_test_file} grading/{exam[choice]}/tests/{main} linked_list.a -o for_test")

	os.system(f"{valgrind} ./original > trace/{exam[choice]}/original.out")
	os.system(f"{valgrind} ./for_test > trace/{exam[choice]}/for_test.out")

	os.system(f"diff trace/{exam[choice]}/original.out \
			trace/{exam[choice]}/for_test.out\
			>> trace/{exam[choice]}/trace")

	arq_original = open(f"trace/{exam[choice]}/original.out", 'r')
	arq_for_test = open(f"trace/{exam[choice]}/for_test.out", 'r')

	print(main, end=' : ')

	if (arq_original.read() == arq_for_test.read()):
		print('ok')
	else:
		print('ko')

	os.system(f"cat trace/{exam[choice]}/original.out >> trace/{exam[choice]}/trace_all")
	os.system(f"cat trace/{exam[choice]}/for_test.out >> trace/{exam[choice]}/trace_all")

os.system("rm for_test original")
os.system(f"rm trace/{exam[choice]}/for_test.out trace/{exam[choice]}/original.out")

print("-" * 50)

with open(f"trace/{exam[choice]}/trace", 'r') as arq:
	if (arq.read() == ''):
		print("Funcionou! :)")
	else:
		print("Não funcionou!")
