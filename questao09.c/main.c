#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mat[4], *p, x;
    p = mat + 1; // v�lida, oir mat ser um vetor o +1 ir� para a pr�xima posi��o
    //p = mat++; //n�o � v�lida pois mat � um vetor, aqui ele ta incrementando que n�o pode ser feita num vetor com endere�o fixo.
    //p = ++mat; //n�o � v�lida pois mat � um vetor, aqui ele ta incrementando que n�o pode ser feita num vetor com endere�o fixo.
    x = (*mat); //v�lido, vai ser o conte�do do primeiro elemento
    return 0;
}
