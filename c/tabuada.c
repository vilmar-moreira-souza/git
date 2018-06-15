//tabuada de um nro dado pelo usuario
//08//11/2019
//autor: vilmar

#include<stdio.h>
#include<stdlib.h>

void tabuada(){ int i;
   int total=1,nro2;
   char nro[5];
   printf("digite nro <=99999 pra ser calculada tabuada\n");
   fgets(nro,5,stdin);
   fflush(stdin);
   nro2=atoi(nro);
   	for(i=0;i<=10;i++){
        total=nro2*i;
        printf("%dx%d=%d\n",nro2,i,total);
	}

}
int main(int argc, char const *argv[])
{
    tabuada();

	return 0;
}

