#include <stdio.h>
#include <stdlib.h>

int comparacao(const void *x, const void *y) {
    return (*(int*)x - *(int*)y);
    //(int*)p converte o ponteiro genérico criado antes para inteiro, e o * vai acessar o valor para o qual esse ponteiro aponta
    //ele realiza a subtração dos dois inteiros
    //1º caso: se p<n, resultado negativo e o qsort entende que p vem antes de n
    //2º caso: se p>n, resultado positivo e qsort entende que n vem antes de p
}

void ordenacao(int *vetor, int n, int (*comparar)(const void *, const void *))//faz o uso do ponteiro para função
{
    int aux;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            //compara os elementos usando a função comparação
            if (comparar(&vetor[j], &vetor[j + 1]) > 0)//se o vetor[j] for maior que vetor[j+1] ele vai trocar eles de posição
            {
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
    int *numeros;//ponteiro para inteiro

    scanf("%d", &n);//Lê um inteiro e armazena na variável 'n'
    numeros = malloc(n*sizeof(int));//aloca memória suficiente para a quantidade de inteiros digitada pelo usuário

    for (int i = 0; i < n; i++) {
        //pede ao usuário digitar os valores e guarda em numeros
        printf("Digite o valor %d: ", i);
        scanf("%d", &numeros[i]);
    }
    ordenacao(numeros, n, comparacao);//chama a função ordenação para ordenar o vetor numeros usando a comparação
    printf("\nOrdem crescente:\n");
    for (int i = 0; i < n; i++) {
        //imprimi o vetor ordernado
        printf("%d ", numeros[i]);
    }
    free(numeros);//libera a memória alocada antes
    return 0;
}
