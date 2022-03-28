all: test-addi test-slti

.PHYON: test-addi
test-addi:
	mkdir -p ./obj
	mkdir -p ./bin
	g++ -std=c++14 cpu.cc -c -o ./obj/cpu.o
	g++ -std=c++14 helper.cc -c -o ./obj/helper.o
	g++ -std=c++14 ./test/test_addi.cc -I./ -c -o ./obj/test_addi.o
	g++ -std=c++14 ./obj/test_addi.o ./obj/cpu.o ./obj/helper.o -o ./bin/test-addi
	./bin/test-addi

.PHYON: test-slti
test-slti:
	mkdir -p ./obj
	mkdir -p ./bin
	g++ -std=c++14 cpu.cc -c -o ./obj/cpu.o
	g++ -std=c++14 helper.cc -c -o ./obj/helper.o
	g++ -std=c++14 ./test/test_slti.cc -I./ -c -o ./obj/test_slti.o
	g++ -std=c++14 ./obj/test_slti.o ./obj/cpu.o ./obj/helper.o -o ./bin/test-slti
	./bin/test-slti

clean:
	rm -rf ./obj ./bin