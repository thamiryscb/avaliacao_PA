#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int x[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    printf("%u, %u, %u", x+3, *(x+3), *(x+2)+3);
    //%u pr�prio para unsigned int
    //x+3 = x[3][0] vai retornar o endere�o de da 4� linha
    //*(x+3) vai retornar o conte�do de x[3][0], ou seja o mesmo endere�o do anterior
    //*(x+2)+3, *(x+2) vai retornar o conte�do da terceira linha, o +3 deveria acessar x[2][3] como n�o existe ele vai somar mais 12 bytes no endere�o da terceira linha, pois um int ocupa 4. ficara o mesmo endere�o dos anteriores.

}
