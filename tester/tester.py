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

original_file = f'tester/grading/{exam[choice]}/{subjects[choice]}.c'
for_test_file = f'rendu/{exam[choice]}/{subjects[choice]}.c'

os.system('mkdir -p tester/tmp')
os.system(f'mkdir -p trace/{exam[choice]}')
os.system(f'echo -n "" > trace/{exam[choice]}/trace_errors')
os.system(f'echo -n "" > trace/{exam[choice]}/trace_all')

print('compiling: ', end='')

compile_original = f'cc -I {include} {original_file} tester/grading/{exam[choice]}/main.c {utils} -o tester/tmp/original'
compile_for_test = f'cc -I {include} {for_test_file} tester/grading/{exam[choice]}/main.c {utils} -o tester/tmp/for_test'

result_original = subprocess.run(compile_original, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
result_for_test = subprocess.run(compile_for_test, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

if (result_for_test.returncode != 0):
	print("compilation error")
	all_ok = False
else:
	print('ok')

if all_ok:
	with open(f'tester/grading/{exam[choice]}/tests.txt') as arq:
		read_test = arq.read().strip()

	tests = read_test.split('\n')

	for i in range(len(tests)):
		print(f'test {i:>2}', end=' : ')

		test = tests[i].split(':')[1].strip()

		result_original = subprocess.run(f'tester/tmp/original {test}', shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
		result_for_test = subprocess.run(f'{valgrind} tester/tmp/for_test {test}', shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

		fd_trace_all = open(f'trace/{exam[choice]}/trace_all', 'a')
		fd_trace_all.write(f'Test:		teste {i}\n')
		fd_trace_all.write(f'Expected:	{result_original.stdout}')
		fd_trace_all.write(f'Yours:		{result_for_test.stdout}')
		fd_trace_all.write('status:		')

		if (result_original.stdout == result_for_test.stdout and result_for_test.returncode == 0 and result_for_test.stderr == ''):
			print('ok')
			fd_trace_all.write('ok\n\n')
		else:
			fd_trace_error = open(f'trace/{exam[choice]}/trace_errors', 'a')
			fd_trace_error.write(f'Test:		teste {i}\n')
			fd_trace_error.write(f'Expected:	{result_original.stdout}')
			fd_trace_error.write(f'Yours:		{result_for_test.stdout}')
			fd_trace_error.write('status:		')

			if (result_for_test.stderr != ''):
				print('ko_leak')
				fd_trace_all.write('ko_leak\n\n')
				fd_trace_error.write('ko_leak\n\n')
			else:
				print('ko')
				fd_trace_all.write('ko\n\n')
				fd_trace_error.write('ko\n\n')
			all_ok = False
			fd_trace_error.close()

		fd_trace_all.close()

print('-' * 50)

if (all_ok):
	print('Funcionou! :)')
else:
	print('Não funcionou!')

os.system('rm -rf tester/tmp')
