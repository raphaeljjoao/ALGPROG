#include <stdio.h>
#include <locale.h>

/*
 * Aluno: João Raphael Fontoura Dorneles (333315)
 * Enunciado: Uma maneira de calcular PI é através da série infinita abaixo:
 *                     4     4     4     4
 *            PI = 4 - --- + --- - --- + --- - ...
 *                     3     5     7     9
 *            Vamos aproximar PI com uma série FINITA. Escreva uma programa em C que
 *            lê do usuário o número de termos que o usuário deseja aproximar PI e
 *            imprime na tela o valor de PI de acordo com a fórmula acima e o número
 *            de termos definido pelo usuário. O número mínimo de termos é 2.
 */

int main(){

    setlocale(LC_ALL, "Portuguese");

    int termos, operador = -1; /* o operador é inicializado com o valor -1 pois a primeira operação a ser
                                * feita é uma subtração sobre o valor 4*/
    float pi = 4; /* começo da fórmula */

    printf("Entre com o número de termos para o cálculo de PI: ");
    scanf("%d", &termos);

    if (termos >= 2){ /* o número mínimo de termos é 2 */
        for (int contador = 0; contador < termos - 1; contador++){
            pi += operador * (4.0 / (3+2*contador) /* P.A com n1 = 3 e r = 2*/);
            operador *= -1; // alterna entre soma/subtração a cada fração
        }

        printf("\nValor de PI com %d termos: %f", termos, pi);
    } else {
        printf("O número mínimo de termos para o cálculo de PI é 2.");
    }

    return 0;
}
