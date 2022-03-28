all: test-addi test-slti

.PHYON: test-addi
test-addi:
	mkdir -p ../obj/
	riscv64-unknown-elf-gcc -Wl,-Ttext=0x0 -nostdlib -o ../obj/rv32i-addi.o rv32i-addi.s
	riscv64-unknown-elf-objcopy -O binary ../obj/rv32i-addi.o ../obj/rv32i-addi.bin

.PHYON: test-slti
test-slti:
	mkdir -p ../obj/
	riscv64-unknown-elf-gcc -Wl,-Ttext=0x0 -nostdlib -o ../obj/rv32i-slti.o rv32i-slti.s
	riscv64-unknown-elf-objcopy -O binary ../obj/rv32i-slti.o ../obj/rv32i-slti.bin

clean:
	rm -rf ../obj/*.bin ../obj/*.o ../obj/