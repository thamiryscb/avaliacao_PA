#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    scanf("%d", &n);//Lê um inteiro e armazena na variável 'n'
    int *v = malloc(n * sizeof(int));
    int *v1 = malloc(n * sizeof(int));
    int *v2 = malloc(n * sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        v[i]=rand()%100;
    }

    for (int i = 0; i < n; i++) {
        v1[i]=v[i];
        v2[i]=v[i];
    }
    clock_t inicio, fim;
    double tempo1, tempo2;

    inicio = clock();
    ordenacao(v1, n, comparacao);
    fim = clock();
    tempo1 = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    inicio = clock();
    qsort(v2, n, sizeof(int), comparacao);
    fim = clock();
    tempo2 = ((double)(fim - inicio)) / CLOCKS_PER_SEC;


    printf("\nVetor ordenacao:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v1[i]);
    }
    printf("\nVetor qsort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v2[i]);
    }

    printf("\n");
    printf("Ordenacao: %.6f segundos\n", tempo1);
    printf("Qsort: %.6f segundos\n", tempo2);

    free(v);
    free(v1);
    free(v2);
}
