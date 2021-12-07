#include <stdio.h>
#include <locale.h>
#include <math.h>

/*
 * Aluno: Jo�o Raphael Fontoura Dorneles (333315)
 * Enunciado: Em um estacionamento, o valor final a ser pago depende do tempo de utiliza��o.
 *            Os valores de cobran�a s�o fornecidos na tabela abaixo:
 *            ---------------------------------------------------------
 *            | Tempo de Perman�ncia     \ Valor a pagar              |
 *            | Primeira hora            \ R$ 15,00 (valor fixo)      |
 *            | Ap�s a primeira hora     \ R$ 2,00 por hora adicional |
 *            | Mais do que 8 horas      \ R$ 32,00 (valor fixo)      |
 *            ---------------------------------------------------------
 *            Considere que para a hora adicional, basta passar 1min que j� � considerado nova hora.
 *            Escreva um programa em C que leia o tempo de perman�ncia (em minutos) e calcule o valor
 *            a ser pago.
 */

int main(){

    setlocale(LC_ALL, "Portuguese");

    int minutos, pagar;
    float horas;

    printf("Insira o tempo de perman�ncia do ve�culo no estacionamento em minutos: ");
    scanf("%d", &minutos);

    horas = ceil(minutos / 60.0); /* os minutos s�o divididos por 60.0 (que est� intencionalmente em float, para que
                                                                         occorra a convers�o da vari�vel minutos que
                                                                         � um int) para transform�-los em horas,
                                                                         e em seguida s�o arrendados para
                                                                         cima, buscando satisfazer a condi��o
                                                                         exigida na linha 15 desse c�digo */

    if (horas == 1){
        pagar = 15;
    } else if (horas > 1 && horas <= 8){
        pagar = 15 + (horas - 1) * 2;
    } else {
        pagar = 32;
    }

    printf("O valor a ser pago � R$%d.", pagar);

    return 0;
}
