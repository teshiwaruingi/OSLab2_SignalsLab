/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

// a global variable to track whether the signal has been received
int flag = 0;

// a global variable to track the number of alarms that have been received
int alarms = 0;

// a global variable to track the start time of the program
time_t seconds;

// the signal handler for the alarm
void alarmSignalHandler(int signum)
{
  flag = 1;
}

// the signal handler for the exit signal
void exitSignalHandler(int sigint)
{
  printf("Your Program excecuted %d alarms in %ld seconds \n", alarms, (time(NULL) - seconds));
  exit(1);
}

int main(int argc, char * argv[])
{
  // store the start time of the program
  seconds = time(NULL);

  printf("Your program is running...\n");

  // register the signal handlers
  signal(SIGALRM, alarmSignalHandler);
  signal(SIGINT, exitSignalHandler);

  // busy wait until the signal is received
  while (1) {
    alarm(1);
    while (flag == 0) {
      // do nothing
    }

    // increment the alarm counter and reset the flag
    alarms += 1;
    flag = 0;
  }

  return 0;
}
