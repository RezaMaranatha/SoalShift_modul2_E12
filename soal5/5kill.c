#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
char *pkill[] = {"pkill","soal5",NULL};
execvp("pkill",pkill);
}
