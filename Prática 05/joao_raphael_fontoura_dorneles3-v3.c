#include <stdio.h>
#include <locale.h>

/*
 * Aluno: Jo�o Raphael Fontoura Dorneles (333315)
 * Enunciado: Escreva um programa que leia n�meros inteiros do usu�rio at� que o usu�rio
 *             digite 9999. Voc� N�O sabe quantos n�meros ir�o ser fornecidos pelo usu�rio.
 *             Ao encerrar, apresente na tela o menor e o maior valor lido.
 *
 *             SOLU��O DESENVOLVIDA COM A AJUDA DO PROF. MARCELO WALTER, CHEGAMOS A CONCLUS�O
 *             DE QUE ESSA � A MAIS F�CIL E COM MENOR N�MERO DE LINHAS E VARI�VEIS
 *
 */

int main(){

    setlocale(LC_ALL, "Portuguese");

    int num, menorNum, maiorNum;

    printf("Insira um n�mero inteiro: ");
    scanf("%d", &num);

    if (num != 9999){ // o primeiro n�mero � diferente de 9999?
        menorNum = num; // base para as
        maiorNum = num; // pr�ximas compara��es

        while(num != 9999){ // caso o usu�rio ainda n�o queira encerrar
            printf("Insira um n�mero inteiro: ");
            scanf("%d", &num);

            if (num != 9999){
                if (num > maiorNum) maiorNum = num;
                if (num < menorNum) menorNum = num;
            }
        }
        printf("O menor n�mero vale %d e o maior n�mero vale %d.", menorNum, maiorNum);
    } else printf("N�o h� valores para informar.");

    return 0;
}
