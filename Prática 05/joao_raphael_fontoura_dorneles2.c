#include <stdio.h>
#include <locale.h>
#include <math.h>

/*
 * Aluno: João Raphael Fontoura Dorneles (333315)
 * Enunciado: Uma função f(x) é definida pela série de potências abaixo:
 *                     x       x^3    x^5     x^7
 *            f(x) = ----- - ----- + ----- - ----- + ..., para -1.0 <= x <= 1.0
 *                    1*2     3*4     5*6     7*8
 *            Escreva um programa em C que leia um valor x do teclado e faça consistência desse
 *            valor conforme definido acima (o programa encerra se o valor lido não for válido).
 *            A seguir, calcule o valor aproximado da função nesse ponto x, parando de incluir
 *            termos quando o valor do termo a ser incluído (em módulo) for menor do que uma
 *            tolerância tol a ser lida do usuário. Imprima o valor calculado.
 */

int main(){

    setlocale(LC_ALL, "Portuguese");

    float valor, tolerancia, resultado = 0, termo;
    int operador = 1; /* o operador é inicializado com o valor 1 pois a primeira operação
                       * a ser feita é uma adição para inicializar a fórmula*/

    printf("Informe o valor de x: ");
    scanf("%f", &valor);

    if (valor >= -1 && valor <= 1){

        printf("Informe o valor da tolerância: ");
        scanf("%f", &tolerancia);

        int contador = 0;

        do{
            float numerador = pow(valor, 1+2*contador); // x elevado a P.A com n1 = 1 e r = 2

            float denpt1 = 1+contador*2; // P.A com n1 = 1 e r = 2
            float denpt2 = 2+contador*2; // P.A com n1 = 2 e r = 2
            float denominador = denpt1 * denpt2;

            termo = numerador / denominador;

            /* para evitar somar o termo ao resultado quando ele deixar de satisfazer as condições
             * caso ele não entre nessa condição, o próximo while será falso */
            if (fabs(termo) > tolerancia) resultado += operador * (termo);

            operador *= -1; // alterna entre soma/subtração a cada fração
            contador++;

        } while(fabs(termo) > tolerancia);

        printf("O resultado foi: %f", resultado);

    } else {
        printf("Valor de x fora do intervalo [-1,1].");
    }

    return 0;
}
