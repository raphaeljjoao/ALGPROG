#include <stdio.h>

/*
Enunciado: Escreva um programa que informe se existe estoque para atender um pedido feito a uma
f�brica. O programa dever� receber como entradas o n�mero de itens em estoque e o n�mero
de itens a serem fornecidos, informando como sa�da o estoque atualizado ou uma mensagem
indicando n�o haver itens suficientes em estoque para atender ao pedido
*/

int main(){

    int estoque, pedido;

    printf("Insira o numero dos itens em estoque: ");
    scanf("%d", &estoque);

    printf("Insira o numero de itens solicitados no pedido: ");
    scanf("%d", &pedido);

    if (estoque >= pedido){
        estoque -= pedido;
        printf("\nEstoque atualizado: %d itens.\nOperacao confirmada.", estoque);
        return 0;
    }

    printf("\nNao ha itens suficientes para completar o pedido. Faltam %d itens. Operacao cancelada.", pedido-estoque);

    return 0;
}
