#include <stdio.h>

char *a[] = {"AGOSTINHO", "MEDEIROS", "BRITO", "JUNIOR"}; //vetor de ponteiro para string
char **b[] = {a + 3, a + 2, a + 1, a}; //� um ponteiro para ponteiro e cada elemento de b vai apontar para um endere�o de algum elemento de a
//b[0] - (a+3) = a[3], b[1] - (a+2) = a[2], b[2] - (a+1) = a[1], b[3] -  a = a[0]

char ***c = b;//� um ponteiro para ponteiro para ponteiro, � inicializado com o primeiro elemento de b.

int main() {
    printf("%s ", **++c);
    //++c realiza um pr�-incremento, como c inicia em b[0] vai para b[1], acessa o conte�do de b[1] que� a[2] que � o ponteiro para a string "BRITO"
    printf("%s ", *--*++c + 3);
    //++c vai acessar b[2], j� que anteriormente foi feito um pr� incremento, que leva a a[1] que � o ponteiro para a string "MEDEIROS",
    //o operador de pr�-drecremento, fazneod com que ele decremente do elemento anterior que seria o "AGOSTINHO", +3 adciona 3 a este ponteiro, movendo 3 posi�oes e apontando para o S e isso faz com que a string come�a a partir desse endere�o resultante sendo impresso apenas "STINHO"
    printf("%s ", *c[-2] + 3);
    //c[-2] vai pegar o que estava apontando anteriormente que era b[2], e subtrai 2 chegando a b[0], levando a "JUNIOR", logo em seguida adicionamos 3 ao ponteiro a, fazendo apontar para o I e ser� impresso "IOR"
    printf("%s ", c[-1][-1] + 1);
    //c[-1][-1] = *(*(c-1)-1), *(c-1) � o conte�do de b[1] j� que anteriormente ele apontava para b[2], subtrai 1 do ponteiro a, levando ao a[1] que � a string "MEDEIROS", o +1 vai mover o ponteiro para o E, sendo impresso "EDEIROS"
    return 0;

    //S�ida final: BRITO STINHO IOR EDEIROS
}
