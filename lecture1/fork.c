#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>

void main(){
	int child_pid;
	
	if((child_pid = fork()) == 0 ){
		//child
		execl("/bin/ls","ls",(char *) 0);
		//Except in case of an error in excel, it won't return 
	} else {
		//parent
		//twiddle thumbs
		int status;
		wait(&status);
	}	
}
