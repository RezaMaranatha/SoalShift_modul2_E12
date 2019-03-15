#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <syslog.h>

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

  if ((chdir("/home/idputuwiprah")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  int i = 1;
  
  while(1)
  {

	struct stat stt;
	stat("/home/idputuwiprah/Documents/makanan/makan_enak.txt", &stt);
	
	struct tm mod = *localtime(&(stt.st_atime));

	time_t rawtime = time(NULL);
	struct tm times = *localtime(&rawtime);
	
	double seconds = difftime( mktime(&times), mktime(&mod)); 
	printf ("%.f\n", seconds);

	if(seconds <= 30)
	{
		char dir[50];
		char trans[12];
		
		memset(dir,0,sizeof(dir));
		memset(trans,0,sizeof(trans));

		strcpy(dir,"/home/idputuwiprah/Documents/makanan/makan_sehat");
		sprintf(trans, "%d", i);	
		strcpy(dir+strlen(dir),trans);
		strcpy(dir+strlen(dir),".txt");

		int fd;
		mode_t perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

		fd = creat(dir,perm);
		i = i+1;
		printf("%d\n", i);
	}

	sleep(5);
  }

  exit(EXIT_SUCCESS);
}
