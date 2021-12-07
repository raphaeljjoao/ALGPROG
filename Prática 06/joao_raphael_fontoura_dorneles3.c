#include <stdio.h>
#include <locale.h>
#include <math.h>

#define MAXLIDOS 10

/*
 * Aluno: Jo�o Raphael Fontoura Dorneles (333315)
 * Enunciado: Escreva um programa em C que leia uma quantidade indefinida mas limitada de
 *            valores reais positivos (um valor negativo � usado para indicar o fim da entrada
 *            de dados e n�o faz parte dos valores lidos), e armazene-os em um arranjo unidimensional.
 *            O n�mero m�ximo de valores a ser lido � definido por um #define MAXLIDOS 10, mas o usu�rio
 *            pode digitar menos valores que esse m�ximo. Ap�s leitura, o programa deve calcular e
 *            imprimir na tela:
 *            a) A m�dia dos quadrados dos valores informados;
 *            b) A m�dia das ra�zes quadradas dos valores informados;
 *            c) A quantidade de valores que est�o entre as duas m�dias calculadas
 *            acima (incluindo os extremos).
 */

int main(){

    setlocale(LC_ALL, "Portuguese");

    float valor = 0, valores[MAXLIDOS], mediaQuadrado = 0, mediaRaiz = 0;
    int lidos = 0, intervalo = 0;

    printf("Entre com os valores: ");
    // Ler novos valores enquanto n�o atingir o limite e n�o receber um valor negativo
    while (lidos < MAXLIDOS && valor >= 0){
        scanf("%f", &valor);
        if (valor > 0) valores[lidos++] = valor;
    }

    // Se pelo menos um valor for lido
    if (lidos >= 1){
        // Calcular a m�dia dos quadrados
        for (int i = 0; i < lidos; i++) mediaQuadrado += pow(valores[i], 2);
        mediaQuadrado /= lidos;

        // Calcular a m�dia das ra�zes
        for (int i = 0; i < lidos; i++) mediaRaiz += sqrt(valores[i]);
        mediaRaiz /= lidos;

        // Verifica qual m�dia come�a e qual termina o intervalo para atender ao item c) do enunciado
        float mediaMenor, mediaMaior;

        if (mediaQuadrado > mediaRaiz){
            mediaMenor = mediaRaiz;
            mediaMaior = mediaQuadrado;
        } else {
            mediaMenor = mediaQuadrado;
            mediaMaior = mediaRaiz;
        }

        // Calcular a quantidade de valores entre as duas m�dias
        for (int i = 0; i < lidos; i++){
            if (valores[i] >= mediaMenor && valores[i] <= mediaMaior) intervalo++;
        }

        printf("M�dia dos quadrados: %f\n", mediaQuadrado);
        printf("M�dia das ra�zes: %f\n", mediaRaiz);
        printf("Quantidade de valores entre as duas m�dias: %d", intervalo);

    } else printf("Nenhum valor foi lido.");

    return 0;
}
