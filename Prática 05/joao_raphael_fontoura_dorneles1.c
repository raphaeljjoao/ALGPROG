#include <stdio.h>
#include <locale.h>

/*
 * Aluno: Jo�o Raphael Fontoura Dorneles (333315)
 * Enunciado: Escreva um programa que leia caracteres do teclado at� que o usu�rio digite '!'.
 * O programa deve ent�o retornar o n�mero de caracteres em min�sculo e o n�mero de caracteres
 * em mai�sculo informados (voc� deve considerar apenas letras nesse c�lculo). OBS: Para descobrir
 * os caracteres mai�sculos e min�sculos voc� N�O pode testar todas as possibilidades (for�a-bruta!)
 * e nem usar a fun��o isalpha.
 */

int main(){

    setlocale(LC_ALL, "Portuguese");

    char caractere;
    int contadorMai = 0, contadorMin = 0, contadorCar = 0; /* inicializando as vari�veis para que seja poss�vel
                                                            * utilizar operadores de incremento a seguir */

    do{
        contadorCar++;
        printf("\nEntre com o %do caractere: ", contadorCar);
        scanf(" %c", &caractere);

        /* na tabela ASCII, cada char est� associado a um n�mero inteiro, sendo poss�vel fazer
         * essa compara��o com os operadores relacionais */
        if(caractere >= 'A' && caractere <= 'Z') contadorMai++;
        if(caractere >= 'a' && caractere <= 'z') contadorMin++;

    } while(caractere != '!');

    printf("\nVoc� digitou %d caracteres em min�sculo e %d em mai�sculo.", contadorMin, contadorMai);

    return 0;
}
