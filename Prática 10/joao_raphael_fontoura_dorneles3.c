#include <stdio.h>
#include <locale.h>
#include <ctype.h>

#define NNOTAS 5

/*
 * Aluno: Jo�o Raphael Fontoura Dorneles (333315)
 * Enunciado: Escreva um programa que apresenta na tela a m�dia e o conceito de um aluno numa disciplina.
 *            O conceito � dado conforme a tabela abaixo.
 *            ===========================
 *            =    M�dia    = Conceito  =
 *            =  85 a 100   =    A      =
 *            =  70 a 84    =    B      =
 *            =  50 a 69    =    C      =
 *            =  0 a 49     =    D      =
 *            ===========================
 *            O programa dever� ler 4 provas mensais no valor m�ximo de 20 pontos e uma prova final no valor
 *            m�ximo de 40 pontos (n�o precisa fazer consist�ncia das notas). A m�dia do aluno � obtida somando-se
 *            as tr�s melhores notas dentre as 4 provas mensais, mais a prova final.
 *
 *            O seu programa dever� ter uma fun��o tipada que recebe as 4 provas mensais e a nota final e retorna
 *            a m�dia bem como o conceito do aluno (sugest�o: uma fun��o tipada char que retorna o conceito, com
 *            a m�dia retornada por refer�ncia). Al�m disso, utilize a fun��o char le_s_n() que vimos em aula
 *            (aula 17) para implementar a pergunta se o usu�rio deseja calcular o conceito para outro aluno.
 *            A leitura das notas e impress�o da m�dia e conceito dever�o ser feitos no main.
 */

char media_conceito(int notas[], int *media); // Salva a m�dia (de acordo com o enunciado) do vetor NOTAS no conte�do do ponteiro M�DIA
                                              // e retorna o conceito equivalente a m�dia calculada
void selection_sort(int vet[], int tam); // Ordena um vetor de n�meros inteiros de forma crescente
char le_s_n(); // Retorna a letra mai�scula s ou n

int main(){
    setlocale(LC_ALL, "Portuguese");

    int notas[NNOTAS], media;
    char conceito;

    do {
        // Leitura das notas
        printf("Entre com as 5 notas (4 provas mensais e uma prova final): ");
        for (int i = 0; i < NNOTAS; i++) scanf("%d", &notas[i]);

        // Impress�o da m�dia e do conceito
        conceito = media_conceito(notas, &media);
        printf("Sua m�dia � %d e seu conceito � %c.\n", media, conceito);
    } while(le_s_n() == 'S');

    return 0;
}

char media_conceito(int notas[], int *media){
    char conceito;

    selection_sort(notas, NNOTAS - 1); // Ordena todas as notas menos a �ltima (nota final)
    *media = notas[NNOTAS-1] + notas[NNOTAS-2] + notas[NNOTAS-3] + notas[NNOTAS-4];

    if(*media >= 85 && *media <= 100) conceito = 'A';
    if(*media >= 70 && *media < 85) conceito = 'B';
    if(*media >= 50 && *media < 70) conceito = 'C';
    if(*media >= 0 && *media < 50) conceito = 'D';

    return conceito;
}

void selection_sort(int vet[], int tam){
     // Selection Sort Method - Aula 12
    for (int pos = 0; pos < tam - 1; pos++){ // Posi��o a ser ordenada
        int pos_min = pos;
        for (int i = pos + 1; i < tam; i++){ // Busca o menor valor a seguir
            if (vet[i] < vet[pos_min]) pos_min = i; // Se o elemento daquela itera��o da busca for menor que o elemento m�nimo,
                                                    // ent�o a posi��o do m�nimo � igual a posi��o da itera��o da busca
        }

        if (pos != pos_min){ // Faz a troca se o elemento n�o estiver na posi��o correta
            int aux = vet[pos];
            vet[pos] = vet[pos_min];
            vet[pos_min] = aux;
        }
    }
 }

char le_s_n(){
    char s_n;
    do{
        printf("Mais um (S /N)? ");
        scanf(" %c", &s_n);
        s_n = toupper(s_n);
        if(s_n != 'S' && s_n != 'N') printf("Resposta inv�lida. ");
    } while (s_n != 'S' && s_n != 'N');
    return s_n;
}
