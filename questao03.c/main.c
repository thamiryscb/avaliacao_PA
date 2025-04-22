#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=3,j=5;
    int *p, *q;
    p = &i;
    *q = &j; // não tem como atribuir a um ponteiro o endereço de j;
    p = &*&i;
    i = (*&)j; //erro de Sintaxe, devido ao uso dos parênteses não tem como pegar o endereço e guardar seu valor se não possui uma variável.
    i = *&j;
    i = *&*&j;//semelhante ao anterior da erro de Sintaxe, porque não tem como pegar o endereço do valor se não possui uma variável.
    q = *p;
    i = (*p)++ + *q;
    return 0;
}
