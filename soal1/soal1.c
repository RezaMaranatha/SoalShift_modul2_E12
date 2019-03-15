#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

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
	DIR *dir;
	dir = opendir("/home/idputuwiprah/modul2/fotografi");		

	struct dirent *sd;

	if(dir == NULL)
	{
		printf("ERROR BRO!\n");
		exit(1);
	}

	while( (sd = readdir(dir)) != NULL )
	{
		int len=0, ret=0, len_temp=0;
		char temp[50];
		char format[5];
		char format_check[5];
		memset(temp,0,sizeof(temp));
		memset(format,0,sizeof(format));

		strcpy(temp, sd->d_name);
		len = strlen(temp);

		len_temp = len-4;
		memcpy(format, temp+len_temp, 4);
		strcpy(format_check,".png");
		
		if(len > 2 && (strcmp(format,format_check) == 0))
		{
			char temp2[50];
			memset(temp2,0,sizeof(temp2));
			strncpy(temp2, temp, len-4);
			strcpy(temp2+strlen(temp2),"_gray.png");
			
			char oldname[260]; 
			memset(oldname,0,sizeof(oldname));
			strcpy(oldname,"/home/idputuwiprah/modul2/fotografi/");
			strcpy(oldname+strlen(oldname),temp);			
			//printf("oldname: %s\n", oldname);


			char newname[260]; 
			memset(newname,0,sizeof(newname));
			strcpy(newname,"/home/idputuwiprah/modul2/gambar/");
			strcpy(newname+strlen(newname),temp2);			
			//printf("newname: %s\n", newname);
			
			ret = rename(oldname, newname);
		}
	}

	closedir(dir);
	
	sleep(3);
  }

  exit(EXIT_SUCCESS);
}

