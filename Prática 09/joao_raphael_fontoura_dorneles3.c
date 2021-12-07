#include <stdio.h>
#include <locale.h>
#include <math.h>

/*
 * Aluno: João Raphael Fontoura Dorneles (333315)
 * Enunciado: Um algoritmo iterativo para achar a raiz cúbica de um número real r é dado por:
 *            (fórmula disponível do pdf da prática 9)
 *            com x0 sendo uma aproximação inicial fornecida pelo usuário.
 *            Escreva uma função void que receba como entrada um número real r, uma
 *            aproximação inicial x0 para sua raiz cúbica, e uma tolerância t (valor
 *            real estritamente positivo). A função deve calcular (imprimindo na tela)
 *            uma aproximação da raiz cúbica de r de acordo com o algoritmo acima, parando
 *            quando o |x^3 - r| < t O programa principal lê os valores de x0, r e t, faz a
 *            consistência de t (terminando o programa com mensagem de erro se t <= 0)
 *            e após chama a função solicitada.
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

    printf("Insira a tolerância: ");
    scanf("%f", &tolerancia);

    aprox_cbrt(radicando, aproximacao, tolerancia);

    return 0;
}

void aprox_cbrt(float radicando, float aprox, float tol){

    float resultado = 0, x = aprox;

    // Faz a consistência da tolerância
    if(tol > 0){
        // Para de fazer iterações quando |x^3 - r| < t
        while(fabs(pow(x, 3) - radicando) > tol){
            resultado = x - (pow(x, 3) - radicando) / (3 * pow(x, 2));
            x = resultado;
        }
        printf("Raiz cúbica aproximada de %.4f: %f", radicando, resultado);
    } else printf("Erro: tolerância <= 0");
}
