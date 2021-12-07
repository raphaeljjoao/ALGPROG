#include <stdio.h>
#include <locale.h>

/*
 * Aluno: João Raphael Fontoura Dorneles (333315)
 *
 * Enunciado: Escreva um programa que informa na tela se a pessoa pode doar sangue ou não.
 *            Para isso, seu programa deverá perguntar: (i) se fez tatuagem nos últimos 12
 *            meses (resposta ‘S’ ou ‘N’); (ii) peso (iii) a idade do candidato a doador
 *            (quando se tratar de menor de idade, perguntar se possui autorização, e ler
 *            uma resposta do tipo caractere, podendo ser ‘S’ ou ‘N’). Baseado nas respostas
 *            a essas perguntas o programa deverá emitir a mensagem “Você está apto a doar sangue”
 *            ou “Você não está apto a doar sangue”.
 *
 *            Condições para ser permitida a doação de sangue:
 *             - (1) Não ter feito tatuagem nos últimos 12 meses;
 *             - (2) Pesar no mínimo 50kg;
 *             - (3) Ter 69 anos ou menos;
 *             - (4) Ter autorização dos pais para realizer a doação (caso tenha menos de 16 anos)
 */

int main(){

    setlocale(LC_ALL, "Portuguese");

    char tatuagem, autorizacao = 'S'; /* a variável autorizacao é inicializada com o valor 'S' e só é alterada
    caso o usuário tenha menos de 16 anos, pois esse é o único grupo que precisa de autorização e consequentemente
    pode receber um não ('N') */
    float peso;
    int idade;

    printf("Você fez tatuagem nos últimos 12 meses? (S/N)");
    scanf(" %c", &tatuagem);

    printf("Qual seu peso?");
    scanf("%f", &peso);

    printf("Qual sua idade?");
    scanf("%d", &idade);

    if (idade < 16){
        printf("Você é menor de idade. Tem autorização dos pais?");
        scanf(" %c", &autorizacao);
    }

    if (tatuagem == 'N' && peso >= 50 && idade <= 69 && autorizacao == 'S'){
        printf("Parabéns! Você está apto a doar sangue.");
    } else {
        printf("Você não está apto a doar sangue.");
    }

    return 0;
}
