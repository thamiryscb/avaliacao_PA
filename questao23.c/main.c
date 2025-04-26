#include <stdio.h>
#include <stdlib.h>

void soma_v(int *vet1, int *vet2, int *resultado, int n){
    for(int i=0; i<n; i++){
        //vai pegar cada elemento dos vetores na posi��o i, e ir� somar e registrar esse valor no vator resultado.
        resultado[i] = vet1[i]+vet2[i];
    }
}
int main()
{
    int n;
    scanf("%d", &n);//L� um inteiro e armazena na vari�vel 'n'

    int *v1 = malloc(n * sizeof(int));//aloca mem�ria suficiente para a quantidade de inteiros digitada pelo usu�rio
    int *v2 = malloc(n * sizeof(int));//aloca mem�ria suficiente para a quantidade de inteiros digitada pelo usu�rio
    int *v3 = malloc(n * sizeof(int));//aloca mem�ria suficiente para a quantidade de inteiros digitada pelo usu�rio

    for (int i = 0; i < n; i++) {
        v1[i]=rand()%100;//vai sortear n�meros entre 0 e 99
    }
    for (int i = 0; i < n; i++) {
        v2[i]=rand()%100; //vai sortear n�meros entre 0 e 99
    }

    //vai imprimir o vetor v1
    for(int i=0; i<n; i++){
        printf("%d ", v1[i]);
    }
    printf("\n");
    //vai imprimir o vetor v2
    for(int i=0; i<n; i++){
        printf("%d ", v2[i]);
    }
    printf("\n");

    soma_v(v1, v2, v3, n);//chama a fun��o e manda os vetores v1, v2, v3 e o n fornecido pelo usu�rio como par�metros.

    //imprimi o vetor resultado
    for(int i=0; i<n; i++){
        printf("%d ", v3[i]);
    }

    free(v3);//libera a mem�ria
    free(v2);
    free(v1);
    return 0;
}
