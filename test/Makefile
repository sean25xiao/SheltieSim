add:
	riscv64-unknown-elf-gcc -Wl,-Ttext=0x0 -nostdlib -o ../obj/add-addi add-addi.s
	riscv64-unknown-elf-objcopy -O binary ../obj/add-addi ../obj/add-addi.bin

clean:
	rm -rf ../obj/*.bin ../obj/add-addi