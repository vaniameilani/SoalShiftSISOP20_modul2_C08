#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <time.h>
#include <string.h>
#define SIZE 1000

int main() {
  pid_t pid, sid;
  int stat;

  pid = fork();
  if (pid < 0){
    exit(EXIT_FAILURE);
  }

  if (pid > 0){
    exit(EXIT_SUCCESS);
  }

  umask (0);
  sid = setsid();
  if (sid < 0){
    exit (EXIT_FAILURE);
  }

  if ((chdir("/"))<0){
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while(1){
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
    else {
      while((wait(&stat))>0);
      strcpy(link, "https://picsum.photos/");
    }
  } 
}

