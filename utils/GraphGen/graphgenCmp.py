import os
import pandas as pd
import matplotlib.pyplot as plt

# Caminho dos arquivos e nomes dos algoritmos
folders = ["n10", "n20", "n30", "n40", "n50", "n60", "n70", "n80", "n90", "n100", "n200", "n400", "n800", "n1600", "n3200", "n6400", "n12800", "n25600", "n51200", "n102400", "n204800", "n409600", "n819200", "n1638400", "n3276800"]
algorithms = ["Iteractive","BranchAndBound", 'BackTrack']

results = {algorithm: {} for algorithm in algorithms}

for folder in folders:
    # Calcula a potência de 10 correspondente
    power_of_10 = folder.replace("n", "")
    
    for algorithm in algorithms:
        # Lê o arquivo e extrai o tempo médio
        with open(f"../../output/{folder}/{algorithm}.out") as f:
            avg_time = float(f.readlines()[-1].split()[-1])
            results[algorithm][power_of_10] = avg_time

# Cria um DataFrame
df = pd.DataFrame(results)

# Usa um estilo predefinido
plt.style.use('ggplot')

# Plota o gráfico
ax = df.plot(kind='line', grid=True, linewidth=2.0, marker='o')
plt.ylabel('Tempo Médio', fontsize=12)
plt.xlabel('Tamanho da entrada', fontsize=12)
plt.title('Comparação entre os três Algoritmos', fontsize=10)

# Personaliza a legenda
plt.legend(fontsize=10, title_fontsize='10')

plt.savefig(f"../../graphs/AllAlgs.png", dpi=200)
