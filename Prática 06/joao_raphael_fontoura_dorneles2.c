#include <stdio.h>
#include <locale.h>

#define TAMMAX 10

/*
 * Aluno: Jo�o Raphael Fontoura Dorneles (333315)
 * Enunciado: Inicialize um arranjo unidimensional com TAMMAX elementos via teclado (TAMMAX �
 *            um n�mero par dado atrav�s de um #define), considerando que o usu�rio deve inserir
 *            obrigatoriamente a mesma quantidade de n�meros pares e �mpares na leitura, em uma
 *            ordem qualquer. O programa deve gerar um segundo arranjo com mesmo tamanho, invertendo
 *            a ordem dos elementos da seguinte maneira: no lugar dos n�meros pares colocar os
 *            �mpares e vice-versa, respeitando a ordem no qual foram inseridos. Ao final, o
 *            programa deve imprimir os dois vetores.
 *
 *            DICA: crie arranjos unidimensionais auxiliares, um apenas com os valores pares e outro
 *            com os valores �mpares e depois junte os dois no arranjo de sa�da.
 */

 int main(){

     setlocale(LC_ALL, "Portuguese");

     int numeros[TAMMAX], saida[TAMMAX], pares[TAMMAX/2], impares[TAMMAX/2];
     char tipo[TAMMAX];

     printf("Insira %d n�meros pares e %d n�meros �mpares (em qualquer ordem): ", TAMMAX/2, TAMMAX/2);
     for (int i = 0; i < TAMMAX; i++) scanf("%d", &numeros[i]);

     // Alimenta��o do array tipo, onde P � par e I � impar
     for (int i = 0; i < TAMMAX; i++) tipo[i] = numeros[i] % 2?'I':'P';

     // Alimenta��o do array de pares

     int contadorAux = 0; // contador auxiliar para os pares

     for (int i = 0; i < TAMMAX; i++){
            if (tipo[i] == 'P') pares[contadorAux++] = numeros[i];
     }

     // Alimenta��o do array de �mpares

     contadorAux = 0; // contador auxiliar para os �mpares

     for (int i = 0; i < TAMMAX; i++){
            if (tipo[i] == 'I') impares[contadorAux++] = numeros[i];
     }

     contadorAux = 0; // contador auxiliar para os pares
     int contadorAux1 = 0; // contador auxiliar para os �mpares

     // Montagem do array de sa�da
     for (int i = 0; i < TAMMAX; i++){
         if (tipo[i] == 'P') saida[i] = impares[contadorAux1++];
         else saida[i] = pares[contadorAux++];
     }

     // Impress�o das arrays de entrada e sa�da
     printf("Arranjo de entrada: ");
     for (int i = 0; i < TAMMAX; i++) printf("%d ", numeros[i]);

     printf("\nArranjo de sa�da:   ");
     for (int i = 0; i < TAMMAX; i++) printf("%d ", saida[i]);

     return 0;
 }
