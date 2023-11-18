import matplotlib.pyplot as plt
import re
from pathlib import Path

def is_even(row):
    return row % 2 == 0

def extract_confidence_interval(filepath):
    with open(filepath, "r") as f:
        for line in f:
            if "Intervalo de Confiança" in line:
                match = re.search(r"\((.*); (.*)\)", line)
                if match:
                    return match.group(0)
    return None

def create_table(data, row_labels, col_labels, ax):
    table = ax.table(cellText=data, rowLabels=row_labels, colLabels=col_labels, loc="center")
    table.auto_set_font_size(False)
    table.set_fontsize(10)
    table.scale(1, 1.5)
    table.auto_set_column_width(col=list(range(len(data[0]))))
    for (row, col), cell in table.get_celld().items():
        cell.set_edgecolor("black")
        cell.get_text().set_horizontalalignment('center')
        if row == 0:
            cell.set_facecolor('#83c5be')
            cell.set_fontsize(13)
            cell.set_height(.08)
        elif is_even(row):
            cell.set_facecolor('#edf6f9')
        else:
            cell.set_facecolor('#e5e5e5')
    return table

filepath = Path("../../output/TPairedTests/")
folders = ["10", "20", "30", "40", "50", "60", "70", "80", "90", "100", "200", "400", "800", "1600", "3200", "6400", "12800", "25600", "51200", "102400", "204800", "409600", "819200", "1638400", "3276800"]
comparisons = [
    ("BranchAndBound", "Iteractive"),
    ("Iteractive", "SegundoTeste"),
    ("BranchAndBound", "SegundoTeste"),
]

results = [[] for _ in comparisons]
for folder in folders:
    for i, (alg1, alg2) in enumerate(comparisons):
        file_path = filepath / f"n{folder}" / f"{alg1}-X-{alg2}.out"
        confidence_interval = extract_confidence_interval(file_path)
        if confidence_interval:
            results[i].append(confidence_interval)

fig, ax = plt.subplots()
ax.axis('off')

col_labels = ["10", "20", "30", "40", "50", "60", "70", "80", "90", "100", "200", "400", "800", "1600", "3200", "6400", "12800", "25600", "51200", "102400", "204800", "409600", "819200", "1638400", "3276800"]
table_data = results
comparisons = [(alg1.replace('_', ' '), alg2.replace('_', ' ')) for alg1, alg2 in comparisons]
row_labels = [f"{alg1} vs {alg2}" for alg1, alg2 in comparisons]
create_table(table_data, row_labels, col_labels, ax)

fig = plt.gcf()
fig.subplots_adjust(top=1, bottom=0, right=1, left=0, hspace=0, wspace=0)


plt.savefig("../../tables/algs_teste_t_comparacoes.png", bbox_inches='tight', pad_inches=0, transparent = True,  dpi=200)
