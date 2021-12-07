#include <stdio.h>

int main(){
    float preco, taxa;

    printf("=== Conversao do valor de um produto para USD (dolar) ===\n");
    printf("Insira o valor do produto: ");
    scanf("%f", &preco);

    printf("Insira a taxa de conversao atual para dolar: ");
    scanf("%f", &taxa);

    printf("O preco original convertido para dolar e de %.2f", preco/taxa);

    return 0;
}
