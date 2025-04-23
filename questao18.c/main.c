#include <stdio.h>
#include <stdlib.h>

//um ponteiro para função vai armazenar o endereço dessa função, e isso é possível porque as funções possuem endereços fixos.

int multiplicacao(int x, int y){
    return x*y;
    //função que multiplica duas variáveis inteiras
}
int main()
{
    int (*p)(int, int);//foi criado um ponteiro para uma função que recebe dois int e retorna int

    p = multiplicacao; //guarda o endereço da função dentro do ponteiro

    printf("%d", p(2,3));//a função é chamada a partir do ponteiro e exibido o resultado da função chamada
    return 0;
}
