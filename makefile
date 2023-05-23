CC := g++
# CC = riscv32-unknown-elf-g++
# CC = riscv32-unknown-linux-gnu-g++
CFLAGS := -g -Wall -ansi -std=c++14 -O0
SRCS := const.h getop.cpp getop.h stack.h stack.cpp util.cpp util.h main.cpp
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

# Generate objdump output
objdump: $(EXECUTABLE)
	objdump -d $< > $(EXECUTABLE).objdump

# Rule for compiling source files to object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the generated files
clean:
	rm -f $(OBJS) $(EXECUTABLE) $(EXECUTABLE).objdump