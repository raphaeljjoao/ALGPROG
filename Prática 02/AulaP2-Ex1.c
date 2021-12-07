#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    float largura, comprimento;
    int potencia;

    printf("== C�lculo de ilumina��o de um quarto ==\n");

    printf("Insira a largura do quarto (em metros): ");
    scanf("%f", &largura);

    printf("Insira o comprimento do quarto (em metros): ");
    scanf("%f", &comprimento);

    printf("Insira a pot�ncia das l�mpadas (em watts): ");
    scanf("%d", &potencia);

    printf("Para iluminar um quarto de %.2fm2 voc� precisa de %.0f l�mpadas de %dW.", largura*comprimento,
           (largura*comprimento*16)/potencia, potencia);

    return 0;
}
