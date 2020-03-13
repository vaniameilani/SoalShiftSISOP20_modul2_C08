#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <time.h>
#include <string.h>
#define SIZE 1000

int main() {
  pid_t child;
  int status;
  time_t rawtime;
  struct tm *timeinfo;
  char file[SIZE];
  char lalaland[SIZE];
  char place[SIZE];

  rawtime = time(NULL);
  timeinfo = localtime ( &rawtime ); 
  strcpy (file, "/home/vaniameith/khususoal2/");
  strftime (lalaland, SIZE, "%Y-%m-%d_%H:%M:%S", timeinfo);
  strcat (file, lalaland);

    child = fork();
   if (child == 0) {
     sleep(30);
     char *argv[] = {"mkdir","-p",file,NULL};
     execv("/bin/mkdir", argv);
   } 
}

