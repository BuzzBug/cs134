#include<sys/wait.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

void main(){
	int child_pid;
	int pipe_fds[2];

	int err = pipe(pipe_fds);
	if(err != 0){
		perror("pipe");
	}
	if((child_pid = fork())==0 ){
		//left child
		close(1);
		//close(pipe_fds[0]);
		dup2(pipe_fds[1],1);
		close(pipe_fds[1]);
		execl("/bin/ls","ls",(char*) 0);
	} else{
		if((child_pid = fork())== 0 ){
			//right child
			close(0);
			close(pipe_fds[1]);
			dup2(pipe_fds[0],0);
			close(pipe_fds[0]);
			execl("/bin/wc","wc","-l",(char *) 0);
		}
		//parent
		int status;

		close(pipe_fds[0]);
		close(pipe_fds[1]);
		wait(&status);
		wait(&status);
	}
}

		
