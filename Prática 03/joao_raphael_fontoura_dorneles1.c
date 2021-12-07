#include <stdio.h>
#include <locale.h>

/*
 * Aluno: Jo�o Raphael Fontoura Dorneles (333315)
 *
 * Enunciado: Escreva um programa que informa na tela se a pessoa pode doar sangue ou n�o.
 *            Para isso, seu programa dever� perguntar: (i) se fez tatuagem nos �ltimos 12
 *            meses (resposta �S� ou �N�); (ii) peso (iii) a idade do candidato a doador
 *            (quando se tratar de menor de idade, perguntar se possui autoriza��o, e ler
 *            uma resposta do tipo caractere, podendo ser �S� ou �N�). Baseado nas respostas
 *            a essas perguntas o programa dever� emitir a mensagem �Voc� est� apto a doar sangue�
 *            ou �Voc� n�o est� apto a doar sangue�.
 *
 *            Condi��es para ser permitida a doa��o de sangue:
 *             - (1) N�o ter feito tatuagem nos �ltimos 12 meses;
 *             - (2) Pesar no m�nimo 50kg;
 *             - (3) Ter 69 anos ou menos;
 *             - (4) Ter autoriza��o dos pais para realizer a doa��o (caso tenha menos de 16 anos)
 */

int main(){

    setlocale(LC_ALL, "Portuguese");

    char tatuagem, autorizacao = 'S'; /* a vari�vel autorizacao � inicializada com o valor 'S' e s� � alterada
    caso o usu�rio tenha menos de 16 anos, pois esse � o �nico grupo que precisa de autoriza��o e consequentemente
    pode receber um n�o ('N') */
    float peso;
    int idade;

    printf("Voc� fez tatuagem nos �ltimos 12 meses? (S/N)");
    scanf(" %c", &tatuagem);

    printf("Qual seu peso?");
    scanf("%f", &peso);

    printf("Qual sua idade?");
    scanf("%d", &idade);

    if (idade < 16){
        printf("Voc� � menor de idade. Tem autoriza��o dos pais?");
        scanf(" %c", &autorizacao);
    }

    if (tatuagem == 'N' && peso >= 50 && idade <= 69 && autorizacao == 'S'){
        printf("Parab�ns! Voc� est� apto a doar sangue.");
    } else {
        printf("Voc� n�o est� apto a doar sangue.");
    }

    return 0;
}
