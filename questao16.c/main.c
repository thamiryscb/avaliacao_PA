#include <stdio.h>
#include <stdlib.h>

int main()
{
    float aloha[10], coisas[10][5], *pf, value = 2.2;
    int i=3;

    aloha[2] = value;//válido, na posição 2 aloha vai recber valoue, que é 2.2
    scanf("%f", &aloha); //válido, scanf é usado para receber dados do usuário, %f para formato float, &aloha vai retornar o endereço
    aloha = "value"; //não é válido aloha é um vetor do tipo float e ta sendo passado uma string, da erro pois os tipos são incompatíveis
    printf("%f", aloha);//não é válido, %f vai esperar um float enquanto aloha é um vetor
    coisas[4][4] = aloha[3]; //válido, pois o array da posição [4][4] está recebendo o conteúdo de aloha na posição 3
    coisas[5] = aloha;//não é válido, coisas é um array com capacidade para 5 enquanto aloha é 10, da erro em c
    pf = value; // não é válido, porque pf é um ponteiro para float então ele ta guardando um endereço e não tem como receber um número float
    pf = aloha; //válido, pois pf é um ponteiro para float e irá receber o endereço do primeiro elemento de aloha
}
