#include <stdio.h>
#define TAM 10

//Alternativa correta apenas I, ou seja alternativa "a"
//A funcao1 realiza uma busca linear e irá encontrar o numero 15 no indice 7, a funcao2 realiza uma busca binária, funcionando com divisões para reduzir o intervalo pela metade;
//funcao2(vetor, 15, 0, TAM-1) também encontrará 15 no indice 7, saindo 7 - 7.

//A funcao1, o elemento alvo é o ultimo elemento ou que não está contido na matriz, pois examina todo o array na sua busca. enquanto na funcao2 reduz o espaço de busca pela metade, sendo mais rápida.

//A funcao2 utiliza o recuso de chamar a si mesma, ou seja é uma função recursiva, não de iteração, pois uma abordagem de iteração usaria laços como for ou wuile.


int funcao1(int vetor[], int v){
    int i;
    for (i = 0; i < TAM; i++){
        if (vetor[i] == v)
            return i;
    }
    return -1;
}
int funcao2(int vetor[], int v, int i, int f){
    int m = (i + f) / 2;
    if (v == vetor[m])
        return m;
    if (i >= f)
        return -1;
    if (v > vetor[m])
        return funcao2(vetor, v, m+1, f);
    else
        return funcao2(vetor, v, i, m-1);
}
int main(){
    int vetor[TAM] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    printf("%d - %d", funcao1(vetor, 15), funcao2(vetor, 15, 0, TAM-1));
    return 0;
}
