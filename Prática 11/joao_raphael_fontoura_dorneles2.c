#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

#define TAM 10
#define MIN 0
#define MAX 100

/*
 * Aluno: João Raphael Fontoura Dorneles (333315)
 * Enunciado: Implemente uma função substitui_menor que recebe como parâmetro um vetor
 *            de inteiros, o tamanho do vetor, e um valor inteiro x. Essa função deverá
 *            encontrar o menor elemento do vetor, e substituí-lo por x, caso este valor
 *            encontrado seja maior que x. Caso contrário, nada deve ser alterado. A função
 *            deverá retornar um inteiro (1/0) para indicar se houve (valor retorno 1) ou não
 *            (valor retorno 0) substituição.
 *
 *            Na main, gere um vetor aleatório de 10 posições, usando a função rand()e imprima
 *            na tela esse vetor. Assuma os valores no intervalo fechado [0, 100] para a geração
 *            de números aleatórios. Lembre-se de usar a função srand para reinicializar as sequências
 *            de números aleatórios. A seguir leia o valor de x, chame a função substitui_menor,
 *            e imprima na tela mensagem informando se houve substituição ou não. Em caso positivo,
 *            imprima o vetor atualizado. DICA: na aula 13 vimos números aleatórios.
 */

int substitui_menor(int *vetor, int tam, int troca);

int main(){
    setlocale(LC_ALL, "Portuguese");

    // Definicação da semente para geração de números pseudoaleatórios
    long int seed = time(NULL);
    srand(seed);

    int vet[TAM], substituicao, alteracao;

    // Preenchimento do vetor com números pseudoaleatórios
    for (int i = 0; i < TAM; i++) vet[i] = rand() % (MAX-MIN+1) + MIN;

    // Impressão do vetor gerado
    printf("Vetor gerado:\n");
    for (int i = 0; i < TAM; i++) printf("%2d ", vet[i]);
    printf("\n");

    // Leitura do valor de x
    printf("Entre com o valor de x: ");
    scanf("%d", &substituicao);

    alteracao = substitui_menor(vet, TAM, substituicao);

    // Se houve alteração no vetor após a chamada da função
    if(alteracao){
        printf("Foi feita a troca!\n");
        // Impressão do vetor alterado
        for (int i = 0; i < TAM; i++) printf("%2d ", vet[i]);
        printf("\n");
    } else printf("Não foi feita a troca.\n");

    return 0;
}

int substitui_menor(int *vetor, int tam, int troca){
    int alteracao = 0, menor_index = 0, menor;

    // Busca pelo índice do menor menor
    for (int i = 0; i < tam; i++){
        if (vetor[i] < vetor[menor_index]) menor_index = i;
    }

    menor = vetor[menor_index];

    // O menor número do vetor só é trocado se o número recebido para troca for menor que ele
    if (troca < menor){
        vetor[menor_index] = troca;
        alteracao = 1;
    }
    return alteracao;
}
