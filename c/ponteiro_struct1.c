// author:vilmar moreira de souza
#include <stdio.h>
#include <stdlib.h>
int main(){
int x=10;
double y=20.50;
char z ='a';
int *px=&x;
double  *py=&y;
char  *pz=&z;
double soma =*px+*py;//px*=valor//px=endereço
int *resultado;
resultado=&x;
printf("valor =%.2f\n",soma);
printf("valor =%c\n",*pz);
printf("valor =%i\n",*resultado);
return 0;
}
