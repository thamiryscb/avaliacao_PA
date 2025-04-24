#include <stdio.h>
#include <stdlib.h>
void multi_matriz(int *A, int *B, int *C, int l_a, int c_a, int c_b){
    for(int i=0; i<l_a; i++){
        for(int j=0; j<c_b; j++){
            C[i * c_b + j] = 0;
            for (int k = 0; k < c_a; k++) {
                C[i * c_b + j] += A[i * c_a + k] * B[k * c_b + j];
            }
        }
    }
}
int main()
{
    int l_a, l_b, c_a, c_b;
    int l_A = 2, c_A = 3, c_B = 4;

    int *A = malloc(l_A * c_A * sizeof(int));
    int *B = malloc(c_A * c_B * sizeof(int));
    int *C = malloc(l_A * c_A * sizeof(int));

    for (int i = 0; i < l_A * c_A; i++)
        A[i] = rand() % 10;
    for (int i = 0; i < c_A * c_B; i++)
        B[i] = rand() % 10;


    for(int i=0; i<l_A;i++){
        for(int j=0; j<c_A; j++){
            printf("%4d ",A[i * c_A + j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0; i<c_A;i++){
        for(int j=0; j<c_B; j++){
            printf("%4d ",B[i * c_B + j]);
        }
        printf("\n");
    }
    printf("\n");

    multi_matriz(A, B, C, l_A, c_A, c_B);

    for(int i=0; i<l_A;i++){
        for(int j=0; j<c_B; j++){
            printf("%4d ",C[i * c_B + j]);
        }
        printf("\n");
    }

    free(C);
    free(B);
    free(A);
    return 0;
}
