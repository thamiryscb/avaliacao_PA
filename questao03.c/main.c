#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=3,j=5;
    int *p, *q;
    p = &i;
    *q = &j; // n�o tem como atribuir a um ponteiro o endere�o de j;
    p = &*&i;
    i = (*&)j; //erro de Sintaxe, devido ao uso dos par�nteses n�o tem como pegar o endere�o e guardar seu valor se n�o possui uma vari�vel.
    i = *&j;
    i = *&*&j;//semelhante ao anterior da erro de Sintaxe, porque n�o tem como pegar o endere�o do valor se n�o possui uma vari�vel.
    q = *p;
    i = (*p)++ + *q;
    return 0;
}
