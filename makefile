
source = ./main.cpp
header = ./include
compile_process : $(source) $(header)
	g++ -E main.cpp -o main.i
	g++ -S main.i -o main.s
	g++ -c main.s -o main.o
	nm -a main.o > symble_table.txt