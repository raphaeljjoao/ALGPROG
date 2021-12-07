#include <stdio.h>
#include <locale.h>

/*
 * Aluno: João Raphael Fontoura Dorneles (333315)
 * Enunciado: Elaborar um programa que identifique o mês do pagamento do IPVA de um carro,
 *            baseado na parte numérica da placa. Para isto, ler o número de uma placa de veículo
 *            como um valor inteiro (composta por exatamente quatro dígitos - ignore a parte das
 *            letras) e, através do número finalizador da placa (algarismo da casa das unidades),
 *            determinar e informar o mês de vencimento do IPVA deste veículo. Para isto, aplique a
 *            tabela ao lado (nesse comentário, abaixo).
 *            ===============================================================
 *           | Final 1 - mês (1) - Janeiro    / Final 6 - mês (6) - Junho    |
 *           | Final 2 - mês (2) - Fevereiro  / Final 7 - mês (7) - Julho    |
 *           | Final 3 - mês (3) - Março      / Final 8 - mês (8) - Agosto   |
 *           | Final 4 - mês (4) - Abril      / Final 9 - mês (9) - Setembro |
 *           | Final 5 - mês (5) - Maio       / Final 0 - mês (10) - Outubro |
 *            ===============================================================
 *
 *           Observação: só processe se o número lido da placa estiver entre 1000 e 9999. Caso
 *           contrário imprima mensagem de erro ao usuário e encerro o programa.
 */

int main(){
    setlocale(LC_ALL, "Portuguese");

    int placa;

    printf("Informe a placa do veículo: ");
    scanf("%d", &placa);

    if (placa >= 1000 && placa <= 9999){ // essa condição garante que a placa tenha 4 dígitos

        int ultimo = placa % 10; // o resto da divisão por 10 é igual ao dígito da unidade
        printf("\nMês de vencimento: ");

        switch(ultimo){
            case 1:
                printf("Janeiro");
                break;
            case 2:
                printf("Fevereiro");
                break;
            case 3:
                printf("Março");
                break;
            case 4:
                printf("Abril");
                break;
            case 5:
                printf("Maio");
                break;
            case 6:
                printf("Junho");
                break;
            case 7:
                printf("Julho");
                break;
            case 8:
                printf("Agosto");
                break;
            case 9:
                printf("Setembro");
                break;
            case 0:
                printf("Outubro");
                break;
        }

    } else {
        printf("Formato inválido. A placa deve ser composta por 4 números.");
    }

    return 0;
}
