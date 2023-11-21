import os
import subprocess

all_ok = True
subjects = []
# valgrind = 'valgrind -q --leak-check=full --show-leak-kinds=all'
valgrind = ''
utils = 'tester/utils/utils.c tester/linked_list.a'
include = 'tester/include'
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

	os.system('cp tester/include/linked_list.h rendu')

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

	tester = f'tester/grading/{exam[choice]}/tests/{main}'

	command_original = f'cc -I {include} {original_file} {tester} {utils} -o tester/tmp/original'
	command_for_test = f'cc -I {include} {for_test_file} {tester} {utils} -o tester/tmp/for_test'

	result_original = subprocess.run(command_original, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
	result_for_test = subprocess.run(command_for_test, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

	if (result_for_test.returncode != 0 or result_original.returncode != 0):
		print("compilation error", result_for_test.__dict__)
		all_ok = False
		continue

	result_original = os.system('tester/tmp/original > tester/tmp/original.out')
	result_for_test = os.system(f'{valgrind} tester/tmp/for_test > tester/tmp/for_test.out')

	with open('tester/tmp/original.out', 'r') as arq_original:
		read_original = arq_original.read()

	with open('tester/tmp/for_test.out', 'r') as arq_for_test:
		read_for_test = arq_for_test.read()

	if (read_original == read_for_test and result_for_test == 0):
		print('ok')
	else:
		print('ko')
		all_ok = False

		with open(f'trace/{exam[choice]}/trace_errors', 'a') as arq:
			arq.write(f'Test:		{main}\n')
			arq.write(f'Expected:	{read_original}')
			arq.write(f'Yours:		{read_for_test}\n')

	with open(f'trace/{exam[choice]}/trace_all', 'a') as arq:
		arq.write(f'Test:		{main}\n')
		arq.write(f'Expected:	{read_original}')
		arq.write(f'Yours:		{read_for_test}\n')

print('-' * 50)

if (all_ok):
	print('Funcionou! :)')
else:
	print('Não funcionou!')

os.system('rm -rf tester/tmp')
