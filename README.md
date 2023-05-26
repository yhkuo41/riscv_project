# RISC V Project
A demo project for learning the RISC-V instruction set, the program is the same as the MIPS project 2 (postfix calculator).

You can build the project and run it by

    ./main.out < postfix_input.txt

## How to build the project
1. Make sure to clean old files

        make clean

2. Using one of the following command to build
* linux x86
  
        make
* riscv32-unknown-elf-g++
        
        make CC=riscv32-unknown-elf-g++ OBJDUMP=riscv32-unknown-elf-objdump 
* riscv32-unknown-linux-gnu-g++

        make CC=riscv32-unknown-linux-gnu-g++ OBJDUMP=riscv32-unknown-linux-gnu-objdump
* linux x86 (static option)
  
        make CFLAGS="-static -Wall -ansi -std=c++14 -O0 -fno-asynchronous-unwind-tables -fno-exceptions -fno-rtti -fverbose-asm"

* riscv32-unknown-elf-g++ (static option)
        
        make CC=riscv32-unknown-elf-g++ OBJDUMP=riscv32-unknown-elf-objdump CFLAGS="-static -Wall -ansi -std=c++14 -O0 -fno-asynchronous-unwind-tables -fno-exceptions -fno-rtti -fverbose-asm"

* riscv32-unknown-linux-gnu-g++ (static option)

        make CC=riscv32-unknown-linux-gnu-g++ OBJDUMP=riscv32-unknown-linux-gnu-objdump CFLAGS="-static -Wall -ansi -std=c++14 -O0 -fno-asynchronous-unwind-tables -fno-exceptions -fno-rtti -fverbose-asm"