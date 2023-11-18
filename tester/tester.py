import os

subjects = []
valgrind = 'valgrind -q --leak-check=full --show-leak-kinds=all'
exam = sorted(os.listdir('tester/exam'))

for a in exam:
	with open(f'tester/exam/{a}/subject.txt', 'r') as arq:
		subjects.append(arq.readline().split(':')[1].strip())

print('-' * 50)
print(f'|{"Exercícios".center(48)}|')
print(f'|{"de".center(48)}|')
print(f'|{"lista".center(48)}|')
print(f'|{"encadeada".center(48)}|')
print('-' * 50)

print()
print('0 - Arrumar ambinete')
for sub in range(len(subjects)):
	print(f'{sub + 1} - {subjects[sub]}')
print()

choice = int(input('Qual é a sua escolha: ')) - 1
print('-' * 50)

if choice == -1:
	for folder in exam:
		os.system(f'mkdir -p rendu/{folder}')

	os.system('cp tester/linked_list.h rendu')

	if (not os.path.isfile('tester/linked_list.a')):
		os.system('make -C tester/src_lista all clean')
	os.system('cp tester/linked_list.a rendu')

	if (not os.path.exists('exam')):
		os.system('cp -r tester/exam exam')

	exit()

tests = sorted(os.listdir(f'tester/grading/{exam[choice]}/tests'))
original_file = f'tester/grading/{exam[choice]}/{subjects[choice]}.c'
for_test_file = f'rendu/{exam[choice]}/{subjects[choice]}.c'

os.system('mkdir -p tester/tmp')
os.system(f'mkdir -p trace/{exam[choice]}')
os.system(f'echo -n "" > trace/{exam[choice]}/trace_errors')
os.system(f'echo -n "" > trace/{exam[choice]}/trace_all')

for main in tests:
	print(main, end=' : ')

	os.system(f'cc -I tester {original_file} tester/grading/{exam[choice]}/tests/{main} tester/linked_list.a -o tester/tmp/original')
	os.system(f'cc -I tester {for_test_file} tester/grading/{exam[choice]}/tests/{main} tester/linked_list.a -o tester/tmp/for_test')

	os.system('tester/tmp/original > tester/tmp/original.out')
	os.system(f'{valgrind} tester/tmp/for_test > tester/tmp/for_test.out')

	with open('tester/tmp/original.out', 'r') as arq_original:
		read_original = arq_original.read()

	with open('tester/tmp/for_test.out', 'r') as arq_for_test:
		read_for_test = arq_for_test.read()

	if (read_original == read_for_test):
		print('ok')
	else:
		print('ko')

		with open(f'trace/{exam[choice]}/trace_errors', 'a') as arq:
			arq.write(f'Test:		{main}\n')
			arq.write(f'Expected:	{read_original}')
			arq.write(f'Yours:		{read_for_test}\n')

	with open(f'trace/{exam[choice]}/trace_all', 'a') as arq:
		arq.write(f'Test:		{main}\n')
		arq.write(f'Expected:	{read_original}')
		arq.write(f'Yours:		{read_for_test}\n')

print('-' * 50)

with open(f'trace/{exam[choice]}/trace_errors', 'r') as arq:
	if (arq.read() == ''):
		print('Funcionou! :)')
	else:
		print('Não funcionou!')

os.system('rm -rf tester/tmp')
