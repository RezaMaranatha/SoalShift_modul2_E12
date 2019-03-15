#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <grp.h>
#include <pwd.h>
#include <string.h>

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

  while(1)
  {
	char mode[]="0777";
	int i, temp;
	i=strtoul(mode,NULL,8);
	temp = chmod("/home/idputuwiprah/modul2/hatiku/elen.ku",i);	

	char usrtarget[20], grptarget[20];
	gid_t gid;
	uid_t uid;

	strcpy(usrtarget,"www-data");
	strcpy(grptarget,"www-data");

	struct stat stt;
	stat("/home/idputuwiprah/modul2/hatiku/elen.ku", &stt);


	gid = stt.st_gid;
	uid = stt.st_uid;

	struct group *grp;
	grp = getgrgid(gid);

	char grpname[20];
	strcpy(grpname, grp->gr_name);

	struct passwd *usr;
	usr = getpwuid(uid);

	char usrname[20];
	strcpy(usrname, usr->pw_name);

	if( (strcmp(usrname,usrtarget) == 0) && (strcmp(grpname,grptarget) == 0) )
	{
		int status;
		status = remove("/home/idputuwiprah/modul2/hatiku/elen.ku");
	}
	
	sleep(3);
  }

  exit(EXIT_SUCCESS);
}
