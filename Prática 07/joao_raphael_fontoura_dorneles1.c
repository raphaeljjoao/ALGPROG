#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

#define DIML 4 // dimens�o das linhas
#define DIMC 4 // dimens�o das colunas

#define MIN 2
#define MAX 40

/*
 * Aluno: Jo�o Raphael Fontoura Dorneles (333315)
 * Enunciado: Preencha uma matriz de dimens�o 4x4 com n�meros aleat�rios no intervalo [2,40].
 *            Imprima a matriz obtida na tela em formato de matriz. Monte dois arranjos
 *            unidimensionais a partir da matriz gerada da seguinte forma: um arranjo com
 *            os maiores elementos de cada coluna e um arranjo com os menores elementos de
 *            cada linha. Imprima os arranjos que voc� montou.
 */

int main(){

    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int mat[DIML][DIMC], maioresColunas[DIMC], menoresLinhas[DIML];

    // Alimenta��o da matriz com n�meros pseudoaleat�rios no intervalo [MIN, MAX]

    for (int i = 0; i < DIML; i++){ // percorre as linhas
        for (int j = 0; j < DIMC; j++){ // percorre as colunas
            mat[i][j] = rand() % (MAX-MIN+1) + MIN;
        }
    }

    // Impress�o da matriz gerada
    printf("Matriz\n");
    for (int i = 0; i < DIML; i++){ // percorre as linhas
        for (int j = 0; j < DIMC; j++){ // percorre as colunas
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Montagem do array com os maiores elementos de cada coluna
    for (int i = 0; i < DIMC; i++){ // percorre as colunas
        int maximo = mat[0][i]; // elemento base para compara��es seguintes
        for (int j = 0; j < DIML; j++){ // percorre as linhas
            int novoMaximo = mat[j][i];
            if (novoMaximo > maximo) maximo = novoMaximo;
        }
        maioresColunas[i] = maximo;
    }

    // Montagem do array com os menores elementos de cada linha
    for (int i = 0; i < DIML; i++){ // percorre as linhas
        int minimo = mat[i][0]; // elemento base para compara��es seguintes
        for (int j = 0; j < DIMC; j++){ // percorre as colunas
            int novoMinimo = mat[i][j];
            if (novoMinimo < minimo) minimo = novoMinimo;
        }
        menoresLinhas[i] = minimo;
    }

    // Impress�o da matriz maioresColunas
    printf("Maiores elementos de cada coluna:\n");
    for (int i = 0; i < DIMC; i++) printf("%3d", maioresColunas[i]);
    printf("\n\n");

    // Impress�o da matriz menoresLinhas
    printf("Menores elementos de cada linha:\n");
    for (int i = 0; i < DIML; i++) printf("%3d", menoresLinhas[i]);
    printf("\n");

    return 0;
}
