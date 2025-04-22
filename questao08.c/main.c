#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pulo[5] = {1,2,3,4,5};

    printf("%d", *(pulo + 2));//vai acessar o terceiro elemento como o desejado *(pulo +2) = pulo[2]
    return 0;
}
