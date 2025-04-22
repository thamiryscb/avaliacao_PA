#include <stdio.h>
#include <stdlib.h>

void main()
{
    int const *x = 3;
    printf("%d", ++(*x));
}
//a saída é:ERROR, primeiro da um warm no ponteiro pois ele ta tentando apontar para um endereço como esse: 0x00000003, além disso mesmo
//se tivesse apontando para um endereço válido no pintf está tentando fazer um incremento desse endereço, e como o c é um ponteiro para constante esse valor não pode ser alterado.
