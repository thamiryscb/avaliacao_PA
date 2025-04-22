#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct teste{ //no struct n�o pode ser feito a inicializa��o das vari�veis, pois o struct define apenas a estrutura
    int x;
    char nome[5];
};

int main()
{
    struct teste *s; //anteriormente era criado um ponteiro que n�o apontava para nenhum lugar, poderia gerar um comportamento indefinido.

    s = malloc(sizeof(struct teste)); //aloca a mem�ria para o struct e faz com que esse aponte para uma determinada parte da mem�ria para alocar o struct

    s->x = 3; //acessa o inteiro, que � definido como 3.
    strcpy(s->nome, "jose"); //strcpy � uma fun��o para copiar uma string num array
    printf("%d ", s->x); //o s � usando pq ele � um ponteiro para struct
    printf("%s ", s->nome); //-> � para acessar algo atrav�s de ponteiros
    free(s); //libera a mem�ria anteriormente alocada
    return 0;
}
