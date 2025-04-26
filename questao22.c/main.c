#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int comparacao(const void *x, const void *y) {
    return (*(int*)x - *(int*)y);
    //(int*)p converte o ponteiro gen�rico criado antes para inteiro, e o * vai acessar o valor para o qual esse ponteiro aponta
    //ele realiza a subtra��o dos dois inteiros
    //1� caso: se p<n, resultado negativo e o qsort entende que p vem antes de n
    //2� caso: se p>n, resultado positivo e qsort entende que n vem antes de p
}

void ordenacao(int *vetor, int n, int (*comparar)(const void *, const void *)){
    int aux;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            //compara os elementos usando a fun��o por ponteiro
            if (comparar(&vetor[i], &vetor[j]) > 0) {
                ////se o vetor[j] for maior que vetor[j+1] ele vai trocar eles de posi��o
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
    int *v1 = malloc(n * sizeof(int));//aloca mem�ria suficiente para n, nesse caso 1000 interios
    int *v2 = malloc(n * sizeof(int));//aloca mem�ria suficiente para n, nesse caso 1000 interios

    clock_t tempo; //fazer o benchmarking

    for (int i = 0; i < n; i++) {
        v1[i]=rand()%100; //sorteia os valores entre 0 a 99
    }

    //faz o uso do memcpy para fazer a c�pia e assim poder comparar com o qsort
    memcpy(v2, v1, n*sizeof(int));

    tempo = clock();//vai capturar o tempo antes de chamar a fun��o ordena��o, contando quantos ticks de rel�gio vai durar(vai medir tempo de CPU gasto)
    ordenacao(v1, n, comparacao);//a fun��o � chamada
    tempo = clock() - tempo;//vai calcular o tempo gasto nessa ordena��o, pegando o tempo atual e subtra do inicial
    printf("Funcao Comparacao: %d \n", (int)tempo);//exibe

    //realiza o mesmo processo
    tempo = clock();
    qsort(v2, n, sizeof(int), comparacao);
    tempo = clock()-tempo;
    printf("Funcao Qsort: %d \n", (int)tempo);

    free(v2);//libera a mem�ria
    free(v1);//libera a mem�ria
    return 0;
}

//Conclus�o: o tempo da fun��o ordena��o ser� maior que a do qsort, isso porque o bubble sort vai andar o array completo e testar um por um, levando bem mais tempo que o qsort.
//o qsort vai dividir o vetor em partes menores e ir� ordernar cada parte de maneira bem mais r�pida.
