#include <stdio.h>
#include <stdlib.h>

int main()
{
    float vet[5] = {1.1,2.2,3.3,4.4,5.5};
    float *f;
    int i;
    f = vet;
    printf("contador/valor/valor/endereco/endereco\n");
    for(i = 0 ; i <= 4 ; i++){
        //*(f+1) = vet[i]
        printf("i = %d",i); //aqui vai imprimir em qual volta est� o la�o do for, come�ando em 0, at� 4
        printf(" vet[%d] = %.1f",i, vet[i]); //aqui vai mostrar o valor armazenado no vetor na posi��o i
        printf(" *(f + %d) = %.1f",i, *(f+i)); // aqui vai mostrar o valor armazenado atrav�s de ponteiros
        printf(" &vet[%d] = %X",i, &vet[i]); //o %X imprimi unsigned int (numeros inteiro em hexadecimal), &vet[i] vai mostrar o endere�o do elemento i
        printf(" (f + %d) = %X",i, f+i);//endere�o de f+i
        printf("\n");
    }
    return 0;
}
