#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct teste{ //no struct não pode ser feito a inicialização das variáveis, pois o struct define apenas a estrutura
    int x;
    char nome[5];
};

int main()
{
    struct teste *s; //anteriormente era criado um ponteiro que não apontava para nenhum lugar, poderia gerar um comportamento indefinido.

    s = malloc(sizeof(struct teste)); //aloca a memória para o struct e faz com que esse aponte para uma determinada parte da memória para alocar o struct

    s->x = 3; //acessa o inteiro, que é definido como 3.
    strcpy(s->nome, "jose"); //strcpy é uma função para copiar uma string num array
    printf("%d ", s->x); //o s é usando pq ele é um ponteiro para struct
    printf("%s ", s->nome); //-> é para acessar algo através de ponteiros
    free(s); //libera a memória anteriormente alocada
    return 0;
}
