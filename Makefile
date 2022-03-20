all:
	g++ cpu.cc -c -o cpu.o
	g++ helper.cc -c -o helper.o
	g++ main.cc -c -o main.o
	g++ main.o cpu.o helper.o -o a.out
	./a.out

clean:
	rm -rf *.o *.out