#include <stdio.h>
#include <locale.h>

#define MAX 20

/*
 * Aluno: Jo�o Raphael Fontoura Dorneles (333315)
 * Enunciado: Escreva um programa que encontra o vetor intersec��o entre 2 vetores
 *            de inteiros lidos do usu�rio. O n�mero m�ximo de elementos em cada
 *            vetor � 20. Seu programa deve ter uma fun��o void com o seguinte prot�tipo:
 *
 *            void calc_intersec(int a[], int na, int b[], int nb, int c[], int *nc);
 *
 *            Esta fun��o recebe os vetores a e b, o n�mero de elementos de a (na) e b (nb),
 *            retornando em c o vetor intersec��o e na vari�vel nc o n�mero de elementos
 *            do vetor c. Os vetores podem ter um n�mero diferente de elementos, mas considere
 *            que n�o h� elementos repetidos em cada um dos vetores de entrada.
 *
 *            Observa��o: a impress�o do vetor intersec��o deve ser no main.
 */

 void calc_intersec(int a[], int na, int b[], int nb, int c[], int *nc); // C�lculo o vetor intersec��o entre A e B e salva no vetor C
 void ler_array(int vet[], int tam, char nome_vet); // L� do teclado os elementos de um vetor e os salva no vetor VET
 void ler_num_elementos(int *num, char nome_vet); // L� do teclado o n�mero de elementos de um vetor e salva no inteiro NUM

int main(){
    setlocale(LC_ALL, "Portuguese");

    int tam_a, tam_b, tam_saida;

    // Leitura do vetor a
    ler_num_elementos(&tam_a, 'a');
    int vet_a[tam_a];
    ler_array(vet_a, tam_a, 'a');

    // Leitura do vetor b
    ler_num_elementos(&tam_b, 'b');
    int vet_b[tam_b];
    ler_array(vet_b, tam_b, 'b');

    int vet_c[MAX];
    calc_intersec(vet_a, tam_a, vet_b, tam_b, vet_c, &tam_saida);

    printf("Vetor intersec��o: ");
    if (tam_saida >= 1){
        for (int i = 0; i < tam_saida; i++) printf("%d ", vet_c[i]);

    } else printf("vazio\n");

    return 0;
}


void calc_intersec(int a[], int na, int b[], int nb, int c[], int *nc){
    int tam_c = 0, pos_c = 0;

    // Determina��o do tamanho do vetor c
    for (int i = 0; i < na; i++){ // Vetor a
        for (int j = 0; j < nb; j++){ // Vetor b
            // Se um elemento de a exister em b, aumenta em 1 a capacidade do vetor c
            if (a[i] == b[j]) tam_c++;
        }
    }

    *nc = tam_c;

    // Constru��o do vetor c
    for (int i = 0; i < na; i++){ // Vetor a
        for (int j = 0; j < nb; j++){ // Vetor b
            // Se um elemento de a exister em b, copia esse elemento para c e anda 1 posi��o no vetor
            if (a[i] == b[j]) c[pos_c++] = a[i];
        }
    }
}

void ler_array(int vet[], int tam, char nome_vet){
    printf("Entre com os %d elementos de %c: ", tam, nome_vet);
    for (int i = 0; i < tam; i++) scanf("%d", &vet[i]);
}

void ler_num_elementos(int *num, char nome_vet){
    int lido;
    do {
        printf("Entre com o n�mero de elementos do vetor %c: ", nome_vet);
        scanf("%d", &lido);

        if(lido > MAX) printf("O n�mero de elementos do vetor deve ser menor ou igual que %d.\n", MAX);
    } while(lido > MAX); // Valida��o
    *num = lido;
}
