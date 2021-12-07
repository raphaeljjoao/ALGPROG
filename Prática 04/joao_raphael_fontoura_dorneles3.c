#include <stdio.h>
#include <locale.h>

/*
 * Aluno: Jo�o Raphael Fontoura Dorneles (333315)
 * Enunciado: Uma maneira de calcular PI � atrav�s da s�rie infinita abaixo:
 *                     4     4     4     4
 *            PI = 4 - --- + --- - --- + --- - ...
 *                     3     5     7     9
 *            Vamos aproximar PI com uma s�rie FINITA. Escreva uma programa em C que
 *            l� do usu�rio o n�mero de termos que o usu�rio deseja aproximar PI e
 *            imprime na tela o valor de PI de acordo com a f�rmula acima e o n�mero
 *            de termos definido pelo usu�rio. O n�mero m�nimo de termos � 2.
 */

int main(){

    setlocale(LC_ALL, "Portuguese");

    int termos, operador = -1; /* o operador � inicializado com o valor -1 pois a primeira opera��o a ser
                                * feita � uma subtra��o sobre o valor 4*/
    float pi = 4; /* come�o da f�rmula */

    printf("Entre com o n�mero de termos para o c�lculo de PI: ");
    scanf("%d", &termos);

    if (termos >= 2){ /* o n�mero m�nimo de termos � 2 */
        for (int contador = 0; contador < termos - 1; contador++){
            pi += operador * (4.0 / (3+2*contador) /* P.A com n1 = 3 e r = 2*/);
            operador *= -1; // alterna entre soma/subtra��o a cada fra��o
        }

        printf("\nValor de PI com %d termos: %f", termos, pi);
    } else {
        printf("O n�mero m�nimo de termos para o c�lculo de PI � 2.");
    }

    return 0;
}
