#include <stdio.h>
#include <locale.h>

#define TAMMAX 10

/*
 * Aluno: João Raphael Fontoura Dorneles (333315)
 * Enunciado: Inicialize um arranjo unidimensional com TAMMAX elementos via teclado (TAMMAX é
 *            um número par dado através de um #define), considerando que o usuário deve inserir
 *            obrigatoriamente a mesma quantidade de números pares e ímpares na leitura, em uma
 *            ordem qualquer. O programa deve gerar um segundo arranjo com mesmo tamanho, invertendo
 *            a ordem dos elementos da seguinte maneira: no lugar dos números pares colocar os
 *            ímpares e vice-versa, respeitando a ordem no qual foram inseridos. Ao final, o
 *            programa deve imprimir os dois vetores.
 *
 *            DICA: crie arranjos unidimensionais auxiliares, um apenas com os valores pares e outro
 *            com os valores ímpares e depois junte os dois no arranjo de saída.
 */

 int main(){

     setlocale(LC_ALL, "Portuguese");

     int numeros[TAMMAX], saida[TAMMAX], pares[TAMMAX/2], impares[TAMMAX/2];
     char tipo[TAMMAX];

     printf("Insira %d números pares e %d números ímpares (em qualquer ordem): ", TAMMAX/2, TAMMAX/2);
     for (int i = 0; i < TAMMAX; i++) scanf("%d", &numeros[i]);

     // Alimentação do array tipo, onde P é par e I é impar
     for (int i = 0; i < TAMMAX; i++) tipo[i] = numeros[i] % 2?'I':'P';

     // Alimentação do array de pares

     int contadorAux = 0; // contador auxiliar para os pares

     for (int i = 0; i < TAMMAX; i++){
            if (tipo[i] == 'P') pares[contadorAux++] = numeros[i];
     }

     // Alimentação do array de ímpares

     contadorAux = 0; // contador auxiliar para os ímpares

     for (int i = 0; i < TAMMAX; i++){
            if (tipo[i] == 'I') impares[contadorAux++] = numeros[i];
     }

     contadorAux = 0; // contador auxiliar para os pares
     int contadorAux1 = 0; // contador auxiliar para os ímpares

     // Montagem do array de saída
     for (int i = 0; i < TAMMAX; i++){
         if (tipo[i] == 'P') saida[i] = impares[contadorAux1++];
         else saida[i] = pares[contadorAux++];
     }

     // Impressão das arrays de entrada e saída
     printf("Arranjo de entrada: ");
     for (int i = 0; i < TAMMAX; i++) printf("%d ", numeros[i]);

     printf("\nArranjo de saída:   ");
     for (int i = 0; i < TAMMAX; i++) printf("%d ", saida[i]);

     return 0;
 }
