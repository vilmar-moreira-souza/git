//vilmar
//03/11/2016
//calculo de fatorial de inteiro


#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
int fatorial,a,rfatorial=1;
printf("hello  world\n");
printf("digite um numero\n");
scanf("%d",&fatorial);//nao funciona para float 2,5
a=fatorial;
 for (; fatorial>=1; --fatorial)
 {
	rfatorial=rfatorial*fatorial;
 }
printf("fatorial de %i=%i\n",a,rfatorial );
		return 0;
}
