#include <stdio.h>
#include <stdlib.h>

void ordenacao(float *p, int n){
    float aux;
    for(int i =0; i<n-1; i++){
        for(int j=0; j< n - i - 1; j++){
            if(p[j]>p[j+1]){
                aux=p[j];
                p[j] = p[j+1];
                p[j+1]=aux;
            }
        }
    }
}
int main()
{
    int n;
    float *numeros;

    scanf("%d", &n);//Lê um inteiro e armazena na variável 'n'
    numeros = malloc(n*sizeof(float));

    for (int i = 0; i < n; i++) {
        printf("Digite o valor %d: ", i);
        scanf("%f", &numeros[i]);
    }
    ordenacao(numeros, n);
    printf("\nOrdem crescente:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", numeros[i]);
    }
    free(numeros);
    return 0;
}
