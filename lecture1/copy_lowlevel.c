#include<unistd.h>

void main(){
	char buffer[256];

	int nread = read(0,buffer,sizeof(buffer));
	write(1,buffer,nread);
}
