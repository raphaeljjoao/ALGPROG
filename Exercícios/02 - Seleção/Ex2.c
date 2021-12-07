#include <stdio.h>
#include <math.h>

/*
Enunciado: Fa�a um programa que l� dois valores, o primeiro servindo de indicador de opera��o e o
segundo correspondendo ao raio de uma circunfer�ncia. Caso o primeiro valor lido seja igual a
1, calcular e imprimir a �rea desta circunfer�ncia. Se o valor lido for 2, calcular e imprimir o
per�metro da circunfer�ncia. Se o valor lido for diferente destes dois valores, imprimir uma
mensagem dizendo que o indicador de opera��o foi mal fornecido.
*/

int main(){

    int operacao;
    float raio;

    printf("1 = area da circunferencia\n2 = perimetro da circunferencia\nInsira o valor da operacao: ");
    scanf("%d", &operacao);

    if (operacao != 1 && operacao != 2){
        printf("\nUm indicador de operacao nao valido foi informado.");
        return 0;
    }

    printf("Insira o raio da circunferencia: ");
    scanf("%f", &raio);

    if (operacao == 1){
        printf("\nA area da circunferencia e igual a: %.2f", M_PI*pow(raio, 2));
    }

    if (operacao == 2) {
        printf("\nO perimetro da circunferencia e igual a: %.2f", 2*M_PI*raio);
    }

    return 0;
}
