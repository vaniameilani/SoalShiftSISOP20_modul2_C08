#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
#include <wait.h>

int cekbintang (char a[]){
  if (a[0]=='*') {
    return 1;
  }
  return 0;
}

int cekangka (char a[]){
  for (int x = 0; x < strlen(a); x++){
    if (a[x] < '0' || a[x] > '9'){
      return 0;
    }
  }
  return 1;
}

int main (int argc, char **argv){
  if (argc == 5){
    int argumen[4];
    for (int x = 1; x < 4; x++){
      if (cekangka(argv[x])){
        argumen[x]=atoi(argv[x]);
        if (argumen[x] < 0) printf("Input ke %d tidak valid\n", x);
      }
      else if (cekbintang(argv[x])) argumen[x] = -1;
    
    else{
      printf("Input ke %d tidak valid\n", x);
      exit(EXIT_FAILURE);
    }
  }
  if (argumen[1] > 59 && argumen [2] > 59 && argumen [3] >23){
    printf("Input out of range\n");
    exit(EXIT_FAILURE);
  }

  pid_t pid, sid;        // Variabel untuk menyimpan PID

  pid = fork();     // Menyimpan PID dari Child Process

  /* Keluar saat fork gagal
  * (nilai variabel pid < 0) */
  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  /* Keluar saat fork berhasil
  * (nilai variabel pid adalah PID dari child process) */
  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();
  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);
  
  while(1){
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    if ((tm->tm_sec==argumen[1] || argumen[1]==-1) && (tm->tm_min==argumen[2] || argumen[2]==-1) && (tm->tm_hour==argumen[3] || argumen[3]==-1)){
      pid_t child_id;
      child_id = fork();

      int status;

      if (child_id == 0){
        char *argexe[]={"bash", argv[4], NULL};
        execv("/bin/bash", argexe);
      }
    }
    sleep(1);
  }
}
  else{
  printf("Argumen tidak valid\n");
  exit(EXIT_FAILURE);
  }
}
