#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#define MAX 60

/*
 * Aluno: Jo�o Raphael Fontoura Dorneles (333315)
 * Enunciado: Leia um string do usu�rio de comprimento m�ximo igual a 60 (n�o precisa validar) e
 *            crie outro string sem os espa�os em branco. Apresente tamb�m o n�mero de vogais
 *            presentes no string original. Imprima na tela o novo string e o n�mero de vogais.
 */

int main(){

    setlocale(LC_ALL, "Portuguese");

    char texto[MAX+1], saida[MAX+1];
    int vogais = 0, saidaContador = 0;

    printf("Entre com uma string: ");
    if (fgets(texto, MAX, stdin) != NULL){ // Leitura da string
        texto[strlen(texto) - 1] = '\0'; // substituindo �ltimo caractere de newline por um vazio

        // Cria��o do array de sa�da
        for (int i = 0; i < strlen(texto); i++){
            if (texto[i] != ' ') saida[saidaContador++] = texto[i];
        }

        saida[saidaContador] = '\0'; // inserindo �ltimo caractere vazio para definir que o arranjo � uma string

        // Calcular quantidade de vogais

        for (int i = 0; i < strlen(texto); i++){
            switch (toupper(saida[i])){
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U': vogais++;
            }
        }

        printf("String sem espa�os: %s\n", saida);
        printf("N�mero de vogais: %d", vogais);

    } else printf("Problema com o fgets.");

    return 0;
}
