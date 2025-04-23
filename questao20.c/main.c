#include <stdio.h>
#include <stdlib.h>

int ordenacao(const void *p, const void *n){
    //o void* vai gerar um ponteiro gen�rico para qualquer tipo de dado e o const que o conte�do apontado n�o ser� alterado
    return *(int*)p - *(int*)n;
    //(int*)p converte o ponteiro gen�rico criado antes para inteiro, e o * vai acessar o valor para o qual esse ponteiro aponta
    //ele realiza a subtra��o dos dois inteiros
    //1� caso: se p<n, resultado negativo e o qsort entende que p vem antes de n
    //2� caso: se p>n, resultado positivo e qsort entende que n vem antes de p
}
//a fun��o ordena��o precisa retornar um inteiro porque o qsort exige isso, al�m de que os argumentos da fun��o devem ser do tipo const void
int main()
{
    int n;
    float *numeros;

    scanf("%d", &n);//L� um inteiro e armazena na vari�vel 'n'
    numeros = malloc(n*sizeof(float)); //aloca��o din�mica, vai alocar um espa�o da mem�ria

    for (int i = 0; i < n; i++) {
        printf("Digite o valor %d: ", i);
        scanf("%f", &numeros[i]);
        //um la�o para que o usu�rio insira os n�meros
    }
    qsort(numeros, n, sizeof(float), ordenacao);//uso da fun��o para ordernar de maneira crescente
    printf("\nOrdem crescente:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", numeros[i]);
        //exibe os numeros na ordem desejada
    }
    free(numeros);//libera a mem�ria alocada antes
    return 0;
}
