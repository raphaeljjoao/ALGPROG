#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

#define TAM 10
#define MIN 0
#define MAX 100

/*
 * Aluno: Jo�o Raphael Fontoura Dorneles (333315)
 * Enunciado: Implemente uma fun��o substitui_menor que recebe como par�metro um vetor
 *            de inteiros, o tamanho do vetor, e um valor inteiro x. Essa fun��o dever�
 *            encontrar o menor elemento do vetor, e substitu�-lo por x, caso este valor
 *            encontrado seja maior que x. Caso contr�rio, nada deve ser alterado. A fun��o
 *            dever� retornar um inteiro (1/0) para indicar se houve (valor retorno 1) ou n�o
 *            (valor retorno 0) substitui��o.
 *
 *            Na main, gere um vetor aleat�rio de 10 posi��es, usando a fun��o rand()e imprima
 *            na tela esse vetor. Assuma os valores no intervalo fechado [0, 100] para a gera��o
 *            de n�meros aleat�rios. Lembre-se de usar a fun��o srand para reinicializar as sequ�ncias
 *            de n�meros aleat�rios. A seguir leia o valor de x, chame a fun��o substitui_menor,
 *            e imprima na tela mensagem informando se houve substitui��o ou n�o. Em caso positivo,
 *            imprima o vetor atualizado. DICA: na aula 13 vimos n�meros aleat�rios.
 */

int substitui_menor(int *vetor, int tam, int troca);

int main(){
    setlocale(LC_ALL, "Portuguese");

    // Definica��o da semente para gera��o de n�meros pseudoaleat�rios
    long int seed = time(NULL);
    srand(seed);

    int vet[TAM], substituicao, alteracao;

    // Preenchimento do vetor com n�meros pseudoaleat�rios
    for (int i = 0; i < TAM; i++) vet[i] = rand() % (MAX-MIN+1) + MIN;

    // Impress�o do vetor gerado
    printf("Vetor gerado:\n");
    for (int i = 0; i < TAM; i++) printf("%2d ", vet[i]);
    printf("\n");

    // Leitura do valor de x
    printf("Entre com o valor de x: ");
    scanf("%d", &substituicao);

    alteracao = substitui_menor(vet, TAM, substituicao);

    // Se houve altera��o no vetor ap�s a chamada da fun��o
    if(alteracao){
        printf("Foi feita a troca!\n");
        // Impress�o do vetor alterado
        for (int i = 0; i < TAM; i++) printf("%2d ", vet[i]);
        printf("\n");
    } else printf("N�o foi feita a troca.\n");

    return 0;
}

int substitui_menor(int *vetor, int tam, int troca){
    int alteracao = 0, menor_index = 0, menor;

    // Busca pelo �ndice do menor menor
    for (int i = 0; i < tam; i++){
        if (vetor[i] < vetor[menor_index]) menor_index = i;
    }

    menor = vetor[menor_index];

    // O menor n�mero do vetor s� � trocado se o n�mero recebido para troca for menor que ele
    if (troca < menor){
        vetor[menor_index] = troca;
        alteracao = 1;
    }
    return alteracao;
}
