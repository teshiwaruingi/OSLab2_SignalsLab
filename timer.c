/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

int flag = 0;
time_t seconds;
int alarms = 0;

void alarmSignalHandler(int signum)
{ //signal handler
  flag = 1;
}

void exitSignalHandler(int sigint) {
  printf("Your Program excecuted %d alarms in %ld seconds \n",alarms, (time(NULL)-seconds));
  exit(1);
}

int main(int argc, char * argv[]) {
  seconds = time(NULL);
  printf("Your program is running...\n");
  signal(SIGALRM, alarmSignalHandler);
  signal(SIGINT, exitSignalHandler);
  while (1) {
     alarm(1);
     while(flag == 0){}; 
     alarms += 1;
     flag = 0;
  }
  return 0;
}

