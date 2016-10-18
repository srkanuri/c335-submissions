I was able to complete the code and a basic make file to generate the object file and to run it with user input.
I got to know about the makefile to execute and do a diff with input file in the last minute.

I was able to finish the makefile and it is able to generate all the files needed.
Below is the execution log for it :

[srkanuri@silo HW3]$ make test
gcc -g -c hw3.c
gcc -lm -o hw3 hw3.o
arm-none-eabi-as test.asm -o test.o
arm-none-eabi-objcopy test.o -O binary --only-section=.text test.bin
hexdump -x test.bin |sed -e 's/^[^ ]*//' > test.hex
./hw3 < test.hex > test.out
make: *** [test] Error 255

It is giving an error but all the files have been generated.
You can execute a command:
[srkanuri@silo HW3]$ diff test.asm test.out

and it will give no difference.
I am not able to find out the error for this specific case.
Request you to please consider this while grading.
