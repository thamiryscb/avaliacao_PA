#include <stdio.h>
#include <stdlib.h>

int comparacao(const void *x, const void *y) {
    return (*(int*)x - *(int*)y);
}

void ordenacao(int *vetor, int n, int (*comparar)(const void *, const void *)){
    int aux;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            //compara os elementos usando a função por ponteiro
            if (comparar(&vetor[j], &vetor[j + 1]) > 0) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}
int main()
{
    int n;
    int *numeros;

    scanf("%d", &n);//Lê um inteiro e armazena na variável 'n'
    numeros = malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Digite o valor %d: ", i);
        scanf("%d", &numeros[i]);
    }
    ordenacao(numeros, n, comparacao);
    printf("\nOrdem crescente:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
    }
    free(numeros);
    return 0;
}
