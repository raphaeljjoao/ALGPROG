#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>

/*
 * Aluno: João Raphael Fontoura Dorneles (333315)
 * Enunciado: Escreva uma função tipada que receba como entrada um número real x
 *            (assuma que x é positivo, não precisa validar) e um indicador
 *            (char L, ou Q). Se o indicador for L, retornar o maior número inteiro
 *            n tal que 0+1+2+ . . .+n <= x. Se o indicador for Q, retornar o maior número
 *            inteiro n tal que 0^2 + 1^2 + 2^2 + . . . + n^2 <= x. Caso o indicador seja
 *            inválido, a função deve retornar o valor -1. Escreva o programa principal que
 *            lê o número real e o indicador, e chame a função criada.
 *            Caso o valor retornado pela função seja -1, imprima na tela uma mensagem de erro.
 *            Caso contrário, imprima o valor de n na tela (a impressão de n deve ser feita
 *            no programa principal!!!)
 */

int sequencia(float maximo, char indicador);

int main(){

    setlocale(LC_ALL, "Portuguese");

    float max;
    char indicador;
    int seq;

    printf("Entre com o valor de x: ");
    scanf("%f", &max);

    printf("Escolha o indicador (L ou Q): ");
    scanf(" %c", &indicador);

    seq = sequencia(max, indicador);

    // A função sequencia() retorna -1 quando recebe um indicador não válido
    if(seq != -1) printf("O valor de n é: %d\n", seq);
    else printf("Código inválido.\n");

    return 0;
}

int sequencia(float maximo, char indicador){
    int valor = 0, contador = 0;
    indicador = toupper(indicador); // Garante que o usuário possa digitar L ou Q sem se importar com maiúsculas ou minúsculas

    if(indicador == 'L'){
        while (valor + contador <= maximo){
            valor += contador;
            if (valor + contador <= maximo) contador++;
        }
    } else if (indicador == 'Q'){
        while (valor + pow(contador, 2) <= maximo){
            valor += pow(contador, 2);
            if (valor + pow(contador, 2) <= maximo) contador++;
        }
    } else contador = -1;
    return contador;
}
