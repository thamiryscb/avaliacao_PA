#include <stdio.h>
#include <stdlib.h>

//send vai receber o valor de 64bits
int send(unsigned long estado){
    unsigned char num_bit;

    for(int i=63; i>=0; --i){
        //o tamanho é 64 bits, mas como começa em 0 vai de o a 63, o laço vai até i>=0 para que o ultimo bit(0) seja lido
        //se não houver deslocamento de posição irá pegar o bit menos significativo o da direita.
        printf("%ld", (estado >> i) & 1);
        //vai descolar "estado" i posiçoes para a direita e realizar o AND com 1 para pegar apenas o bit à direita, imprimindo apenas 0 ou 1
    }
    printf("\n");

}
int main()
{
    //cria a mtriz 8x8
     unsigned char m[8][8] ={
        {0,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0},
        {1,0,1,0,1,0,1,0},
        {1,0,1,0,1,0,1,0}
    };

    unsigned long num;//vai servir para guardar os bits da matriz juntos

    //vai percorrer todas as posições da matriz m
     for(int i=0; i<8; ++i){
        for(int j=0; j<8; ++j){
            num = (num << 1); //desloca 1 bit a esquerda
            num = num | (int) m[i][j];//vai fazer um OR bit a bit entre num e o valor atual na matriz
        }
    }

    printf("%ld\n",num);//imrprimi o número em decimal
    send(num);//vai mostrar os 64bits do número

    return 0;
}
