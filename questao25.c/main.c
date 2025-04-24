#include <stdio.h>
#include <stdlib.h>

//(A)
//n�o possui nenhum problema de vazamento de mem�ria, pois � realizado o free.
void f( ){
    void *s;
    s = malloc(50);
    free(s);
}

//(B)
//n�o possui nenhum tipo de vazamento de mem�ria, at� porque n�o � nem realizado o malloc
int f( ){
    float *a;
    return 0;
}

//(C)
//POSSUI ERRO DE VAZAMENTO DE MEM�RIA, o problema est� quando o entra dentro da condi��o (if).
//quando size>50 vai retorna -1 e n�o vai ser realizado a libera��o da mem�ria alocada antes.
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
//N�o cont�m vazamento de mem�ria, apesar de alocar mem�ria na fun��o f, no main ele libera a aloca��o feita antes atrav�s do free.
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
//posssui erro de mem�ria, ocorre um problema de double free, primeiramente ele aloca 10bytes para m e n, depois libera m, em seguida
//afirma que m aponta para o mesmo local de n, ai libera a mem�ria pontada por n, j� que m=n, em seguida tenta liberar n novamente causando double free.
//mas n�o possui problema de vazamento de mem�ria.
void f(int n){
    char *m = malloc(10);
    char *n = malloc(10);
    free(m);
    m = n;
    free(m);
    free(n);
}
