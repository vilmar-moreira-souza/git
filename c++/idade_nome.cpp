//vilmar 2017
//nome e idade da pessoa 
#include<iostream>

#include "stdlib.h"
using namespace std;
 int  main(int argc, char const *argv[]) {


char nome[20];
int idade;
cout<< "hello\nqual seu primeiro nome" << endl;
cin >> nome;
cout<< "qual sua idade" << endl;
cin >> idade;
cout<< "bem vindo " ;
cout<<nome<<endl;
if(idade<=18){
cout << "voce é um adolescente" << '\n';
}
else if(idade>18){
cout << "voce ja e adulto" << '\n';
}

   return 0;
 }
