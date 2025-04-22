#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mat[4], *p, x;
    p = mat + 1; // válida, oir mat ser um vetor o +1 irá para a próxima posição
    //p = mat++; //não é válida pois mat é um vetor, aqui ele ta incrementando que não pode ser feita num vetor com endereço fixo.
    //p = ++mat; //não é válida pois mat é um vetor, aqui ele ta incrementando que não pode ser feita num vetor com endereço fixo.
    x = (*mat); //válido, vai ser o conteúdo do primeiro elemento
    return 0;
}
