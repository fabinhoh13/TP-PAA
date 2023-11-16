#!/bin/bash

echo "[+] Gerando Testes T Pareados"

cd ../StatisticsGen

for i in 100 200 400 800 1600 3200 6400 12800 25600 51200 102400 204800 409600 819200 1638400 3276800; do
    mkdir -p ../../output/TPairedTests/n$i
    python3.10 TPairedAlg.py $i BranchAndBound > ../../output/TPairedTests/n$i/BranchAndBound.out 
done

echo "[+] Testes Finalizados!"