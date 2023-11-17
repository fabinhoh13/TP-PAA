import random, os

number_instances = 20
instance = 10

for number in range(1,number_instances+1):
    filename = f"./input/a1/n{instance}/instance-n{instance}-{number}.in"
    os.makedirs(os.path.dirname(filename), exist_ok=True)
    with open(filename, "w") as f:
        f.write("100" + "\n")
        for i in range(instance):
            peso = random.randint(0, 30)
            valor = random.randint(1, 100)
            f.write(str(peso) + " " + str(valor) + "\n")