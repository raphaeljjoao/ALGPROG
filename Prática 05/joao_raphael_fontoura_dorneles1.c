#include <stdio.h>
#include <locale.h>

/*
 * Aluno: João Raphael Fontoura Dorneles (333315)
 * Enunciado: Escreva um programa que leia caracteres do teclado até que o usuário digite '!'.
 * O programa deve então retornar o número de caracteres em minúsculo e o número de caracteres
 * em maiúsculo informados (você deve considerar apenas letras nesse cálculo). OBS: Para descobrir
 * os caracteres maiúsculos e minúsculos você NÃO pode testar todas as possibilidades (força-bruta!)
 * e nem usar a função isalpha.
 */

int main(){

    setlocale(LC_ALL, "Portuguese");

    char caractere;
    int contadorMai = 0, contadorMin = 0, contadorCar = 0; /* inicializando as variáveis para que seja possível
                                                            * utilizar operadores de incremento a seguir */

    do{
        contadorCar++;
        printf("\nEntre com o %do caractere: ", contadorCar);
        scanf(" %c", &caractere);

        /* na tabela ASCII, cada char está associado a um número inteiro, sendo possível fazer
         * essa comparação com os operadores relacionais */
        if(caractere >= 'A' && caractere <= 'Z') contadorMai++;
        if(caractere >= 'a' && caractere <= 'z') contadorMin++;

    } while(caractere != '!');

    printf("\nVocê digitou %d caracteres em minúsculo e %d em maiúsculo.", contadorMin, contadorMai);

    return 0;
}
