#include <stdio.h>
#include <stdlib.h>

//(A)
//não possui nenhum problema de vazamento de memória, pois é realizado o free.
void f( ){
    void *s;
    s = malloc(50);
    free(s);
}

//(B)
//não possui nenhum tipo de vazamento de memória, até porque não é nem realizado o malloc
int f( ){
    float *a;
    return 0;
}

//(C)
//POSSUI ERRO DE VAZAMENTO DE MEMÓRIA, o problema está quando o entra dentro da condição (if).
//quando size>50 vai retorna -1 e não vai ser realizado a liberação da memória alocada antes.
int f(char *data){
    void *s;
    s = malloc(50);
    int size = strlen(data);
    if (size > 50)
        return(-1);
    free(s);
    return 0;
}

//(D)
//Não contém vazamento de memória, apesar de alocar memória na função f, no main ele libera a alocação feita antes através do free.
int *f(int n){
    int *num = malloc(sizeof(int)*n);
    return num;
}
int main(void){
    int *num;
    num = f(10);
    free(num);
    return 0;
}

//(E)
//posssui erro de memória, ocorre um problema de double free, primeiramente ele aloca 10bytes para m e n, depois libera m, em seguida
//afirma que m aponta para o mesmo local de n, ai libera a memória pontada por n, já que m=n, em seguida tenta liberar n novamente causando double free.
//mas não possui problema de vazamento de memória.
void f(int n){
    char *m = malloc(10);
    char *n = malloc(10);
    free(m);
    m = n;
    free(m);
    free(n);
}
