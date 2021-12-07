#include <stdio.h>
#include <locale.h>

/*
 * Aluno: Jo�o Raphael Fontoura Dorneles (333315)
 * Enunciado: O Censo Demogr�fico � uma pesquisa realizada pelo IBGE a cada dez anos que coleta informa��es
 *            sobre as condi��es de vida da popula��o brasileira. Em uma rua, foram coletados dados de cinco
 *            resid�ncias. Algumas das quest�es abordadas foram:
 *            - Quantidade de pessoas por moradia;
 *            - Renda mensal total da resid�ncia;
 *            - Acesso � internet (sim/n�o).
 *
 *            Considerando essas informa��es e utilizando o comando for, fa�a um programa que leia essas informa��es
 *            das cinco moradias e, no final, gere um relat�rio contendo o n�mero m�dio de pessoas por resid�ncia, a
 *            renda m�dia mensal e o n�mero de moradias com acesso a internet.
 */

int main(){
    setlocale(LC_ALL, "Portuguese");

    int pessoasTotal = 0, internetTotal = 0; /* inicilizando a vari�vel para que seja poss�vel usar o operador
                                          * de incremento mais tarde
                                          *
                                          * vari�vel pessoasTotal ajustada em 06/09/2021, conforme observa��o
                                          * do monitor da disciplina na corre��o do exerc�cio
                                          * "Vari�vel acumuladora  'pessoasTotal' n�o inicializada.
                                          * Causa erro numa das sa�das" */
    float rendaTotal;

    for (int contador = 1; contador <= 5; contador++){

        int questPessoas;
        float questRenda;
        char questInternet;

        printf("Quantas pessoas moram na resid�ncia %d? ", contador);
        scanf("%d", &questPessoas);

        printf("Qual a renda total da moradia %d? ", contador);
        scanf("%f", &questRenda);

        printf("A resid�ncia %d possui acesso a internet? (S/N) ", contador);
        scanf(" %c", &questInternet);


        pessoasTotal += questPessoas;
        rendaTotal += questRenda;

        /* caso a resid�ncia possua acesso a internet, incrementa 1 � vari�vel contadora, que guarda
        *  o n�mero de casas que possuem internet */
        if (questInternet == 'S'){
            internetTotal++;
        }

        printf("\n");

    }

    printf("N�mero m�dio de pessoas por resid�ncia: %.1f", pessoasTotal / 5.0); /* a divis�o pelo 5.0 for�a que o int
                                                                                 * seja convertido para um float,
                                                                                 * garantindo que o n�mero seja mais preciso */
    printf("\nRenda mensal m�dia: R$ %.2f", rendaTotal / 5);
    printf("\nN�mero de moradias com acesso a internet: %d", internetTotal);

    return 0;
}
