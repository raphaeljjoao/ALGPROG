#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    float inicial, porcentagem;
    int dias;

    printf("=== Calculadora de juros compostos ===\n\n");

    printf("Insira a quantidade inicial: ");
    scanf("%f", &inicial);

    printf("Insira a porcentagem mensal de juros: ");
    scanf("%f", &porcentagem);

    printf("Insira o período em dias: ");
    scanf("%d", &dias);

    printf("\nMontante final: %.2f", inicial* pow(1 + porcentagem/100, dias/30));

    return 0;
}
