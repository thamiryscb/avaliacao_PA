#include <stdio.h>
#include <stdlib.h>

void funcao(char** str){
    (*str)++;//antes não tinha o parentese fazendo com que ele movesse apenas localmente, sem modificar o valor original;
}
int main()
{
    char *str = (void *)malloc(50*sizeof(char));
    strcpy(str, "Agostinho");
    funcao(&str);
    puts(str);//imprimi a string armazenada em str
    free(str); //Libera a memória alocada com malloc
    return 0;
}
