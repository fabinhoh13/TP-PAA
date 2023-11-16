all:
	g++ *.cpp -o tp1 -Wall

run:
	mkdir -p ../output/n$(TAM)
ifeq ($(ALG),1)
	./tp1 $(ALG) $(TAM) > ../output/n$(TAM)/Iteractive.out
else ifeq ($(ALG),2)
	./tp1 $(ALG) $(TAM) > ../output/n$(TAM)/BranchAndBound.out
else ifeq ($(ALG),3)
	./tp1 $(ALG) $(TAM) > ../output/n$(TAM)/BackTrack.out
else ifeq ($(ALG),4)
	./tp1 $(ALG) $(TAM) > ../output/n$(TAM)/SegundoTeste.out
endif
