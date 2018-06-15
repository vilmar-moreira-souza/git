// author:vilmar moreira de souza
#include "stdio.h"

int main(void) {
   typedef struct char_vector{
      char *c_parte_real[2], *c_parte_imag[2];
   }c_vector;
char  a,b;
c_vector x;
x.c_parte_real[0]='2';
a = x.c_parte_real[0];

x.c_parte_real[1]='3';
b = x.c_parte_real[1];

printf("a=%c\n",a);
printf("b=%c\n",b);

return 0;
}
