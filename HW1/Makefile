#################################################################
# Makefile for the HW1
# 
# Author: Srikanth Kanuri (srkanuri)
# Date Created: 09/14/2016
# Last Modified by: Srikanth Kanuri
# Date Last Modified: 09/14/2016
# Assignment: HW1
##################################################################
CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
CPU = -mcpu=cortex-m0 -mthumb
ELF = --specs=rdimon.specs -lc -lrdimon
CFLAGS = -g
LDFLAGS =
test : HW1.elf
	qemu-system-arm  -machine versatilepb -cpu cortex-m3 -nographic -monitor null -serial null -semihosting -kernel HW1.elf
HW1.elf: test.o t1.o
	$(CC) -g $(CPU) $(ELF) test.o t1.o -o HW1.elf
t1.0: t1.s
	$(AS) $(CFLAGS) $(CPU) t1.s -o t1.o
test.o: test.c
	$(CC) $(CFLAGS) -O1 $(CPU) -c test.c
clean:
	rm test.o t1.o
