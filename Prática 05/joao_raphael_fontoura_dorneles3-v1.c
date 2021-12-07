#include <stdio.h>
#include <locale.h>

/*
 * Aluno: João Raphael Fontoura Dorneles (333315)
 * Enunciado: Escreva um programa que leia números inteiros do usuário até que o usuário
 *             digite 9999. Você NÃO sabe quantos números irão ser fornecidos pelo usuário.
 *             Ao encerrar, apresente na tela o menor e o maior valor lido.
 *
 *             SOLUÇÃO MAIS TRABALHOSA COMPARADA COM AS DEMAIS, PODERIA SER MAIS SIMPLES
 *
 */

int main(){

    setlocale(LC_ALL, "Portuguese");

    int contador = 0, num, menorNum, maiorNum;
    int *ptrMenor = NULL, *ptrMaior = NULL;

    do{
        printf("Insira um número inteiro: ");
        scanf("%d", &num);

        if (num != 9999){ // caso o usuário ainda não queira encerrar
                ptrMenor = &menorNum;
                ptrMaior = &maiorNum;

            if (contador == 0){ // o primeiro número inserido é a base para as comparações que virão
                menorNum = num;
                maiorNum = num;
            }

            contador++;

            if (num > maiorNum) maiorNum = num;
            if (num < menorNum) menorNum = num;
        }

    } while(num != 9999);

    if(ptrMaior != NULL && ptrMenor != NULL) printf("O menor número vale %d e o maior número vale %d.", menorNum, maiorNum);
    else printf("Não há valores para informar.");

    return 0;
}
