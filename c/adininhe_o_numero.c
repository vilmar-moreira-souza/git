//vilmar moreira de souza 2016
//adivinhe o numero de 1 a 100
#include <stdio.h>
#include <stdlib.h>
#include <time.h>//biblioteca para rand()
#define true 1

int main(){
printf("hello world\n");


int resp ,num;
 //Para fazer com que um número ‘resp’ receba um valor entre 0 e 9, fazemos:
srand( (unsigned)time(NULL) );//faz a funçao rand() nao repetir o numero/nao ficar num loop
resp=rand()%100;

while(true){
printf("digite numenro\n");
scanf("%d",&num);
if(num>resp){
	printf("mais pra baixo\n");
}
if(num<resp){
	printf("mais pra cima\n");
}
else
if(num==resp){
	printf("acertou!!\n");
	break;
}



}

return 0;
}
