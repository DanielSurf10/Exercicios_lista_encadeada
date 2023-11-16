import os

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
