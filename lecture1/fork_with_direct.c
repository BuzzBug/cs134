#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/type.h>
#include<sys/stat.h>
#include<fcntl.h>


void main(){
	int child_pid;
	
	if(child_pid = fork() == 0){
		//child
		close(1);
		creat("output.txt",0600);
		execl("/bin/ls","ls",(char*)0);
	}else{
		//parent
		//twiddle thumbs
		int status;
		wait(&status);
}

