#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    int x, y, z;
    scanf("%d %d", &a, &b); //pede ao usuário 2 números inteiros
    //a(10) = 1010(bin)
    //b(1) = 0001 (bin)

    x = a; //x recebe o valor de a (10)
    y = b; //y recebe o valor de b (1)
    z = a + b; //z recebe a soma de a e b (10+1=11)
    while (a) { //laço de repetição que vai ocorrer enquanto a for diferente de 0, ou seja verdadeiro.
        x = x | b; //vai realizar um ou bit a bit
        // 1º ciclo: 10|1 - 1010|0001 = 1011 (11)
        // 2º ciclo: 11|2 - 1011|0010 = 1011 (11)
        // 3º ciclo: 11|4 - 1011|0100 = 1111 (15)
        // 4º ciclo: 15|8 - 1111|1000 = 1111 (15)

        y = y ^ a; //vai realizar um XOR bit a bit (1 quando apenas um dos dois é 1)
        //1º ciclo: 1^10 - 0001 ^ 1010 = 1011 (11)
        //2º ciclo: 11^5 - 1011 ^ 0101 = 1110 (14)
        //3º ciclo: 14^2 - 1110 ^ 0010 = 1100 (12)
        //4º ciclo: 12^1 - 1100 ^ 0001 = 1101 (13)

        z = z & (a+b); //vai realizar um AND entre z e (a+b)
        //1º ciclo: 11 & 11 = 1011 & 1011 = 1011 (11)
        //2º ciclo: 11 & 7 = 1011 & 0111 = 0011 (3)
        //3º ciclo: 3 & 6 = 0011 & 0110 = 0010 (2)
        //4º ciclo: 2 & 9 = 0010 & 1001 = 0000 (0)

        a = a >> 1;//desloca 1 bit a direita, ou seja dividi por 2(dividisão inteira) (primeiro ciclo: 5, segundo ciclo: 2, terceiro ciclo: 1, quarto ciclo: 0[ai saí do looping já que passa a ser 0, e torna-se falso])
        b = b << 1; // desloca 1 bit a esquerda, ou seja multiplica por 2 (primeiro ciclo: 2, segundo ciclo: 4, terceiro ciclo: 8, quarto ciclo: 16)
    }
    printf ("%d %d %d\n", x, y, z); // imprimi os resultados do ultimo ciclo das variáveis
    return 0;
}
//SAÍDA: 15 13 0
