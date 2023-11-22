import os


class Tester:
    def __init__(self, compiler, valgrind, include, utils, tester_folder):
        subjects = []

        self.compiler = compiler
        self.valgrind = valgrind
        self.include = include
        self.utils = utils
        self.tester_folder = tester_folder
        self.exams = sorted(os.listdir(f'{tester_folder}/exam'))
        self.allok = True
        # self.choice = 0   # Põe aqui ou põe como parâmetro de um método

        for subject in self.exams:
            with open(f'{tester_folder}/exam/{subject}/subject.txt',
                      'r') as arq:
                subjects.append(arq.readline().split(':')[1].strip())

        self.subjects = subjects.copy()

    def test():
        ...


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
    os.system('cp -rf tester/exam/* exam')
