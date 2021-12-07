#include <stdio.h>
#include <locale.h>
#include <math.h>

/*
 * Aluno: João Raphael Fontoura Dorneles (333315)
 * Enunciado: Em um estacionamento, o valor final a ser pago depende do tempo de utilização.
 *            Os valores de cobrança são fornecidos na tabela abaixo:
 *            ---------------------------------------------------------
 *            | Tempo de Permanência     \ Valor a pagar              |
 *            | Primeira hora            \ R$ 15,00 (valor fixo)      |
 *            | Após a primeira hora     \ R$ 2,00 por hora adicional |
 *            | Mais do que 8 horas      \ R$ 32,00 (valor fixo)      |
 *            ---------------------------------------------------------
 *            Considere que para a hora adicional, basta passar 1min que já é considerado nova hora.
 *            Escreva um programa em C que leia o tempo de permanência (em minutos) e calcule o valor
 *            a ser pago.
 */

int main(){

    setlocale(LC_ALL, "Portuguese");

    int minutos, pagar;
    float horas;

    printf("Insira o tempo de permanência do veículo no estacionamento em minutos: ");
    scanf("%d", &minutos);

    horas = ceil(minutos / 60.0); /* os minutos são divididos por 60.0 (que está intencionalmente em float, para que
                                                                         occorra a conversão da variável minutos que
                                                                         é um int) para transformá-los em horas,
                                                                         e em seguida são arrendados para
                                                                         cima, buscando satisfazer a condição
                                                                         exigida na linha 15 desse código */

    if (horas == 1){
        pagar = 15;
    } else if (horas > 1 && horas <= 8){
        pagar = 15 + (horas - 1) * 2;
    } else {
        pagar = 32;
    }

    printf("O valor a ser pago é R$%d.", pagar);

    return 0;
}
