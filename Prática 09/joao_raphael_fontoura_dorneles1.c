#include <stdio.h>
#include <locale.h>

/*
 * Aluno: Jo�o Raphael Fontoura Dorneles (333315)
 * Enunciado: Escreva um programa que converte temperaturas de graus cent�grados para fahrenheit
 *            e vice-versa. O programa deve ter um menu de op��es implementado como uma fun��o
 *            void e mais duas fun��es void que calculam as convers�es de temperaturas. A leitura
 *            e impress�o das temperaturas � feita dentro das fun��es.
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
        printf("Escolha uma op��o:\n");
        printf("1 - Converte celsius para fahrenheit\n");
        printf("2 - Converte fahrenheit para celsius\n");
        printf("3 - Sair\n");
        printf("Op��o: ");
        scanf("%d", &op);
    } while (op != 1 && op != 2 && op != 3); // Enquanto n�o for inserida uma opera��o v�lida

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
            printf("Op��o inv�lida.\n");
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
