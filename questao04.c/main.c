#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valor;
    int *p1;
    float temp;
    float *p2;
    char aux;
    char *nome = "Ponteiros";
    char *p3;
    int idade;
    int vetor[3];
    int *p4;
    int *p5;

    /* (a) */
    //Resultado: 20, apesar de receber o valor 10, Pl recebe o endere�o de valor, logo ap�s � guardado 20 no endere�o que foi colocado anteriormente.
    valor = 10;
    p1 = &valor;
    *p1 = 20;
    printf("%d \n", valor);

    /* (b) */
    // 29.0, pelo mesmo motivo
    temp = 26.5;
    p2 = &temp;
    *p2 = 29.0;
    printf("%.1f \n", temp);

    /* (c) */
    // P
    p3 = &nome[0];
    aux= *p3;
    printf("%c \n", aux);

    /* (d) */
    //e
    p3= &nome[4];
    aux= *p3;
    printf("%c \n", aux);

    /* (e) */
    // P, como � um ponteiro para o primeiro caractere.
    p3= nome;
    printf("%c \n", *p3);

    /* (f) */
    //e, o ponteiro move 4 posi��es, j� que antes tinha recebido nome, ele vai andar 4 posi��es;
    p3= p3+4;
    printf("%c \n", *p3);

    /* (g) */
    //t, ele volta uma posi��o que tava antes;
    p3--;
    printf("%c \n", *p3);

    /* (h) */
    //31, por ser um ponteiro vai retorna a primeira posi��o.
    vetor[0]= 31;
    vetor[1]= 45;
    vetor[2]= 27;
    p4= vetor;
    idade= *p4;
    printf("%d \n", idade);

    /* (i) */
    //45, andou uma posi��o em p4, que � o vetor, recebendo o conte�do do vetor[1]
    p5= p4+1;
    idade= *p5;
    printf("%d \n", idade);

    /* (j) */
    //27, andou uma posi��o do p4
    p4= p5+1;
    idade= *p4;
    printf("%d \n", idade);

    /* (l) */
    //31, voltou duas posi��es
    p4= p4-2;
    idade= *p4;
    printf("%d \n", idade);

    /* (m) */
    //45, vai mover o ponteiro uma posi��o, indo para vetor[1].
    p5= &vetor[2]-1;
    printf("%d \n", *p5);

    /* (n) */
    //27 vai mover o ponteiro para o pr�ximo elemento
    p5++;
    printf("%d \n", *p5);
    return 0;
}
