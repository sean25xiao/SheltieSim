g++ cpu.cc -c -o cpu.o
g++ main.cc -c -o main.o
g++ main.o cpu.o -o a.out
./a.out