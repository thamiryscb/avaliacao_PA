#include <stdio.h>
#include <stdlib.h>

void ordenacao(float *p, int n){
    float aux;
    //o objetivo do bubble sort � empurrar o maior elemento para i final em cada passagem
    //no primeiro for vai ser i<n-1 porque se o vetor tiver n=3 se ele percorrer o de 0 ao 2 o ultimo elemento j� vai est� ordenado, ent�o n�o vai precisar passar
    for(int i =0; i<n-1; i++){
        //o segundo for vai necessitar de menos compara��es, j� que o primeiro tem um intervalo maior, vai comparar do come�o at� onde ainda falta ordenar
        //exemplo: quando i=0, vai comparar at� o penultimo, em i=1, at� o antipenultimo e asssim por diante.
        for(int j=0; j< n - i - 1; j++){
            if(p[j]>p[j+1]){//realiza o bubble sort, usa uma vari�vel auxiliar para que ela armazene o valor maior e possa realizar a troca
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

    scanf("%d", &n);//L� um inteiro e armazena na vari�vel 'n'
    numeros = malloc(n*sizeof(float)); //aloca mem�ria para o ponteiro

    for (int i = 0; i < n; i++) {//la�o de repeti��o para o usu�rio informar os valores que ir�o compor o vetor
        printf("Digite o valor %d: ", i);
        scanf("%f", &numeros[i]);
    }
    ordenacao(numeros, n); //chama a fun��o criada para ordernar e passa os valores que o usu�rio digitou
    printf("\nOrdem crescente:\n");
    for (int i = 0; i < n; i++) { //imprimi os numeros j� em ordem crescente
        printf("%.2f ", numeros[i]); //%.2f vai definir 2 casas decimais para os floats
    }
    free(numeros);//libera a mem�ria alocada antes
    return 0;
}
