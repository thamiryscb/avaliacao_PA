#include <stdio.h>
#include <stdlib.h>

int main(){
    int vet[] = {4, 9, 13};
    int i;
    for(i=0;i<3;i++){
        printf("%d ", *(vet+i)); //vai mostrar os valores armazenados no vetor, nesse caso possui 3 elementos, por isso o for vai de 0 at� 2,
            //*(vet+i) corresponde a vet[i], assim quando i=0 vai mostrar na tela o valor armazenado do vetor na posi��o 0.
    }
    main2();
}

int main2(){
    int vet[] = {4, 9, 13};
    int i;
    for(i=0;i<3;i++){
        printf("%X ",vet+i);//vai mostrar os endere�os em hexadecimal de cada elemento do vetor nesse caso vai aumentar de 4 em 4 byts, por ser do tipo inteiro.
    }
}
