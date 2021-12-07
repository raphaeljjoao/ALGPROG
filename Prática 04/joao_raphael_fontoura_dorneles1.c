#include <stdio.h>
#include <locale.h>

/*
 * Aluno: Jo�o Raphael Fontoura Dorneles (333315)
 * Enunciado: Elaborar um programa que identifique o m�s do pagamento do IPVA de um carro,
 *            baseado na parte num�rica da placa. Para isto, ler o n�mero de uma placa de ve�culo
 *            como um valor inteiro (composta por exatamente quatro d�gitos - ignore a parte das
 *            letras) e, atrav�s do n�mero finalizador da placa (algarismo da casa das unidades),
 *            determinar e informar o m�s de vencimento do IPVA deste ve�culo. Para isto, aplique a
 *            tabela ao lado (nesse coment�rio, abaixo).
 *            ===============================================================
 *           | Final 1 - m�s (1) - Janeiro    / Final 6 - m�s (6) - Junho    |
 *           | Final 2 - m�s (2) - Fevereiro  / Final 7 - m�s (7) - Julho    |
 *           | Final 3 - m�s (3) - Mar�o      / Final 8 - m�s (8) - Agosto   |
 *           | Final 4 - m�s (4) - Abril      / Final 9 - m�s (9) - Setembro |
 *           | Final 5 - m�s (5) - Maio       / Final 0 - m�s (10) - Outubro |
 *            ===============================================================
 *
 *           Observa��o: s� processe se o n�mero lido da placa estiver entre 1000 e 9999. Caso
 *           contr�rio imprima mensagem de erro ao usu�rio e encerro o programa.
 */

int main(){
    setlocale(LC_ALL, "Portuguese");

    int placa;

    printf("Informe a placa do ve�culo: ");
    scanf("%d", &placa);

    if (placa >= 1000 && placa <= 9999){ // essa condi��o garante que a placa tenha 4 d�gitos

        int ultimo = placa % 10; // o resto da divis�o por 10 � igual ao d�gito da unidade
        printf("\nM�s de vencimento: ");

        switch(ultimo){
            case 1:
                printf("Janeiro");
                break;
            case 2:
                printf("Fevereiro");
                break;
            case 3:
                printf("Mar�o");
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
        printf("Formato inv�lido. A placa deve ser composta por 4 n�meros.");
    }

    return 0;
}
