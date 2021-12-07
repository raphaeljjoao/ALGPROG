#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    float raio, lado;

    printf("== Maior quadrado inscrito em um círculo ==\n");

    printf("Insira o raio do círculo: ");
    scanf("%f", &raio);

    lado = raio * sqrt(2);

    printf("Perímetro do maior quadrado: %.2f\n", lado * 4);
    printf("Área do maior quadrado: %.2f\n", pow(lado, 2));

    return 0;
}
