#include <stdio.h>
#include <string.h>

#define NLIN 10
#define NCOL 10

int main(){
    // Testando leitura da matriz para replicar o comportamento na prática 14

    FILE *arq;
    char arqNome[20] = "teste.txt";

    char matriz[NLIN][NCOL];

    arq = fopen(arqNome, "r");
    if (arq != NULL){
        // Leitura do arquivo para a matriz
        for (int i = 0; i < NLIN; i++){ // Percorre as linhas
            fgets(matriz[i], NCOL + 2, arq);
        }

        fclose(arq);

    } else printf("erro abertura leitura\n");

    // Impressão da matriz
    for (int i = 0; i < NLIN; i++){ // Percorre as linhas
        printf("Linha %02d: ", i+1);
        for (int j = 0; j < NCOL; j++){ // Percorre as colunas
            char lido = matriz[i][j];
            printf("%c", lido);
        }
        printf("\n");
    }
    printf("\n\n");

    // Gravando o conteúdo da matriz em um arquivo
    strcpy(arqNome, "teste-copia.txt");

    arq = fopen(arqNome, "w");
    if (arq != NULL){
        for (int i = 0; i < NLIN; i++){ // Percorre as linhas
            for (int j = 0; j < NCOL; j++){ // Percorre as colunas
                putc(matriz[i][j], arq);
            }
            putc('\n', arq);
        }

        fclose(arq);
        printf("Gravado com sucesso no arquivo %s.\n", arqNome);
    } else printf("erro abertura escrita\n");

    return 0;
}
