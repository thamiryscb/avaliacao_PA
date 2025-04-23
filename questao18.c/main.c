#include <stdio.h>
#include <stdlib.h>

//um ponteiro para fun��o vai armazenar o endere�o dessa fun��o, e isso � poss�vel porque as fun��es possuem endere�os fixos.

int multiplicacao(int x, int y){
    return x*y;
    //fun��o que multiplica duas vari�veis inteiras
}
int main()
{
    int (*p)(int, int);//foi criado um ponteiro para uma fun��o que recebe dois int e retorna int

    p = multiplicacao; //guarda o endere�o da fun��o dentro do ponteiro

    printf("%d", p(2,3));//a fun��o � chamada a partir do ponteiro e exibido o resultado da fun��o chamada
    return 0;
}
