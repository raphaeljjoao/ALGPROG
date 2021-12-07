#include <stdio.h>
#include <locale.h>

/*
 * Aluno: João Raphael Fontoura Dorneles (333315)
 * Enunciado: Escreva um programa que converte temperaturas de graus centígrados para fahrenheit
 *            e vice-versa. O programa deve ter um menu de opções implementado como uma função
 *            void e mais duas funções void que calculam as conversões de temperaturas. A leitura
 *            e impressão das temperaturas é feita dentro das funções.
 */

void menu();
void celsius_para_fahrenheit(float celsius);
void fahrenheit_para_celsius(float fahrenheit);

int main(){
    setlocale(LC_ALL, "Portuguese");

    menu();

    return 0;
}

void menu(){

    int op;

    do{
        printf("Escolha uma opção:\n");
        printf("1 - Converte celsius para fahrenheit\n");
        printf("2 - Converte fahrenheit para celsius\n");
        printf("3 - Sair\n");
        printf("Opção: ");
        scanf("%d", &op);
    } while (op != 1 && op != 2 && op != 3); // Enquanto não for inserida uma operação válida

    float temperatura;

    switch(op){
        case 1:
            printf("Entre com a temperatura em celsius: ");
            scanf("%f", &temperatura);
            celsius_para_fahrenheit(temperatura);
            break;
        case 2:
            printf("Entre com a temperatura em fahrenheit: ");
            scanf("%f", &temperatura);
            fahrenheit_para_celsius(temperatura);
            break;
        case 3:
            printf("Programa encerrado.\n");
            break;
        default:
            printf("Opção inválida.\n");
    }
}

void celsius_para_fahrenheit(float celsius){
    float convertida = (celsius * 9/5) + 32;
    printf("Temperatura equivalente em fahrenheit: %.1f\n", convertida);
}

void fahrenheit_para_celsius(float fahrenheit){
    float convertida = (fahrenheit - 32) * 5/9;
    printf("Temperatura equivalente em celsius: %.1f\n", convertida);
}
