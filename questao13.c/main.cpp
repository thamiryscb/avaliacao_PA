#include <iostream>
//Resposta: a questão supõe que o char ocupa 1 byte, ao executar observamos que realmente ocupa, sendo assim x[0]=4092, x[1]=4093, x[2]=4094, x[3]=4095
//também afirma que int ocupa 2 bytes, mas na verdade ocupa 4 bytes, que possuem esse comportamento de armazenamento é o short int, assim o int será: x[0]=4092, x[1]=4096, x[2]=4100, x[3] = 4104.
//o tipo float também ocupa 4 bytes como afirmado na questão, sendo: x[0]=4092, x[1]=4096, x[2]=4100, x[3] = 4104.
//o tipo  double realmente ocupa 8 bytes, sendo: x[0]=4092, x[1]=4100, x[2]=4108, x[3] = 4116.

using namespace std;

int main()
{
    char x[4];
    short int y[4];
    int p[4];
    float z[4];
    double t[4];

    //imprimi o endereço de char
    for(int i=0; i<4; i++){
        printf("%p ", &x[i]);
    }
    printf("\n");

    //imprimi endereço do short int
    for(int i=0; i<4; i++){
        printf("%p ", &y[i]);
    }
    printf("\n");

    //imprimi endereço do int
    for(int i=0; i<4; i++){
        printf("%p ", &p[i]);
    }
    printf("\n");

    //imprimi endereço do float
    for(int i=0; i<4; i++){
        printf("%p ", &z[i]);
    }
    printf("\n");

    //imprimi endereço do double
    for(int i=0; i<4; i++){
        printf("%p ", &t[i]);
    }
    return 0;
}
/*Endereços da minha memória:
000000000061fe08 000000000061fe09 000000000061fe0a 000000000061fe0b
000000000061fe00 000000000061fe02 000000000061fe04 000000000061fe06
000000000061fdf0 000000000061fdf4 000000000061fdf8 000000000061fdfc
000000000061fde0 000000000061fde4 000000000061fde8 000000000061fdec
000000000061fdc0 000000000061fdc8 000000000061fdd0 000000000061fdd8
*/
