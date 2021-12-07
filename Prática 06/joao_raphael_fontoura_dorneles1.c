#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#define MAX 60

/*
 * Aluno: João Raphael Fontoura Dorneles (333315)
 * Enunciado: Leia um string do usuário de comprimento máximo igual a 60 (não precisa validar) e
 *            crie outro string sem os espaços em branco. Apresente também o número de vogais
 *            presentes no string original. Imprima na tela o novo string e o número de vogais.
 */

int main(){

    setlocale(LC_ALL, "Portuguese");

    char texto[MAX+1], saida[MAX+1];
    int vogais = 0, saidaContador = 0;

    printf("Entre com uma string: ");
    if (fgets(texto, MAX, stdin) != NULL){ // Leitura da string
        texto[strlen(texto) - 1] = '\0'; // substituindo último caractere de newline por um vazio

        // Criação do array de saída
        for (int i = 0; i < strlen(texto); i++){
            if (texto[i] != ' ') saida[saidaContador++] = texto[i];
        }

        saida[saidaContador] = '\0'; // inserindo último caractere vazio para definir que o arranjo é uma string

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

        printf("String sem espaços: %s\n", saida);
        printf("Número de vogais: %d", vogais);

    } else printf("Problema com o fgets.");

    return 0;
}
