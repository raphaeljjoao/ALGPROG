#include <stdio.h>
#include <locale.h>
#include <math.h>

#define MAXLIDOS 10

/*
 * Aluno: João Raphael Fontoura Dorneles (333315)
 * Enunciado: Escreva um programa em C que leia uma quantidade indefinida mas limitada de
 *            valores reais positivos (um valor negativo é usado para indicar o fim da entrada
 *            de dados e não faz parte dos valores lidos), e armazene-os em um arranjo unidimensional.
 *            O número máximo de valores a ser lido é definido por um #define MAXLIDOS 10, mas o usuário
 *            pode digitar menos valores que esse máximo. Após leitura, o programa deve calcular e
 *            imprimir na tela:
 *            a) A média dos quadrados dos valores informados;
 *            b) A média das raízes quadradas dos valores informados;
 *            c) A quantidade de valores que estão entre as duas médias calculadas
 *            acima (incluindo os extremos).
 */

int main(){

    setlocale(LC_ALL, "Portuguese");

    float valor = 0, valores[MAXLIDOS], mediaQuadrado = 0, mediaRaiz = 0;
    int lidos = 0, intervalo = 0;

    printf("Entre com os valores: ");
    // Ler novos valores enquanto não atingir o limite e não receber um valor negativo
    while (lidos < MAXLIDOS && valor >= 0){
        scanf("%f", &valor);
        if (valor > 0) valores[lidos++] = valor;
    }

    // Se pelo menos um valor for lido
    if (lidos >= 1){
        // Calcular a média dos quadrados
        for (int i = 0; i < lidos; i++) mediaQuadrado += pow(valores[i], 2);
        mediaQuadrado /= lidos;

        // Calcular a média das raízes
        for (int i = 0; i < lidos; i++) mediaRaiz += sqrt(valores[i]);
        mediaRaiz /= lidos;

        // Verifica qual média começa e qual termina o intervalo para atender ao item c) do enunciado
        float mediaMenor, mediaMaior;

        if (mediaQuadrado > mediaRaiz){
            mediaMenor = mediaRaiz;
            mediaMaior = mediaQuadrado;
        } else {
            mediaMenor = mediaQuadrado;
            mediaMaior = mediaRaiz;
        }

        // Calcular a quantidade de valores entre as duas médias
        for (int i = 0; i < lidos; i++){
            if (valores[i] >= mediaMenor && valores[i] <= mediaMaior) intervalo++;
        }

        printf("Média dos quadrados: %f\n", mediaQuadrado);
        printf("Média das raízes: %f\n", mediaRaiz);
        printf("Quantidade de valores entre as duas médias: %d", intervalo);

    } else printf("Nenhum valor foi lido.");

    return 0;
}
