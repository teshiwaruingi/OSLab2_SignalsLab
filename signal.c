/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// a global variable to track whether the signal has been received
int flag = 0;

// the signal handler function
void handler(int signum)
{
  printf("Hello World!\n");
  flag = 1;
}

int main(int argc, char * argv[])
{
  // register the signal handler
  signal(SIGALRM, handler);

  // busy wait until the signal is received
  while (flag == 0) {
    alarm(1);
    while (flag == 0) {
      // do nothing
    }

    // print a message and reset the flag
    printf("Turing was right!\n");
    flag = 0;
  }

  return 0;
}
