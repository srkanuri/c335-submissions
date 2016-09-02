#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
  while(1)
  {
    system("echo Hello World");
    sleep(3);
    system("gcc -o whello wicked_hello.c");
    system("./whello");
    wait(0);
  }
  return 0;
}
