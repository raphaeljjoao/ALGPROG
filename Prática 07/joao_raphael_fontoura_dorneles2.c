#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 10

/*
 * Aluno: Jo�o Raphael Fontoura Dorneles (333315)
 * Enunciado: Implemente em C um jogo simples de adivinhar um n�mero inteiro sorteado
 *            pelo computador. O computador ir� sortear um n�mero inteiro no intervalo
 *            [1,10]. Ap�s o sorteio o usu�rio tentar� adivinhar o n�mero que foi sorteado.
 *            Caso o usu�rio acerte o n�mero em menos de 5 tentativas, o programa imprime a
 *            mensagem: �Parab�ns! Voc� acertou o n�mero em XX tentativas� (XX corresponde ao
 *            n�mero de tentativas). Caso o usu�rio n�o acertou, o programa dever� comparar o
 *            n�mero sorteado com o n�mero fornecido pelo usu�rio e imprimir uma mensagem adequada
 *            de acordo se o n�mero for maior ou menor do que o valor sorteado.
 */

int main(){

    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int sorteado = rand() % (MAX-MIN+1) + MIN, chute;
    int tentativas = 0;

    do {
        if (tentativas++ < 5){ // verifica se o n�mero de tentivas � menor que 5 e adiciona mais 1 somente ap�s essa verifica��o
            printf("Digite seu chute: ");
            scanf("%d", &chute);

            if (chute >= MIN && chute <= MAX){ // se o n�mero for v�lido, trata as possibilidades para o chute
                if (chute == sorteado){
                printf("Parab�ns! Voc� acertou em %d tentativa(s)!", tentativas);
                } else if (chute > sorteado) {
                    printf("Seu chute � maior que o valor sorteado.\n");
                } else if (chute < sorteado) {
                    printf("Seu chute � menor que o valor sorteado.\n");
                }
            }
            else { /* funcionalidade adicional, n�o foi solicitada no enunciado:
                    * verifica se o n�mero est� dentro do intervalo [MIN, MAX]
                    */
                printf("Chute inv�lido! Digite um n�mero dentro do intervalo [%d, %d].\nVoc� ainda tem %d tentativa(s).\n",
                       MIN, MAX, 5 - --tentativas); /* como o n�mero de tentativas foi incrementado no come�o, agora ele �
                                                     * decrementado no mesmo momento em que � feito o c�lculo de tentativas
                                                     * restante, j� que uma tentativa fora do intervalo n�o deve
                                                     * ser contabilizada
                                                     */
            }
        } else printf("\nVoc� ultrapassou o n�mero m�ximo de tentativas!");
    } while(tentativas <= 5 && chute != sorteado);

    return 0;
}
