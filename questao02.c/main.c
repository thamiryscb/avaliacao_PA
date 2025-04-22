#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=5, *p; //i é uma variável inteira que guarda o valor 5, já p é um ponteiro que logo em seguida guarda o endereço de i.
    p = &i;
    printf("%p %p %d %d %d %d\n", p, p+1, *p+2, **&p, 3**p, **&p+4);
    //%p -> p, p guarda o endereço de i, então será impresso: 4094, sendo esse a posição de i na memória;
    //%p -> p+1, p+1 significa o próximo endereço de um int na memória, já que int ocupa 2 bytes, p+1 avança 2 bytes em relaçãp a p; saindo:  4096;
    //%d -> *p+2, *p vai acessar o valor armazenado em p e vai somar a esse valor o 2, tendo como saída o 7;
    //%d -> **&p, vai pegar o endereço de p, lê o valor armazenado no endereço de p, que no caso é o endereço de i (&i), logo após lê o valor armazenado no endereço de i que é 5;
    //%d -> 3**p, acessa o valor que é armazenado em p, que é 5, e multiplica por 3. Resultado: 15;
    //%d -> **&p+4, vai pegar o endereço de p, lê o valor armazenado no endereço de p, que no caso é o endereço de i (&i), logo após lê o valor armazenado no endereço de i e soma 4, Resultado: 9.
    return 0;
}
