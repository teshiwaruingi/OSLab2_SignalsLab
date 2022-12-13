/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int flag = 0;
void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  flag = 1;
//   exit(1); //exit after printing
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  while (flag == 0) {
     alarm(1); 
     while(flag == 0) {
  }; //busy wait for signal to be delivered
    printf("Turing was right!\n");
    flag = 0;
  }
  return 0; //never reached
}