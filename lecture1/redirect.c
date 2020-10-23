
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>


void main(){
	int fd = creat("output.txt", S_IRUSR | S_IWUSR);
	char *buffer = "Hello, world!\n";
	dup2(fd,1);
	close(fd);
	write(1,buffer,strlen(buffer));
}


