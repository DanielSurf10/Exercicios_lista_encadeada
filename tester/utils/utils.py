import os
import subprocess


class Tester:
    def __init__(self, compiler, valgrind, include, utils, tester_folder, flags):
        subjects = []

        self.compiler = compiler
        self.valgrind = valgrind.split()
        self.include = include
        self.flags = flags
        self.utils = utils
        self.tester_folder = tester_folder
        self.exams = sorted(os.listdir(f'{tester_folder}/exam'))
        self.all_ok = True
        # self.choice = 0   # Põe aqui ou põe como parâmetro de um método

        for subject in self.exams:
            with open(f'{tester_folder}/exam/{subject}/subject.txt',
                      'r') as arq:
                subjects.append(arq.readline().split(':')[1].strip())

        self.subjects = subjects.copy()

    def test(self, choice):
        with open(f'{self.tester_folder}/grading/{self.exams[choice]}/tests.txt') as arq:
            tests = arq.read().strip().split('\n')

        print('compiling: ', end='')
        compile_result = self.compile(choice)
        if (compile_result != 0):
            print('compilation error')
            self.all_ok = False
            return 1    # Erro de compilação
        else:
            print('ok')

        os.system(f'mkdir -p {self.tester_folder}/tmp')
        os.system(f'mkdir -p trace/{self.exams[choice]}')
        os.system(f'echo -n "" > trace/{self.exams[choice]}/trace_errors')
        os.system(f'echo -n "" > trace/{self.exams[choice]}/trace_all')

        subject_tests = []
        for subject in tests:
            subject_tests.append(SubjectTest(subject))

        for test in subject_tests:
            print(f'testing {test.name}: ', end='')
            test_result = self.run_tests(choice, test.test)
            if (test_result == 0):
                print('ok')
            else:
                if (test_result == 1):
                    print('ko')
                else:
                    print('ko_leak')
                self.all_ok = False

    def compile(self, choice):
        main = f'{self.tester_folder}/grading/{self.exams[choice]}/main.c'
        command_original = [self.compiler, self.flags, '-I', self.include, f'{self.tester_folder}/grading/{self.exams[choice]}/{self.subjects[choice]}.c', main, self.utils, '-o', f'{self.tester_folder}/tmp/original']
        command_for_test = [self.compiler, self.flags, '-I', self.include, f'rendu/{self.exams[choice]}/{self.subjects[choice]}.c', main, self.utils, '-o', f'{self.tester_folder}/tmp/for_test']

        sub_run(command_original)
        compile_result_for_test = subprocess.run(command_for_test)

        return compile_result_for_test.returncode

    def run_tests(self, choice, test):
        command_original = [f'{self.tester_folder}/tmp/for_test', test]
        command_for_test = self.valgrind.extend([f'{self.tester_folder}/tmp/for_test', test])

        result_original = sub_run(command_original)
        result_for_test = sub_run(command_for_test)

        # todo: colocar o resultado no arquivo de trace_all
        # todo: verificar se o resultado é igual ao esperado e o retorno é igual a 0
        # todo: se não for igual, colocar o resultado no arquivo de trace_errors
        # todo: verificar se o stdrr do valgrind é igual a 0


class SubjectTest:
    def __init__(self, test_line):
        test = test_line.split(':')
        self.name = test[0].strip()
        self.test = test[1].strip()


def print_header():
    print('-' * 50)
    print(f'|{"Exercícios".center(48)}|')
    print(f'|{"de".center(48)}|')
    print(f'|{"lista".center(48)}|')
    print(f'|{"encadeada".center(48)}|')
    print('-' * 50)
    print()


def get_choice(tester):
    print('0 - Arrumar ambinete')
    for sub in range(len(tester.subjects)):
        print(f'{sub + 1} - {tester.subjects[sub]}')
    print()
    choice = int(input('Qual é a sua escolha: ')) - 1
    print('-' * 50)
    return (choice)


def arrange_environment(tester):
    for folder in tester.exam:
        os.system(f'mkdir -p rendu/{folder}')

    os.system(f'cp {tester.tester_folder}/include/linked_list.h rendu')

    if (not os.path.isfile(f'{tester.tester_folder}/linked_list.a')):
        os.system(f'make -C {tester.tester_folder}/src_lista all clean')
    os.system(f'cp {tester.tester_folder}/linked_list.a rendu')
    os.system(f'cp -rf {tester.tester_folder}/exam/* exam')


def sub_run(command):
    return subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
