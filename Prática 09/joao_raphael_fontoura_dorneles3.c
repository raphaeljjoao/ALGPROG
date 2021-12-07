#include <stdio.h>
#include <locale.h>
#include <math.h>

/*
 * Aluno: Jo�o Raphael Fontoura Dorneles (333315)
 * Enunciado: Um algoritmo iterativo para achar a raiz c�bica de um n�mero real r � dado por:
 *            (f�rmula dispon�vel do pdf da pr�tica 9)
 *            com x0 sendo uma aproxima��o inicial fornecida pelo usu�rio.
 *            Escreva uma fun��o void que receba como entrada um n�mero real r, uma
 *            aproxima��o inicial x0 para sua raiz c�bica, e uma toler�ncia t (valor
 *            real estritamente positivo). A fun��o deve calcular (imprimindo na tela)
 *            uma aproxima��o da raiz c�bica de r de acordo com o algoritmo acima, parando
 *            quando o |x^3 - r| < t O programa principal l� os valores de x0, r e t, faz a
 *            consist�ncia de t (terminando o programa com mensagem de erro se t <= 0)
 *            e ap�s chama a fun��o solicitada.
 */

 /* Legenda
 * radicando = r
 * aprox = x0
 * tol = t
 */
void aprox_cbrt(float radicando, float aprox, float tol);

int main(){

    setlocale(LC_ALL, "Portuguese");

    float radicando, aproximacao, tolerancia;

    printf("Insira o valor de r: ");
    scanf("%f", &radicando);

    printf("Insira o valor de x0: ");
    scanf("%f", &aproximacao);

    printf("Insira a toler�ncia: ");
    scanf("%f", &tolerancia);

    aprox_cbrt(radicando, aproximacao, tolerancia);

    return 0;
}

void aprox_cbrt(float radicando, float aprox, float tol){

    float resultado = 0, x = aprox;

    // Faz a consist�ncia da toler�ncia
    if(tol > 0){
        // Para de fazer itera��es quando |x^3 - r| < t
        while(fabs(pow(x, 3) - radicando) > tol){
            resultado = x - (pow(x, 3) - radicando) / (3 * pow(x, 2));
            x = resultado;
        }
        printf("Raiz c�bica aproximada de %.4f: %f", radicando, resultado);
    } else printf("Erro: toler�ncia <= 0");
}
