#include<stdio.h>
void main(){
	char buffer[1024];
	
	fgets(buffer,sizeof(buffer),stdin);
	fputs(buffer,stdout);
}

