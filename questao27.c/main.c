#include <stdio.h>
#define TAM 10

//Alternativa correta apenas I, ou seja alternativa "a"
//A funcao1 realiza uma busca linear e ir� encontrar o numero 15 no indice 7, a funcao2 realiza uma busca bin�ria, funcionando com divis�es para reduzir o intervalo pela metade;
//funcao2(vetor, 15, 0, TAM-1) tamb�m encontrar� 15 no indice 7, saindo 7 - 7.

//A funcao1, o elemento alvo � o ultimo elemento ou que n�o est� contido na matriz, pois examina todo o array na sua busca. enquanto na funcao2 reduz o espa�o de busca pela metade, sendo mais r�pida.

//A funcao2 utiliza o recuso de chamar a si mesma, ou seja � uma fun��o recursiva, n�o de itera��o, pois uma abordagem de itera��o usaria la�os como for ou wuile.


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
