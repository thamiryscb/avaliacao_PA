#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int comparacao(const void *x, const void *y) {
    return (*(int*)x - *(int*)y);
    //(int*)p converte o ponteiro genérico criado antes para inteiro, e o * vai acessar o valor para o qual esse ponteiro aponta
    //ele realiza a subtração dos dois inteiros
    //1º caso: se p<n, resultado negativo e o qsort entende que p vem antes de n
    //2º caso: se p>n, resultado positivo e qsort entende que n vem antes de p
}

void ordenacao(int *vetor, int n, int (*comparar)(const void *, const void *)){
    int aux;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            //compara os elementos usando a função por ponteiro
            if (comparar(&vetor[i], &vetor[j]) > 0) {
                ////se o vetor[j] for maior que vetor[j+1] ele vai trocar eles de posição
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}
int main()
{
    int n = 1000;//o inteiro n recebe o valor de 1000
    int *v1 = malloc(n * sizeof(int));//aloca memória suficiente para n, nesse caso 1000 interios
    int *v2 = malloc(n * sizeof(int));//aloca memória suficiente para n, nesse caso 1000 interios

    clock_t tempo; //fazer o benchmarking

    for (int i = 0; i < n; i++) {
        v1[i]=rand()%100; //sorteia os valores entre 0 a 99
    }

    //faz o uso do memcpy para fazer a cópia e assim poder comparar com o qsort
    memcpy(v2, v1, n*sizeof(int));

    tempo = clock();//vai capturar o tempo antes de chamar a função ordenação, contando quantos ticks de relógio vai durar(vai medir tempo de CPU gasto)
    ordenacao(v1, n, comparacao);//a função é chamada
    tempo = clock() - tempo;//vai calcular o tempo gasto nessa ordenação, pegando o tempo atual e subtra do inicial
    printf("Funcao Comparacao: %d \n", (int)tempo);//exibe

    //realiza o mesmo processo
    tempo = clock();
    qsort(v2, n, sizeof(int), comparacao);
    tempo = clock()-tempo;
    printf("Funcao Qsort: %d \n", (int)tempo);

    free(v2);//libera a memória
    free(v1);//libera a memória
    return 0;
}

//Conclusão: o tempo da função ordenação será maior que a do qsort, isso porque o bubble sort vai andar o array completo e testar um por um, levando bem mais tempo que o qsort.
//o qsort vai dividir o vetor em partes menores e irá ordernar cada parte de maneira bem mais rápida.
