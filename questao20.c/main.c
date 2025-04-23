#include <stdio.h>
#include <stdlib.h>

int ordenacao(const void *p, const void *n){
    //o void* vai gerar um ponteiro genérico para qualquer tipo de dado e o const que o conteúdo apontado não será alterado
    return *(int*)p - *(int*)n;
    //(int*)p converte o ponteiro genérico criado antes para inteiro, e o * vai acessar o valor para o qual esse ponteiro aponta
    //ele realiza a subtração dos dois inteiros
    //1º caso: se p<n, resultado negativo e o qsort entende que p vem antes de n
    //2º caso: se p>n, resultado positivo e qsort entende que n vem antes de p
}
//a função ordenação precisa retornar um inteiro porque o qsort exige isso, além de que os argumentos da função devem ser do tipo const void
int main()
{
    int n;
    float *numeros;

    scanf("%d", &n);//Lê um inteiro e armazena na variável 'n'
    numeros = malloc(n*sizeof(float)); //alocação dinâmica, vai alocar um espaço da memória

    for (int i = 0; i < n; i++) {
        printf("Digite o valor %d: ", i);
        scanf("%f", &numeros[i]);
        //um laço para que o usuário insira os números
    }
    qsort(numeros, n, sizeof(float), ordenacao);//uso da função para ordernar de maneira crescente
    printf("\nOrdem crescente:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", numeros[i]);
        //exibe os numeros na ordem desejada
    }
    free(numeros);//libera a memória alocada antes
    return 0;
}
