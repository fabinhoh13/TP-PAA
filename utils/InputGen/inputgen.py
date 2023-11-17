# Script utilizado para gerar arquivos de entrada desordenados que serão utilizados pelos algoritmos
# Arquivos de entrada possuem formato *.in
# Arquivos de saída possuem formato *.out

import random, os
i = 100
j = 1
instance_sizes = [10, 20, 30, 40, 50, 60, 70, 80, 90]
while j <= 16:
    instance_sizes.append(i)
    i *= 2
    j+= 1


number_instances = 20

for instance in instance_sizes:
    print(f"[+] Running Instance: N{instance}")
    for number in range(1,number_instances+1):
        filename = f"./input/a1/n{instance}/instance-n{instance}-{number}.in"
        os.makedirs(os.path.dirname(filename), exist_ok=True)
        with open(filename, "w") as f:
            f.write("100" + "\n")
            for i in range(instance):
                peso = random.randint(0, 30)
                valor = random.randint(1, 100)
                f.write(str(peso) + " " + str(valor) + "\n")
                
for instance in instance_sizes:
    print(f"[+] Running Weight: N{instance}")
    for number in range(1,number_instances+1):
        filename = f"./input/a2/n{instance}/weight-W{instance}-{number}.in"
        os.makedirs(os.path.dirname(filename), exist_ok=True)
        with open(filename, "w") as f:
            f.write(str(instance) + "\n")
            for i in range(1, 401):
                peso = random.randint(0, 30)
                valor = random.randint(1, 100)
                f.write(str(peso) + " " + str(valor) + "\n")