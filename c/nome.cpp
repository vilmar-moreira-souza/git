//vilmar moreira 03/11/2016
//recebe nome
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int nome1(){//erro
	int nome;
	do{
		printf("\ndigite nome\n\n");
		char a[30];
		fgets(a,30,stdin);
		fflush(stdin);
		nome=atoi(a);
		if(nome<'a'&& nome>'Z');	printf("nome nao aceito\n");
}while(nome>'a'&& nome<'Z');return nome;

}//erro


int main(int argc, char const *argv[])
{  int nomes;
	char nome[30];
	printf("\n\nhello word!!!\n\n");
	printf("digite nome\n");
	scanf("%[^\n]",nome);//le com espaço e tudo
	//	scanf("%s",nome);//le ate o espaço
		printf("ola %s\n",nome);

		char nome2[40];
		   printf("Nome do aluno 2 ......: ");
             fflush(stdin);
             fgets(nome2, 40, stdin);
             printf("Nome ...........: %s", nome2);


   nome1();//erro


	return 0;
}
