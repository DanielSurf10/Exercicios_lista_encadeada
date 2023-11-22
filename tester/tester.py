import os
import subprocess
# import tester.utils.utils

all_ok = True
subjects = []
valgrind = 'valgrind -q --leak-check=full --show-leak-kinds=all'
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

	os.system('cp -rf tester/exam/* exam')

	exit()

# tests = sorted(os.listdir(f'tester/grading/{exam[choice]}/tests'))
original_file = f'tester/grading/{exam[choice]}/{subjects[choice]}.c'
for_test_file = f'rendu/{exam[choice]}/{subjects[choice]}.c'

os.system('mkdir -p tester/tmp')
os.system(f'mkdir -p trace/{exam[choice]}')
os.system(f'echo -n "" > trace/{exam[choice]}/trace_errors')
os.system(f'echo -n "" > trace/{exam[choice]}/trace_all')

with open(f'tester/grading/{exam[choice]}/tests.txt') as arq:
	tests = arq.read().split('\n')[:-1]

for i in range(len(tests)):
	print(f'{i:>2}', end=' : ')

	command_original = f'cc -I {include} {original_file} tester/grading/{exam[choice]}/main.c {utils} -o tester/tmp/original'
	command_for_test = f'cc -I {include} {for_test_file} tester/grading/{exam[choice]}/main.c {utils} -o tester/tmp/for_test'

# for main in tests:
# 	print(main, end=' : ')
#
# 	tester_main = f'tester/grading/{exam[choice]}/tests/{main}'
#
# 	command_original = f'cc -I {include} {original_file} {tester_main} {utils} -o tester/tmp/original'
# 	command_for_test = f'cc -I {include} {for_test_file} {tester_main} {utils} -o tester/tmp/for_test'
#
# 	result_original = subprocess.run(command_original, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
# 	result_for_test = subprocess.run(command_for_test, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
#
# 	if (result_for_test.returncode != 0 or result_original.returncode != 0):
# 		print("compilation error", result_for_test.__dict__)
# 		all_ok = False
# 		continue
#
# 	result_original = subprocess.run('tester/tmp/original', shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
# 	result_for_test = subprocess.run(f'{valgrind} tester/tmp/for_test', shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
#
# 	if (result_original.stdout == result_for_test.stdout and result_for_test.returncode == 0 and result_for_test.stderr == ''):
# 		print('ok')
# 	else:
# 		if (result_for_test.stderr != ''):
# 			print('ko_leak')
# 		else:
# 			print('ko')
# 		all_ok = False
#
# 		with open(f'trace/{exam[choice]}/trace_errors', 'a') as arq:
# 			arq.write(f'Test:		{main}\n')
# 			arq.write(f'Expected:	{result_for_test.stdout}')
# 			arq.write(f'Yours:		{result_for_test.returncode}\n')
#
# 	with open(f'trace/{exam[choice]}/trace_all', 'a') as arq:
# 		arq.write(f'Test:		{main}\n')
# 		arq.write(f'Expected:	{result_for_test.stdout}')
# 		arq.write(f'Yours:		{result_for_test.returncode}\n')

print('-' * 50)

if (all_ok):
	print('Funcionou! :)')
else:
	print('Não funcionou!')

os.system('rm -rf tester/tmp')
