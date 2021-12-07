#include <stdio.h>
#include <locale.h>

/*
 * Aluno: João Raphael Fontoura Dorneles (333315)
 * Enunciado: O Censo Demográfico é uma pesquisa realizada pelo IBGE a cada dez anos que coleta informações
 *            sobre as condições de vida da população brasileira. Em uma rua, foram coletados dados de cinco
 *            residências. Algumas das questões abordadas foram:
 *            - Quantidade de pessoas por moradia;
 *            - Renda mensal total da residência;
 *            - Acesso à internet (sim/não).
 *
 *            Considerando essas informações e utilizando o comando for, faça um programa que leia essas informações
 *            das cinco moradias e, no final, gere um relatório contendo o número médio de pessoas por residência, a
 *            renda média mensal e o número de moradias com acesso a internet.
 */

int main(){
    setlocale(LC_ALL, "Portuguese");

    int pessoasTotal = 0, internetTotal = 0; /* inicilizando a variável para que seja possível usar o operador
                                          * de incremento mais tarde
                                          *
                                          * variável pessoasTotal ajustada em 06/09/2021, conforme observação
                                          * do monitor da disciplina na correção do exercício
                                          * "Variável acumuladora  'pessoasTotal' não inicializada.
                                          * Causa erro numa das saídas" */
    float rendaTotal;

    for (int contador = 1; contador <= 5; contador++){

        int questPessoas;
        float questRenda;
        char questInternet;

        printf("Quantas pessoas moram na residência %d? ", contador);
        scanf("%d", &questPessoas);

        printf("Qual a renda total da moradia %d? ", contador);
        scanf("%f", &questRenda);

        printf("A residência %d possui acesso a internet? (S/N) ", contador);
        scanf(" %c", &questInternet);


        pessoasTotal += questPessoas;
        rendaTotal += questRenda;

        /* caso a residência possua acesso a internet, incrementa 1 à variável contadora, que guarda
        *  o número de casas que possuem internet */
        if (questInternet == 'S'){
            internetTotal++;
        }

        printf("\n");

    }

    printf("Número médio de pessoas por residência: %.1f", pessoasTotal / 5.0); /* a divisão pelo 5.0 força que o int
                                                                                 * seja convertido para um float,
                                                                                 * garantindo que o número seja mais preciso */
    printf("\nRenda mensal média: R$ %.2f", rendaTotal / 5);
    printf("\nNúmero de moradias com acesso a internet: %d", internetTotal);

    return 0;
}
