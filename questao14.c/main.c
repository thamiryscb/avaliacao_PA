#include <stdio.h>
#include <stdlib.h>

int f(int a, int *pb, int **ppc) {
    int b, c;
    **ppc += 1; //ppc vai ter o valor de c, pois quando a função main chama a função f ppc recebe a  que é o valor de c, como era 5 passa a ser 6
    c = **ppc; //c recebe o valor de ppc, que é 6
    *pb += 2; //pb tem o valor de c, que vou passado na função main, de 6(pois já foi modificado anteriormente) passa a ser 8
    b = *pb;// b recebe o valor de pb que é 8
    a += 3; //a recebe o valor 5 da função main, de 5 passa a ser 8
    return a + b + c; //(8+8+6) = 22
}
int main()
{
    int c, *b, **a;
    c = 5;
    b = &c;//recebe o endereço de c
    a = &b;//recebe o endereço de b
    printf("%d\n", f(c, b, a));
    getchar();//// Espera o usuário digitar algo
}
