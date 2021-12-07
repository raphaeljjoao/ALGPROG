#include <stdio.h>
#include <locale.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

#define NLIN 10
#define NCOL 10

/*
 * Aluno: João Raphael Fontoura Dorneles (333315)
 * Enunciado: Faça um programa para ler e imprimir na tela o conteúdo de um arquivo texto fornecido (utilize o arquivo teste.txt disponível no
 *            moodle para teste).
 */

// Menu de opções, retorna a opção escolhida
int menu();

// Lê o nome de um arquivo e salva na variável passada
void leNomeArq(char nome_arq[]);

// (Continuação do enunciado) O seu programa deverá, obrigatoriamente, ter as funções abaixo:

/* Esta função deve abrir para leitura o arquivo texto cujo nome é informado na variável nome_arq e ler o conteúdo do arquivo para a matriz m.
 * Ela retorna o valor 1 em caso de sucesso e -1 em caso de problema na leitura.*/
int abre_le_arquivo(char m[NLIN][NCOL], char nome_arq[]);

// Esta função imprime na tela, em formato de matriz, o conteúdo de m.
void imprime_matriz_tela(char m[NLIN][NCOL]);

/* Esta função abre e grava em disco em formato texto o conteúdo da matriz m no arquivo com nome especificado pela variável nome_arq.
 * Ela retorna o valor 1 em caso de sucesso e -1 em caso de problema na gravação. */
int abre_grava_arquivo(char m[NLIN][NCOL], char nome_arq[]);

// Esta função troca todas as ocorrências do caracter velho pelo caracter novo na matriz m.
void troca_caracter(char m[NLIN][NCOL], char velho, char novo);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int opcao, conteudoLido = FALSE;
    char conteudoArquivo[NLIN][NCOL];

    do {
        opcao = menu();
        char arqNome[100];

        // Nesse trecho, optei por usar o if em vez do switch por ser possível definir novas variáveis dentro de cada caso
        if (opcao == 1){
            printf("Entre com o nome do arquivo: ");
            leNomeArq(arqNome);

            int lidoSucesso = abre_le_arquivo(conteudoArquivo, arqNome) == 1;
            conteudoLido = lidoSucesso;
            if (lidoSucesso)
                printf("Arquivo lido com sucesso.\n");
            else printf("Não foi possível ler o arquivo %s.\n", arqNome);
        } else if (opcao == 2){
            if (conteudoLido)
                imprime_matriz_tela(conteudoArquivo);
            else printf("Não foi possível imprimir a matriz na tela. Leia um arquivo antes.\n");
        } else if (opcao == 3){
            if (conteudoLido){
                char antigo, novo;
                printf("Entre com o caractere a ser substituído: ");
                scanf(" %c", &antigo);
                printf("Entre com o novo caractere: ");
                scanf(" %c", &novo);
                printf("\n");

                troca_caracter(conteudoArquivo, antigo, novo);
                printf("Todas as ocorrências de '%c' foram trocadas por '%c' na matriz.\n", antigo, novo);
            } else printf("Não foi possível realizar substituições na matriz. Leia um arquivo antes.\n");
        } else if (opcao == 4){
            if (conteudoLido){
                printf("Entre com o nome do arquivo: ");
                leNomeArq(arqNome);
                int gravadoSucesso = abre_grava_arquivo(conteudoArquivo, arqNome) == 1;
                if (gravadoSucesso)
                    printf("Arquivo gravado com sucesso.\n");
                else printf("Não foi possível a matriz gravar no arquivo %s.\n", arqNome);
            } else printf("Não foi gravar a matriz no arquivo. Leia um arquivo antes.\n");
        }
        printf("\n");
    } while(opcao != 5);

    return 0;
}

int menu(){
    int opcao, opcaoValida;
    do {
        printf("1 - Ler arquivo\n");
        printf("2 - Imprimir matriz na tela\n");
        printf("3 - Trocar caractere\n");
        printf("4 - Gravar arquivo\n");
        printf("5 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        printf("\n");

        opcaoValida = opcao >= 1 && opcao <= 5;
        if (!opcaoValida)
            printf("Opção inválida.\n\n");

    } while(!opcaoValida);

    return opcao;
}

void leNomeArq(char nome_arq[]){
    fflush(stdin); // Evita que um ENTER de outra leitura seja lido pelo fgets a seguir
    fgets(nome_arq, 100+1, stdin);
    nome_arq[strlen(nome_arq)-1] = '\0';
}

int abre_le_arquivo(char m[NLIN][NCOL], char nome_arq[]){
    int codigo = -1; // Padrão: -1 | não foi possível abrir o arquivo
    FILE *arq;
    arq = fopen(nome_arq, "r"); // Modo read, erro se o arquivo não existir

    if (arq != NULL){
        codigo = 1; // Foi possível abrir o arquivo

        for (int i = 0; i < NLIN; i++){ // Percorre as linhas
            fgets(m[i], NCOL+2, arq);
        }

        fclose(arq);
    }

    return codigo;
}

void imprime_matriz_tela(char m[NLIN][NCOL]){
    for (int linha = 0; linha < NLIN; linha++){ // Percorre as linhas
        for (int coluna = 0; coluna < NCOL; coluna++){ // Percorre as colunas
            printf("%c", m[linha][coluna]);
        }
        printf("\n");
    }
    printf("\n");
}

int abre_grava_arquivo(char m[NLIN][NCOL], char nome_arq[]){
    int codigo = -1; // Padrão: -1 | não foi possível abrir o arquivo
    FILE *arq;
    arq = fopen(nome_arq, "w"); // Modo write, se o arquivo existir, o sobrescreve

    if (arq != NULL){
        codigo = 1; // Foi possível abrir o arquivo

        for (int linha = 0; linha < NLIN; linha++){ // Percorre as linhas
            for (int coluna = 0; coluna < NCOL; coluna++){ // Percorre as colunas
                putc(m[linha][coluna], arq);
            }
            putc('\n', arq);
        }

        fclose(arq);
    }

    return codigo;
}

void troca_caracter(char m[NLIN][NCOL], char velho, char novo){
    for (int linha = 0; linha < NLIN; linha++){ // Percorre as linhas
        for (int coluna = 0; coluna < NCOL; coluna++){ // Percorre as colunas
            char atual = m[linha][coluna];
            if (atual == velho)
                m[linha][coluna] = novo;
        }
    }
}
