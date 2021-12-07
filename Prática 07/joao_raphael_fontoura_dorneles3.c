#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 30

/*
 * Aluno: João Raphael Fontoura Dorneles (333315)
 * Enunciado: Na Teoria de Sistemas define-se como elemento minimax de uma
 *            matriz o menor elemento da linha em que se encontra o maior
 *            elemento da matriz. Fazer um programa para ler um inteiro N
 *            no intervalo [3, 9] (faça validação) e gerar uma matriz quadrada
 *            de dimensão NxN com elementos aleatórios no intervalo [1, 30].
 *            Após a geração da matriz o programa imprime na tela a matriz gerada
 *            (use um formatador como %3d) e calcula e imprime o elemento minimax.
 */

int main(){

    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    // Leitura e validação da dimensão para definição matriz
    int dimensao;
    do {
        printf("Entre com a dimensão da matriz: ");
        scanf("%d", &dimensao);
    } while(dimensao < 3 || dimensao > 9);

    int mat[dimensao][dimensao];

    // Alimentação da matriz com números pseudoaleatórios no intervalo [MIN, MAX]
    for (int i = 0; i < dimensao; i++){ // percorrendo as linhas
        // percorrendo as colunas
        for (int j = 0; j < dimensao; j++) mat[i][j] = rand() % (MAX-MIN+1) + MIN;
    }

    // Impressão da matriz
    for (int i = 0; i < dimensao; i++){ // percorrendo as linhas
        // percorrendo as colunas
        for (int j = 0; j < dimensao; j++) printf("%3d", mat[i][j]);
        printf("\n");
    }

    // Busca pela linha do maior elemento da matriz
    int linhaMaior;
    int maior = mat[0][0]; // base

    for (int i = 0; i < dimensao; i++){ // percorrendo as linhas
        for (int j = 0; j < dimensao; j++){ // percorrendo as colunas
            int novoMaior = mat[i][j];
            if (novoMaior > maior){
                maior = novoMaior;
                linhaMaior = i;
            }
        }
    }

    // Busca pelo menor elemento da linha onde está o maior elemento (minimax)

    int menor = mat[linhaMaior][0]; // base
    for (int i = 0; i < dimensao; i++){
        int novoMenor = mat[linhaMaior][i];
        if (novoMenor < menor) menor = novoMenor;
    }

    // Impressão do elemento minimax
    printf("O elemento minimax da matriz vale %d.\n", menor);

    return 0;
}
