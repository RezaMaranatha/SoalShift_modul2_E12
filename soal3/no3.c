#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int p[2];


int main(){
    pid_t pid;
    pid_t pid2;
    pid_t pid3;
    int status;
    int status2;
    char *ls[] = {"ls","/home/reza/campur2", NULL};
    char *grep[] = {"grep", "[.]txt$", NULL};
    char *touch[] = {"touch","daftar.txt",NULL};
    char *unzip[] = {"unzip","/home/reza/campur2.zip","-d","/home/reza",NULL};
    pipe(p);
    pid = fork();
    if(pid == 0){
	//printf("LLL\n");
	execvp("unzip",unzip);
	//execvp("touch",touch);
		//execvp("unzip",unzip);
		//execvp("touch",touch);
		//while ((wait(&status)) > 0);
		//execvp("touch",touch);
		//execvp("unzip",unzip);	
		/*dup2(p[1], 1);
                close(p[0]);
                execvp("ls", ls);*/
    }
    else{
	    while ((wait(&status2)) > 0);
	    pid2 = fork();
	     if(pid2 == 0){
	     	//printf("ASU\n");
		dup2(p[1], 1);
                close(p[0]);
                execvp("ls", ls);
		//execvp("touch",touch);
	     }
	     else{
	        pid3 = fork();
		if(pid3 == 0){
		   execvp("touch",touch);
	//	   printf("hello\n");
		}
		else{
		     while ((wait(&status)) > 0);
		     int file_desc = open("daftar.txt",O_WRONLY | O_APPEND); 
                     dup2(p[0], 0);
                     close(p[1]);
                     dup2(file_desc, 1);
                     execvp("grep", grep);
                     close(p[0]);
		   //printf("HHHH\n");
		}
		
	     }
	     //printf("Hallo");
	     //execvp("touch",touch);	
	     //int file_desc = open("daftar.txt",O_WRONLY | O_APPEND); 
             //dup2(p[0], 0);
             //close(p[1]);
             //dup2(file_desc, 0);
             //execvp("grep", grep);
             //close(p[0]);
    } 
}
