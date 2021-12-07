#include <stdio.h>

/*
Enunciado: Uma loja fornece 5% de desconto para funcionários e 10% de desconto para clientes especiais.
Faça um programa que calcule o valor total a ser pago por uma pessoa. O programa deverá ler
o valor total da compra efetuada e um código que identifique se o comprador é um cliente
comum ou um dos dois tipos de clientes que recebem desconto
*/

int main(){

    float total;
    char situacao;

    printf("Insira o valor total da compra: ");
    scanf("%f", &total);

    printf("C = CLIENTE\nF = FUNCIONARIO\nV = VIP (especial)\nInsira a situacao do cliente: ");
    scanf("%c", &situacao);

    return 0;
}
