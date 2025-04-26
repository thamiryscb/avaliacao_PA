#include <stdio.h>
#include <stdlib.h>

void ordenacao(float *p, int n){
    float aux;
    //o objetivo do bubble sort é empurrar o maior elemento para i final em cada passagem
    //no primeiro for vai ser i<n-1 porque se o vetor tiver n=3 se ele percorrer o de 0 ao 2 o ultimo elemento já vai está ordenado, então não vai precisar passar
    for(int i =0; i<n-1; i++){
        //o segundo for vai necessitar de menos comparações, já que o primeiro tem um intervalo maior, vai comparar do começo até onde ainda falta ordenar
        //exemplo: quando i=0, vai comparar até o penultimo, em i=1, até o antipenultimo e asssim por diante.
        for(int j=0; j< n - i - 1; j++){
            if(p[j]>p[j+1]){//realiza o bubble sort, usa uma variável auxiliar para que ela armazene o valor maior e possa realizar a troca
                aux=p[j];
                p[j] = p[j+1];
                p[j+1]=aux;
            }
        }
    }
}
int main()
{
    int n;
    float *numeros;

    scanf("%d", &n);//Lê um inteiro e armazena na variável 'n'
    numeros = malloc(n*sizeof(float)); //aloca memória para o ponteiro

    for (int i = 0; i < n; i++) {//laço de repetição para o usuário informar os valores que irão compor o vetor
        printf("Digite o valor %d: ", i);
        scanf("%f", &numeros[i]);
    }
    ordenacao(numeros, n); //chama a função criada para ordernar e passa os valores que o usuário digitou
    printf("\nOrdem crescente:\n");
    for (int i = 0; i < n; i++) { //imprimi os numeros já em ordem crescente
        printf("%.2f ", numeros[i]); //%.2f vai definir 2 casas decimais para os floats
    }
    free(numeros);//libera a memória alocada antes
    return 0;
}
