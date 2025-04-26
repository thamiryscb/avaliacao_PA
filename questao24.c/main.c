#include <stdio.h>
#include <stdlib.h>
void multi_matriz(int *A, int *B, int *C, int l_a, int c_a, int c_b){
    for(int i=0; i<l_a; i++){
        //o primeiro for vai percorrer cada linha de A
        for(int j=0; j<c_b; j++){
            //o segundo for vai percorrer todas as colunas de B, já que a multiplicação de matriz é feita linha por coluna.
            C[i * c_b + j] = 0;//importante inicializar cada elemento de C com zero, para que nenhum lixo de memória atrapalhe a operação
            for (int k = 0; k < c_a; k++) {
                //ao final temos que somar os produtos dos pares de elementos, esse terceiro for vai percorrer todos os elementos da linha A e da coluna B, fazer o produto entre ele e guardar em C
                //sem o K não iria conseguir somar os demais elementos da linha e da coluna, ia pegar apenas o primeiro
                C[i * c_b + j] += A[i * c_a + k] * B[k * c_b + j];
                //C[i*c_b+j] = C[i*c_b][j] e assim para os demais
            }
        }
    }
}
int main()
{
    int l_a, l_b, c_a, c_b;
    int l_A = 2, c_A = 3, c_B = 4;

    int *A = malloc(l_A * c_A * sizeof(int)); //aloca a memória que comporte a matriz A
    int *B = malloc(c_A * c_B * sizeof(int)); //aloca a memória que comporte a matriz B
    int *C = malloc(l_A * c_A * sizeof(int)); //aloca a memória que comporte a matriz C

    for (int i = 0; i < l_A * c_A; i++)
        A[i] = rand() % 10;
    for (int i = 0; i < c_A * c_B; i++)
        B[i] = rand() % 10;

    //imprimi a matriz A
    for(int i=0; i<l_A;i++){
        for(int j=0; j<c_A; j++){
            printf("%4d ",A[i * c_A + j]);
        }
        printf("\n");
    }
    printf("\n");
    //imprimi a matriz B
    for(int i=0; i<c_A;i++){
        for(int j=0; j<c_B; j++){
            printf("%4d ",B[i * c_B + j]);
        }
        printf("\n");
    }
    printf("\n");

    multi_matriz(A, B, C, l_A, c_A, c_B);//chama a função

    //imprimi a matriz C
    for(int i=0; i<l_A;i++){
        for(int j=0; j<c_B; j++){
            printf("%4d ",C[i * c_B + j]);
        }
        printf("\n");
    }

    free(C);//libera a memória
    free(B);
    free(A);
    return 0;
}
