#include <stdio.h>

// Enunciado: Dados tr�s valores, calcular e imprimir as m�dias aritm�tica e harm�nica destes valores

int main(){
    float v1, v2, v3;

    printf("=== Calculo de media harmonica ===\n\n");
    printf("Insira o primeiro valor: ");
    scanf("%f", &v1);

    printf("Insira o segundo valor: ");
    scanf("%f", &v2);

    printf("Insira o terceiro valor: ");
    scanf("%f", &v3);

    printf("\nA media aritmetica e igual a: %.2f", (v1+v2+v3)/3);
    printf("\nA media harmonica e igual a: %.2f", 3/(1/v1+1/v2+1/v3));

    return 0;
}
