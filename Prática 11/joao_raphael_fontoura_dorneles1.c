#include <stdio.h>
#include <locale.h>

#define APOSTA_TAM 6
#define MIN 1
#define MAX 80

/*
 * Aluno: Jo�o Raphael Fontoura Dorneles (333315)
 * Enunciado: Crie uma fun��o para calcular o n�mero de acertos para uma dada aposta da Mega Sena.
 *            Esta fun��o receber� dois vetores de inteiros como par�metros: um vetor com os 6
 *            n�meros apostados e outro com os 6 n�meros sorteados, e retornar� o n�mero de acertos
 *            do jogador (um entre 0,1,2,3,4,5 ou 6). O n�mero de acertos � dado pela quantidade
 *            de n�meros iguais entre a aposta e os sorteados. A fun��o a ser implementada ter� o
 *            seguinte prot�tipo:
 *
 *            int avalia_aposta (int *aposta, int *sorteio, int tam);
 *
 *            onde tam � o n�mero de elementos nos dois vetores (tamanhos iguais). A sua fun��o main
 *            dever� inicialmente ler os 6 n�meros da aposta e os 6 n�meros do sorteio. Os n�meros
 *            que comp�e a aposta e o sorteio est�o no intervalo fechado [1,80] (fa�a consist�ncia).
 *            No main ainda testar a sa�da da fun��o imprimindo o n�mero de acertos do jogador, seguido
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
    printf("N�mero de acertos: %d\n", acertos);

    // Imprime uma mensagem especial caso o n�mero de acertos seja maior ou igual a 4
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

        if (lido >= MIN && lido <= MAX){ // Consist�ncia do n�mero lido
            vet[cont] = lido;
            cont++;
        } else printf("Erro: %d n�o est� dentro do intervalo [%d, %d].\n", lido, MIN, MAX);
    } while(cont < APOSTA_TAM);
}
