#include <stdio.h>
#include <stdlib.h>

int f(int a, int *pb, int **ppc) {
    int b, c;
    **ppc += 1; //ppc vai ter o valor de c, pois quando a fun��o main chama a fun��o f ppc recebe a  que � o valor de c, como era 5 passa a ser 6
    c = **ppc; //c recebe o valor de ppc, que � 6
    *pb += 2; //pb tem o valor de c, que vou passado na fun��o main, de 6(pois j� foi modificado anteriormente) passa a ser 8
    b = *pb;// b recebe o valor de pb que � 8
    a += 3; //a recebe o valor 5 da fun��o main, de 5 passa a ser 8
    return a + b + c; //(8+8+6) = 22
}
int main()
{
    int c, *b, **a;
    c = 5;
    b = &c;//recebe o endere�o de c
    a = &b;//recebe o endere�o de b
    printf("%d\n", f(c, b, a));
    getchar();//// Espera o usu�rio digitar algo
}
