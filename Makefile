all:
	g++ -std=c++14 cpu.cc -c -o cpu.o
	g++ -std=c++14 helper.cc -c -o helper.o
	g++ -std=c++14 main.cc -c -o main.o
	g++ -std=c++14 main.o cpu.o helper.o -o a.out
	./a.out

clean:
	rm -rf *.o *.out