#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    float raio, lado;

    printf("== Maior quadrado inscrito em um c�rculo ==\n");

    printf("Insira o raio do c�rculo: ");
    scanf("%f", &raio);

    lado = raio * sqrt(2);

    printf("Per�metro do maior quadrado: %.2f\n", lado * 4);
    printf("�rea do maior quadrado: %.2f\n", pow(lado, 2));

    return 0;
}
