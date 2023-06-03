CC := g++
# CC := riscv32-unknown-elf-g++
# CC := riscv32-unknown-linux-gnu-g++
OBJDUMP := objdump
# OBJDUMP := riscv32-unknown-elf-objdump
# OBJDUMP := riscv32-unknown-linux-gnu-objdump
CFLAGS := -Wall -ansi -std=c++14 -O0 -fno-asynchronous-unwind-tables -fno-exceptions -fno-rtti -fverbose-asm
# CFLAGS := -static -Wall -ansi -std=c++14 -O0 -fno-asynchronous-unwind-tables -fno-exceptions -fno-rtti -fverbose-asm
SRCS := getop.cpp stack.cpp util.cpp main.cpp
OBJS := $(SRCS:.cpp=.o)
EXECUTABLE := main.out

.PHONY: all clean

# Default target
all: $(EXECUTABLE) asm objdump

# Build the executable
$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Generate assembly code
asm: $(SRCS)
	$(CC) $(CFLAGS) -S $^

# Generate objdump output (if with -static option, the objdump will warn you that main.out file is not a dynamic object)
objdump: $(EXECUTABLE)
	$(OBJDUMP) -d -C -S -t -T $< > $(EXECUTABLE).objdump

# Rule for compiling source files to object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the generated files
clean:
	rm -f $(OBJS) $(EXECUTABLE) $(EXECUTABLE).objdump $(SRCS:.cpp=.s)