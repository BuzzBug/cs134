#include<sys/wait.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

void main(){
	int child_pid;
	if((child_pid = fork())==0){
		//child
		close(1);
		creat("output.txt",0600);
		execl("/bin/ls","ls",(char*) 0);
		//Except in case of an error in execl, it won't return 
	} else{
		//parent
		//twiddle thumbs
		int status;
		wait(&status);
	}
}
