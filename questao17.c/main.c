#include <stdio.h>
#include <stdlib.h>

int main()
{
    //memorie leak � quando ocorre um vazamento de mem�ria, eu aloco uma parte da mem�ria e n�o a libero depois
    int *p, tamanho;
    tamanho = 3;

    p = malloc(tamanho * sizeof(int));

    for(int i=0; i<tamanho; i++){
        p[i]=rand()%100;
    }
    for(int i=0; i<tamanho; i++){
        printf("%d ", p[i]);
    }

    //free(p); essa � a solu��o para o vazamento de mem�ria
    return 0;
}
