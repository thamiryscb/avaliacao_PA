#include <stdio.h>
#include <stdlib.h>

int main()
{
    //memorie leak é quando ocorre um vazamento de memória, eu aloco uma parte da memória e não a libero depois
    int *p, tamanho;
    tamanho = 3;

    p = malloc(tamanho * sizeof(int));

    for(int i=0; i<tamanho; i++){
        p[i]=rand()%100;
    }
    for(int i=0; i<tamanho; i++){
        printf("%d ", p[i]);
    }

    //free(p); essa é a solução para o vazamento de memória
    return 0;
}
