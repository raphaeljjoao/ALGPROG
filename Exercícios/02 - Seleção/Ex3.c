#include <stdio.h>

/*
Enunciado: Uma loja fornece 5% de desconto para funcion�rios e 10% de desconto para clientes especiais.
Fa�a um programa que calcule o valor total a ser pago por uma pessoa. O programa dever� ler
o valor total da compra efetuada e um c�digo que identifique se o comprador � um cliente
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
