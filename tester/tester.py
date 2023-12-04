import os
import subprocess
# import tester.utils.utils


class UnitaryTest:
	def __init__(self, test_line):
		test = test_line.split(':')
		self.name = test[0].strip()
		self.test = test[1].strip()


# Utils variables
all_ok = True
tester_folder = 'tester'
utils_folder = f'{tester_folder}/utils'
valgrind = 'valgrind -q --leak-check=full --show-leak-kinds=all'
utils = f'{utils_folder}/utils.c {utils_folder}/linked_list.a'
include = f'{utils_folder}/include'
flags = '-Wall -Wextra -Werror'

# Other variables used
exams = []
choice = 0
original_file = ''
for_test_file = ''
compile_original = ''
compile_for_test = ''
result_original = ''
result_for_test = ''
read_test = ''
tests_splited = []
tests = []
size_line = 0


with open(f'{tester_folder}/grading/exam.txt', 'r') as arq:
	exam_read_result = arq.read().strip()

exams = exam_read_result.split('\n')

print('-' * 50)
print(f'|{"Exercícios".center(48)}|')
print(f'|{"de".center(48)}|')
print(f'|{"lista".center(48)}|')
print(f'|{"encadeada".center(48)}|')
print('-' * 50)
print()

print('0 - Arrumar ambinete')
for i in range(len(exams)):
	print(f'{i + 1} - {exams[i]}')
print()

choice = int(input('Qual é a sua escolha: ')) - 1
print('-' * 50)

if choice == -1:
	os.system('mkdir -p exam')

	for exam in exams:
		os.system(f'mkdir -p rendu/{exam}')
		os.system(f'mkdir -p exam/{exam}')
		os.system(f'cp -f {tester_folder}/grading/{exam}/subject.txt exam/{exam}')

	os.system(f'cp {include}/linked_list.h rendu')

	if (not os.path.isfile(f'{utils_folder}/linked_list.a')):
		os.system(f'make -C {utils_folder}/src_lista all clean')
	os.system(f'cp {utils_folder}/linked_list.a rendu')

	os.system(f'cp -f {tester_folder}/grading/exam.txt "exam/ordem dos exercícios.txt"')

	exit()

original_file = f'{tester_folder}/grading/{exams[choice]}/{exams[choice]}.c'
for_test_file = f'rendu/{exams[choice]}/{exams[choice]}.c'

os.system('mkdir -p tester/tmp')
os.system(f'mkdir -p trace/{exams[choice]}')
os.system(f'echo -n "" > trace/{exams[choice]}/trace_errors')
os.system(f'echo -n "" > trace/{exams[choice]}/trace_all')

print('compiling: ', end='')

compile_original = f'cc {flags} -I {include} {original_file} {tester_folder}/grading/{exams[choice]}/main.c {utils} -o {tester_folder}/tmp/original'
compile_for_test = f'cc {flags} -I {include} {for_test_file} {tester_folder}/grading/{exams[choice]}/main.c {utils} -o {tester_folder}/tmp/for_test'

result_original = subprocess.run(compile_original, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
result_for_test = subprocess.run(compile_for_test, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

if (result_for_test.returncode != 0):
	print('compilation error\n', result_for_test.stderr)
	all_ok = False
else:
	print('ok')
	print('-' * 50)


if all_ok:
	with open(f'{tester_folder}/grading/{exams[choice]}/tests.txt') as arq:
		read_test = arq.read().strip()
	tests_splited = read_test.split('\n')

	tests = [UnitaryTest(test) for test in tests_splited]
	size_line = len(max([test.name for test in tests], key=len))

	for test in tests:
		print(f'{test.name.ljust(size_line)}', end=' : ')

		result_original = subprocess.run(f'{tester_folder}/tmp/original {test.test}', shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
		result_for_test = subprocess.run(f'{valgrind} {tester_folder}/tmp/for_test {test.test}', shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

		fd_trace_all = open(f'trace/{exams[choice]}/trace_all', 'a')
		fd_trace_all.write(f'Test:		{test.name}\n')
		fd_trace_all.write(f'Expected:	{result_original.stdout}')
		fd_trace_all.write(f'Yours:		{result_for_test.stdout}')
		fd_trace_all.write('status:		')

		if (result_original.stdout == result_for_test.stdout and result_for_test.returncode == 0 and result_for_test.stderr == ''):
			print('ok')
			fd_trace_all.write('ok\n\n')
		else:
			fd_trace_error = open(f'trace/{exams[choice]}/trace_errors', 'a')
			fd_trace_error.write(f'Test:		{test.name}\n')
			fd_trace_error.write(f'Expected:	{result_original.stdout}')
			fd_trace_error.write(f'Yours:		{result_for_test.stdout}')
			fd_trace_error.write('status:		')

			if (result_for_test.returncode != 0):
				print('ko_seg_falt')
				fd_trace_all.write('ko_seg_falt\n\n')
				fd_trace_error.write('ko_seg_falt\n\n')
			elif (result_for_test.stderr != ''):
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

print('-' * 50)

os.system(f'rm -rf {tester_folder}/tmp')
