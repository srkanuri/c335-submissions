CC = gcc
CFLAGS = -g
LDFLAGS = -lm
test: test.asm hw3 test.hex
	./hw3 < test.hex > test.out
	diff test.asm test.out
test.hex: 
	arm-none-eabi-as test.asm -o test.o
	arm-none-eabi-objcopy test.o -O binary --only-section=.text test.bin
	hexdump -x test.bin |sed -e 's/^[^ ]*//' > test.hex
hw3: hw3.o
	$(CC) $(LDFLAGS) -o hw3 hw3.o

hw3.o: hw3.c
	$(CC) $(CFLAGS) -c hw3.c
clean:
	rm hw3.o hw3 test.hex test.bin test.o test.out
