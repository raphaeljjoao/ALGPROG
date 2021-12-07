#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#define TEXTO_TAM 101

/*
 * Aluno: Jo�o Raphael Fontoura Dorneles (333315)
 * Enunciado: Escreva um programa que l� uma string do usu�rio e imprime na tela o n�mero
 *            de ocorr�ncias de cada uma das vogais. O seu programa dever� ter necessariamente
 *            uma fun��o void com o seguinte prot�tipo:
 *
 *            void conta_vogais(char texto[], int num_vogais[5]);
 *
 *            A fun��o acima recebe a string a ser analisado e armazena no vetor num_vogais o
 *            n�mero de ocorr�ncias de cada uma das vogais poss�veis. Voc� deve contar mai�sculas
 *            iguais � min�sculas. A impress�o da contagem � feita no programa principal.
 */

void conta_vogais(char texto[], int num_vogais[5]);

int main(){
    setlocale(LC_ALL, "Portuguese");

    char vogais[5] = {'a', 'e', 'i', 'o', 'u'}, str[TEXTO_TAM+1];
    int num_vogais[5];

    // Leitura do texto
    printf("Entre com o texto: ");
    fgets(str, TEXTO_TAM+1, stdin);
    str[strlen(str) - 1] = '\0';

    conta_vogais(str, num_vogais);

    // Impress�o das contagens
    for (int i = 0; i < 5; i++) printf("A vogal %c aparece %d %s.\n", vogais[i], num_vogais[i],
                                       num_vogais[i]==1?"vez":"vezes");

    return 0;
}

void conta_vogais(char texto[], int num_vogais[5]){
    int tam =  strlen(texto);

    // Inicializa��o da contagem de vogais
    num_vogais[0] = 0;
    num_vogais[1] = 0;
    num_vogais[2] = 0;
    num_vogais[3] = 0;
    num_vogais[4] = 0;

    for (int i = 0; i < tam; i++){
        char caractere = tolower(texto[i]);
        switch(caractere){
            case 'a':
                num_vogais[0]++;
                break;
            case 'e':
                num_vogais[1]++;
                break;
            case 'i':
                num_vogais[2]++;
                break;
            case 'o':
                num_vogais[3]++;
                break;
            case 'u':
                num_vogais[4]++;
                break;
        }
    }
}
