#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 10

/*
 * Aluno: João Raphael Fontoura Dorneles (333315)
 * Enunciado: Implemente em C um jogo simples de adivinhar um número inteiro sorteado
 *            pelo computador. O computador irá sortear um número inteiro no intervalo
 *            [1,10]. Após o sorteio o usuário tentará adivinhar o número que foi sorteado.
 *            Caso o usuário acerte o número em menos de 5 tentativas, o programa imprime a
 *            mensagem: “Parabéns! Você acertou o número em XX tentativas” (XX corresponde ao
 *            número de tentativas). Caso o usuário não acertou, o programa deverá comparar o
 *            número sorteado com o número fornecido pelo usuário e imprimir uma mensagem adequada
 *            de acordo se o número for maior ou menor do que o valor sorteado.
 */

int main(){

    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int sorteado = rand() % (MAX-MIN+1) + MIN, chute;
    int tentativas = 0;

    do {
        if (tentativas++ < 5){ // verifica se o número de tentivas é menor que 5 e adiciona mais 1 somente após essa verificação
            printf("Digite seu chute: ");
            scanf("%d", &chute);

            if (chute >= MIN && chute <= MAX){ // se o número for válido, trata as possibilidades para o chute
                if (chute == sorteado){
                printf("Parabéns! Você acertou em %d tentativa(s)!", tentativas);
                } else if (chute > sorteado) {
                    printf("Seu chute é maior que o valor sorteado.\n");
                } else if (chute < sorteado) {
                    printf("Seu chute é menor que o valor sorteado.\n");
                }
            }
            else { /* funcionalidade adicional, não foi solicitada no enunciado:
                    * verifica se o número está dentro do intervalo [MIN, MAX]
                    */
                printf("Chute inválido! Digite um número dentro do intervalo [%d, %d].\nVocê ainda tem %d tentativa(s).\n",
                       MIN, MAX, 5 - --tentativas); /* como o número de tentativas foi incrementado no começo, agora ele é
                                                     * decrementado no mesmo momento em que é feito o cálculo de tentativas
                                                     * restante, já que uma tentativa fora do intervalo não deve
                                                     * ser contabilizada
                                                     */
            }
        } else printf("\nVocê ultrapassou o número máximo de tentativas!");
    } while(tentativas <= 5 && chute != sorteado);

    return 0;
}
