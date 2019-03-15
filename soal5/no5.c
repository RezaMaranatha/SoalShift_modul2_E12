#include <sys/types.h>
#include <time.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <sys/wait.h>

int main() {
  pid_t pid, sid;

  pid = fork();

  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();

  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/home/reza/log")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while(1) {
  	pid_t id1;
	char filename[20];
	char menit[60];
	char c;
	int status;
	time_t now = time(NULL);
	strftime(filename, 20, "%d:%m:%Y-%H:%M", localtime(&now));
	mkdir(filename,S_IRWXU | S_IRWXG | S_IRWXO);
    	FILE *getsyslog;
    	char syslog[100];
	strcpy(syslog,"/var/log/syslog");
        int i=0;
    	while(i<30){
	  if(i==0){
	    i++;
	    sleep(60);
	    //break;
	  }
      	  else{
	    getsyslog = fopen(syslog,"r");

            sprintf(menit,"%s/log%d.log",filename,i);
            FILE *FileLog;
            FileLog = fopen(menit,"w");

            c = fgetc(getsyslog);
            while (c != EOF){
              fputc(c, FileLog);
              c = fgetc(getsyslog);
            }

            fclose(getsyslog);
            fclose(FileLog);
            sleep(60);
            i++;
    	  }
        }
  } 
  exit(EXIT_SUCCESS);
}
