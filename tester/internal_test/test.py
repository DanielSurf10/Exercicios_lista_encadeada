import sys
import subprocess
import os


class UnitaryTest:
    def __init__(self, test_line):
        test = test_line.split(':')
        self.name = test[0].strip()
        self.test = test[1].strip()

try:
    exercise = sys.argv[1]
except IndexError:
    print('Sem argumentos!')
    exit()

try:
    if (sys.argv[2] == 'v'):
        valgrind = 'valgrind -q --leak-check=full --show-leak-kinds=all'
    else:
        valgrind = ''
except IndexError:
    valgrind = ''

# valgrind = 'valgrind -q --leak-check=full --show-leak-kinds=all'

print('compiling: ', end='')

os.system('echo -n "" > tester/internal_test/trace_all')

command = f'cc -g3 -Wall -Wextra -Werror -I tester/utils/include tester/grading/{exercise}/{exercise}.c tester/grading/{exercise}/main.c tester/utils/utils.c tester/utils/linked_list.a -o tester/internal_test/test'
result = subprocess.run(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

if (result.returncode != 0):
    print('compilation error\n', result.stderr)
    exit()
else:
    print('ok')
    print('-' * 50)

with open(f'tester/grading/{exercise}/tests.txt') as arq:
    read_test = arq.read().strip()

tests_splited = read_test.split('\n')

tests = [UnitaryTest(test) for test in tests_splited]
size_line = len(max([test.name for test in tests], key=len))

for test in tests:
    print(f'{test.name.ljust(size_line)}', end=' : ')

    result = subprocess.run(f'{valgrind} tester/internal_test/test {test.test}', shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    fd_trace_all = open('tester/internal_test/trace_all', 'a')

    if (result.returncode == 0 and result.stderr == ''):
        print('ok')
        fd_trace_all.write(f'Test:		{test.name}\n')
        fd_trace_all.write(f'Expected:	{result.stdout}')
        fd_trace_all.write('status:		ok\n\n')
    else:
        fd_trace_all.write(f'Test:		{test.name}\n')
        fd_trace_all.write(f'Expected:	{result.stdout}{chr(10) if result.returncode != 0 else ""}')
        fd_trace_all.write('status:		')

        if (result.returncode != 0):
            print('ko_seg_falt')
            fd_trace_all.write('ko_seg_falt\n\n')
        elif (result.stderr != ''):
            print('ko_leak')
            fd_trace_all.write('ko_leak\n\n')
        else:
            print('ko')
            fd_trace_all.write('ko\n\n')

    fd_trace_all.close()

print('-' * 50)

# os.system('rm -f tester/internal_test/test')
