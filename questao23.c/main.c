#include <stdio.h>
#include <stdlib.h>

void soma_v(int *vet1, int *vet2, int *resultado, int n){
    for(int i=0; i<n; i++){
        resultado[i] = vet1[i]+vet2[i];
    }
}
int main()
{
    int n;
    scanf("%d", &n);//Lê um inteiro e armazena na variável 'n'

    int *v1 = malloc(n * sizeof(int));
    int *v2 = malloc(n * sizeof(int));
    int *v3 = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        v1[i]=rand()%100;
    }
    for (int i = 0; i < n; i++) {
        v2[i]=rand()%100;
    }

    for(int i=0; i<n; i++){
        printf("%d ", v1[i]);
    }
    printf("\n");
    for(int i=0; i<n; i++){
        printf("%d ", v2[i]);
    }
    printf("\n");

    soma_v(v1, v2, v3, n);
    for(int i=0; i<n; i++){
        printf("%d ", v3[i]);
    }

    free(v3);
    free(v2);
    free(v1);
    return 0;
}
