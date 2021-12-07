#include <stdio.h>

int main(){
    int val1, val2, val3;
    int soma, produto;

    printf("Valor do primeiro termo da soma e produto: \n");
    scanf("%d", &val1);

    printf("Valor do segundo termo da soma e produto: \n");
    scanf("%d", &val2);

    printf("Valor do terceiro termo da soma e produto: \n");
    scanf("%d", &val3);

    soma = val1 + val2 + val3;
    produto = val1 * val2 * val3;

    printf("Resultado da soma: %d\n", soma);
    printf("Resultado do produto: %d\n", produto);

    return 0;
}
