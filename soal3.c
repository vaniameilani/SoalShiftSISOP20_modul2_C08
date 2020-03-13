#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <time.h>
#include <string.h>

int main(){
  pid_t child, child1, child2, child3, child4, child5, child6;
  int status;

  child = fork();
  if (child == 0) {
    char *argv[] = {"mkdir","-p","/home/vaniameith/modul2/indomie",NULL};
    execv("/bin/mkdir", argv);
  }

  while((waitpid(child,&status,0))>0);
  child1 = fork();
  if (child1 == 0) {
    sleep(5);
    char *argv[] = {"mkdir","-p","/home/vaniameith/modul2/sedaap",NULL};
    execv("/bin/mkdir", argv);
  }

  while((waitpid(child1,&status,0))>0);
  child2 = fork();
  if (child2 == 0) { 
    char *argv[] = {"unzip","/home/vaniameith/modul2/jpg.zip","-d","/home/vaniameith/modul2",NULL};
    execv("/usr/bin/unzip", argv);
  }
  while((waitpid(child2,&status,0))>0);
  child3 = fork();
  if (child3 == 0){
    char *argv[] = {"find","/home/vaniameith/modul2/jpg",
                    "-mindepth","1","-type","f","-exec","mv",
                    "{}","/home/vaniameith/modul2/sedaap",
                    ";",NULL};
    execv("/usr/bin/find", argv);
  }

  while((waitpid(child3,&status,0))>0);
  child4 = fork();
  if (child4 == 0){
    char *argv[] = {"find","/home/vaniameith/modul2/jpg",
                    "-mindepth","1","-type","d","-exec","mv",
                    "{}","/home/vaniameith/modul2/indomie",
                    ";",NULL};
    execv("/usr/bin/find", argv);
  }

  while((waitpid(child4,&status,0))>0);
  child5 = fork();
  if (child5 == 0){
    char *argv[] = {"find","/home/vaniameith/modul2/indomie","-mindepth","1","-type","d","-exec","touch","{}/coba1.txt","'\'",";",NULL};
    execv("/usr/bin/find", argv);
  }

  while((waitpid(child5,&status,0))>0);
  child6 = fork();
  if (child6 == 0) {
    sleep(3);
    char *argv[] = {"find","/home/vaniameith/modul2/indomie","-mindepth","1","-type","d","-exec","touch","{}/coba2.txt","'\'",";",NULL};
    execv("/usr/bin/find", argv);
  }  

}

