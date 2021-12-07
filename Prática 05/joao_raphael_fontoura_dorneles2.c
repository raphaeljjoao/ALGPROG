#include <stdio.h>
#include <locale.h>
#include <math.h>

/*
 * Aluno: Jo�o Raphael Fontoura Dorneles (333315)
 * Enunciado: Uma fun��o f(x) � definida pela s�rie de pot�ncias abaixo:
 *                     x       x^3    x^5     x^7
 *            f(x) = ----- - ----- + ----- - ----- + ..., para -1.0 <= x <= 1.0
 *                    1*2     3*4     5*6     7*8
 *            Escreva um programa em C que leia um valor x do teclado e fa�a consist�ncia desse
 *            valor conforme definido acima (o programa encerra se o valor lido n�o for v�lido).
 *            A seguir, calcule o valor aproximado da fun��o nesse ponto x, parando de incluir
 *            termos quando o valor do termo a ser inclu�do (em m�dulo) for menor do que uma
 *            toler�ncia tol a ser lida do usu�rio. Imprima o valor calculado.
 */

int main(){

    setlocale(LC_ALL, "Portuguese");

    float valor, tolerancia, resultado = 0, termo;
    int operador = 1; /* o operador � inicializado com o valor 1 pois a primeira opera��o
                       * a ser feita � uma adi��o para inicializar a f�rmula*/

    printf("Informe o valor de x: ");
    scanf("%f", &valor);

    if (valor >= -1 && valor <= 1){

        printf("Informe o valor da toler�ncia: ");
        scanf("%f", &tolerancia);

        int contador = 0;

        do{
            float numerador = pow(valor, 1+2*contador); // x elevado a P.A com n1 = 1 e r = 2

            float denpt1 = 1+contador*2; // P.A com n1 = 1 e r = 2
            float denpt2 = 2+contador*2; // P.A com n1 = 2 e r = 2
            float denominador = denpt1 * denpt2;

            termo = numerador / denominador;

            /* para evitar somar o termo ao resultado quando ele deixar de satisfazer as condi��es
             * caso ele n�o entre nessa condi��o, o pr�ximo while ser� falso */
            if (fabs(termo) > tolerancia) resultado += operador * (termo);

            operador *= -1; // alterna entre soma/subtra��o a cada fra��o
            contador++;

        } while(fabs(termo) > tolerancia);

        printf("O resultado foi: %f", resultado);

    } else {
        printf("Valor de x fora do intervalo [-1,1].");
    }

    return 0;
}
