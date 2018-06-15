// author:vilmar moreira de souza

#include <stdio.h>
#include <stdlib.h>

#define A 2
#define B 6

void linha(){//imprime linha
	printf("_____________________________________________\n");
}
float soma(int a,int b){//soma a e b
	int c;
	c=a+b;
		printf("total=%d\n",c);
		return c;
}
void chama(){ //chama  funçao linha() e soma()
	linha();
	printf("fim\n");
	soma(A,B);
}

int main(){
	printf("\n\nola\n");
	int a=2,b=5;
	linha();
	soma(a,b);
	chama();

	system("pause");
	return 0;
}
