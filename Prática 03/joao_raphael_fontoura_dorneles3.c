#include <stdio.h>
#include <locale.h>
#include <math.h>

/*
 * Aluno: João Raphael Fontoura Dorneles (333315)
 * Enunciado: Faça um programa que leia os coeficientes de uma equação do segundo grau.
 *             Condições:
 *             (1) O coeficiente a tem de ser diferente de zero;
 *             (2) Se delta < 0, não existe raiz real;
 *             (3) Se delta = 0, há uma única raiz.
 *             (4) Se delta > 0, há duas raízes reais;
 */

int main(){

    setlocale(LC_ALL, "Portuguese");

    float a, b, c, delta, r1, r2;

    printf("Entre com os valores dos coeficientes: ");
    scanf("%f%f%f", &a, &b, &c);

    delta = pow(b, 2) - 4 * a * c;

    if (a == 0){
        printf("Não é equação do segundo grau.");
    } else if (delta < 0){
        printf("Não existe raiz real.");
    } else if (delta == 0){
        printf("Raiz única: %f", -b /(2 * a));
    } else {
        r1 = (-b + sqrt(delta)) / (2 * a);
        r2 = (-b - sqrt(delta)) / (2 * a);
        printf("Duas raízes reais: r1=%f r2=%f", r1, r2);
    }

    return 0;
}
