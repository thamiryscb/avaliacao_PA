#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=5, *p; //i � uma vari�vel inteira que guarda o valor 5, j� p � um ponteiro que logo em seguida guarda o endere�o de i.
    p = &i;
    printf("%p %p %d %d %d %d\n", p, p+1, *p+2, **&p, 3**p, **&p+4);
    //%p -> p, p guarda o endere�o de i, ent�o ser� impresso: 4094, sendo esse a posi��o de i na mem�ria;
    //%p -> p+1, p+1 significa o pr�ximo endere�o de um int na mem�ria, j� que int ocupa 2 bytes, p+1 avan�a 2 bytes em rela��p a p; saindo:  4096;
    //%d -> *p+2, *p vai acessar o valor armazenado em p e vai somar a esse valor o 2, tendo como sa�da o 7;
    //%d -> **&p, vai pegar o endere�o de p, l� o valor armazenado no endere�o de p, que no caso � o endere�o de i (&i), logo ap�s l� o valor armazenado no endere�o de i que � 5;
    //%d -> 3**p, acessa o valor que � armazenado em p, que � 5, e multiplica por 3. Resultado: 15;
    //%d -> **&p+4, vai pegar o endere�o de p, l� o valor armazenado no endere�o de p, que no caso � o endere�o de i (&i), logo ap�s l� o valor armazenado no endere�o de i e soma 4, Resultado: 9.
    return 0;
}
