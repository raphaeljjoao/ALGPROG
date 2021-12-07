#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>

/*
 * Aluno: Jo�o Raphael Fontoura Dorneles (333315)
 * Enunciado: Escreva uma fun��o tipada que receba como entrada um n�mero real x
 *            (assuma que x � positivo, n�o precisa validar) e um indicador
 *            (char L, ou Q). Se o indicador for L, retornar o maior n�mero inteiro
 *            n tal que 0+1+2+ . . .+n <= x. Se o indicador for Q, retornar o maior n�mero
 *            inteiro n tal que 0^2 + 1^2 + 2^2 + . . . + n^2 <= x. Caso o indicador seja
 *            inv�lido, a fun��o deve retornar o valor -1. Escreva o programa principal que
 *            l� o n�mero real e o indicador, e chame a fun��o criada.
 *            Caso o valor retornado pela fun��o seja -1, imprima na tela uma mensagem de erro.
 *            Caso contr�rio, imprima o valor de n na tela (a impress�o de n deve ser feita
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

    // A fun��o sequencia() retorna -1 quando recebe um indicador n�o v�lido
    if(seq != -1) printf("O valor de n �: %d\n", seq);
    else printf("C�digo inv�lido.\n");

    return 0;
}

int sequencia(float maximo, char indicador){
    int valor = 0, contador = 0;
    indicador = toupper(indicador); // Garante que o usu�rio possa digitar L ou Q sem se importar com mai�sculas ou min�sculas

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
