#include <stdio.h>
#include <stdlib.h>

void main()
{
    int const *x = 3;
    printf("%d", ++(*x));
}
//a sa�da �:ERROR, primeiro da um warm no ponteiro pois ele ta tentando apontar para um endere�o como esse: 0x00000003, al�m disso mesmo
//se tivesse apontando para um endere�o v�lido no pintf est� tentando fazer um incremento desse endere�o, e como o c � um ponteiro para constante esse valor n�o pode ser alterado.
