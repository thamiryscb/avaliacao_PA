#include <stdio.h>
#include <stdlib.h>

int main()
{
    float aloha[10], coisas[10][5], *pf, value = 2.2;
    int i=3;

    aloha[2] = value;//v�lido, na posi��o 2 aloha vai recber valoue, que � 2.2
    scanf("%f", &aloha); //v�lido, scanf � usado para receber dados do usu�rio, %f para formato float, &aloha vai retornar o endere�o
    aloha = "value"; //n�o � v�lido aloha � um vetor do tipo float e ta sendo passado uma string, da erro pois os tipos s�o incompat�veis
    printf("%f", aloha);//n�o � v�lido, %f vai esperar um float enquanto aloha � um vetor
    coisas[4][4] = aloha[3]; //v�lido, pois o array da posi��o [4][4] est� recebendo o conte�do de aloha na posi��o 3
    coisas[5] = aloha;//n�o � v�lido, coisas � um array com capacidade para 5 enquanto aloha � 10, da erro em c
    pf = value; // n�o � v�lido, porque pf � um ponteiro para float ent�o ele ta guardando um endere�o e n�o tem como receber um n�mero float
    pf = aloha; //v�lido, pois pf � um ponteiro para float e ir� receber o endere�o do primeiro elemento de aloha
}
