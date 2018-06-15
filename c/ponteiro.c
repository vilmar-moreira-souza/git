// author:vilmar moreira de souza
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	int *ponteiro,x=10;
	ponteiro=&x;
	printf("valor=%d\n",x );
	printf("local=%d\n",&x );
	printf("ponteirolocal=%d\n",ponteiro );
	printf("ponteirovalor=%d\n",*ponteiro );

	return 0;
}
