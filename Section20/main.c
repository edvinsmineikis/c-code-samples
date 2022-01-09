#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int score = 0;

void end_game() {
   printf("\nFinal score: %d\n", score);
   exit(0); 
}

void error(char *msg)
{
   fprintf(stderr, "%s: %s\n", msg, strerror(errno));
   exit(1);
}

void alarm_handler() {
   printf("\nTimes up!\n");
   end_game();
}

void interrupt_handler() {
   printf("\nBye bye!\n");
   end_game();
}

int main() {

   srand (time(0));
   
   while(1) {
      int a = rand() % 11;
      int b = rand() % 11;

      char txt[4];

      signal(SIGINT, interrupt_handler);
      signal(SIGALRM, alarm_handler);
      alarm(5);

      printf("\nWhat is %d times %d: ", a, b);
      fgets(txt, 4, stdin);

      int answer = atoi(txt);

      if(answer == a * b) {
         score++;
         printf("\nRight! Score: %d\n", score);
      } else {
         printf("\nWrong! Score: %d\n", score);
      }
   }

    return 0;
} 
