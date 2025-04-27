#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ***m;
    int al, lar, prof;
    int i, j, k, opcao, valor, plano;

    printf("Altura, Largura e Profundidade: ");
    scanf("%d %d %d", &al, &lar, &prof);//pede para o usuário inserir

    //esse trecho faz toda a alocação de memória da matriz levando em consideração a sua altura, largura e profundidade.
    m = malloc(al * sizeof(int **));
    for (i = 0; i < al; i++) {
        m[i] = malloc(lar * sizeof(int *));
        for (j = 0; j < lar; j++) {
            m[i][j] = malloc(prof * sizeof(int));
        }
    }


    // Inicializa matriz com 0
    for (i = 0; i < al; i++)
        for (j = 0; j < lar; j++)
            for (k = 0; k < prof; k++)
                m[i][j][k] = 0;

    printf("\nMenu:\n1 - Imprimir plano\n2 - Modificar elemento\n3 - Sair\n");

    opcao = 0;
    //defini a opção como 0, e entra no laço que vai permanecer até que seja diferente de 3.
    while (opcao != 3) {
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            //quando entrar nessa opção vai imprimir a matriz a partir do plano digitado pelo usuário
            printf("Digite o indice do plano (altura) para imprimir: ");
            scanf("%d", &plano);
            if (plano >= 0 && plano < al) {
                for (j = 0; j < lar; j++) {
                    for (k = 0; k < prof; k++) {
                        printf("%d ", m[plano][j][k]); // Acessa elemento [altura][largura][profundidade]
                    }
                    printf("\n");
                }
            } else {
                printf("Plano invalido!\n");
            }
        }
        else if (opcao == 2) {
            //vai modificar o valor contido, que pode ser 0 ou 1, de acordo com as intruções que usuário difinir
            printf("Digite altura, largura, profundidade e novo valor (0 ou 1): ");
            scanf("%d %d %d %d", &i, &j, &k, &valor);
                m[i][j][k] = valor;
        }
        else if (opcao != 3) {
            printf("Opcao invalida!\n");
        }
    }

    // Libera memoria
    for (i = 0; i < al; i++) {
        for (j = 0; j < lar; j++) {
            free(m[i][j]);
        }
        free(m[i]);
    }
    free(m);

    return 0;
}
