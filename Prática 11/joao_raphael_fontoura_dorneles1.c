#include <stdio.h>
#include <locale.h>

#define APOSTA_TAM 6
#define MIN 1
#define MAX 80

/*
 * Aluno: João Raphael Fontoura Dorneles (333315)
 * Enunciado: Crie uma função para calcular o número de acertos para uma dada aposta da Mega Sena.
 *            Esta função receberá dois vetores de inteiros como parâmetros: um vetor com os 6
 *            números apostados e outro com os 6 números sorteados, e retornará o número de acertos
 *            do jogador (um entre 0,1,2,3,4,5 ou 6). O número de acertos é dado pela quantidade
 *            de números iguais entre a aposta e os sorteados. A função a ser implementada terá o
 *            seguinte protótipo:
 *
 *            int avalia_aposta (int *aposta, int *sorteio, int tam);
 *
 *            onde tam é o número de elementos nos dois vetores (tamanhos iguais). A sua função main
 *            deverá inicialmente ler os 6 números da aposta e os 6 números do sorteio. Os números
 *            que compõe a aposta e o sorteio estão no intervalo fechado [1,80] (faça consistência).
 *            No main ainda testar a saída da função imprimindo o número de acertos do jogador, seguido
 *            de Sena! para 6 acertos, Quina! para 5 acertos, ou Quadra! para 4 acertos.
 */

int avalia_aposta (int *aposta, int *sorteio, int tam);
void ler_dezenas(int *vet, char *mensagem);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int sorteio[APOSTA_TAM], aposta[APOSTA_TAM], acertos;

    // Leitura do sorteio e do jogo
    ler_dezenas(sorteio, "Entre com as 6 dezenas sorteadas:");
    ler_dezenas(aposta, "Entre com o jogo:");

    // Verifica e imprime a quantidade de acertos
    acertos = avalia_aposta(aposta, sorteio, APOSTA_TAM);
    printf("Número de acertos: %d\n", acertos);

    // Imprime uma mensagem especial caso o número de acertos seja maior ou igual a 4
    if (acertos >= 4){
        char acertos_str[8];

        switch(acertos){
            case 4:
                sprintf(acertos_str, "Quadra");
                break;
            case 5:
                sprintf(acertos_str, "Quina");
                break;
            case 6:
                sprintf(acertos_str, "Sena");
                break;
        }
        printf("%s!\n", acertos_str);
    }

    return 0;
}

int avalia_aposta (int *aposta, int *sorteio, int tam){
    int acertos = 0;

    for (int aposta_index = 0; aposta_index < tam; aposta_index++){ // Vetor aposta
        for (int sorteio_index = 0; sorteio_index < tam; sorteio_index++){ // Vetor sorteio
            // Se um elemento da aposta existir no vetor de sorteio, aumenta em 1 a quantidade de acertos
            if (aposta[aposta_index] == sorteio[sorteio_index]) acertos++;
        }
    }

    return acertos;
}

void ler_dezenas(int *vet, char *mensagem){
    int cont = 0;
    printf("%s\n", mensagem);

    do {
        int lido;
        scanf("%d", &lido);

        if (lido >= MIN && lido <= MAX){ // Consistência do número lido
            vet[cont] = lido;
            cont++;
        } else printf("Erro: %d não está dentro do intervalo [%d, %d].\n", lido, MIN, MAX);
    } while(cont < APOSTA_TAM);
}
