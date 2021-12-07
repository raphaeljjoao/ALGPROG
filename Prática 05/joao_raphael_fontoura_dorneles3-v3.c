#include <stdio.h>
#include <locale.h>

/*
 * Aluno: João Raphael Fontoura Dorneles (333315)
 * Enunciado: Escreva um programa que leia números inteiros do usuário até que o usuário
 *             digite 9999. Você NÃO sabe quantos números irão ser fornecidos pelo usuário.
 *             Ao encerrar, apresente na tela o menor e o maior valor lido.
 *
 *             SOLUÇÃO DESENVOLVIDA COM A AJUDA DO PROF. MARCELO WALTER, CHEGAMOS A CONCLUSÃO
 *             DE QUE ESSA É A MAIS FÁCIL E COM MENOR NÚMERO DE LINHAS E VARIÁVEIS
 *
 */

int main(){

    setlocale(LC_ALL, "Portuguese");

    int num, menorNum, maiorNum;

    printf("Insira um número inteiro: ");
    scanf("%d", &num);

    if (num != 9999){ // o primeiro número é diferente de 9999?
        menorNum = num; // base para as
        maiorNum = num; // próximas comparações

        while(num != 9999){ // caso o usuário ainda não queira encerrar
            printf("Insira um número inteiro: ");
            scanf("%d", &num);

            if (num != 9999){
                if (num > maiorNum) maiorNum = num;
                if (num < menorNum) menorNum = num;
            }
        }
        printf("O menor número vale %d e o maior número vale %d.", menorNum, maiorNum);
    } else printf("Não há valores para informar.");

    return 0;
}
