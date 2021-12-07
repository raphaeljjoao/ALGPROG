#include <stdio.h>
#include <locale.h>

#define MAX 20

/*
 * Aluno: João Raphael Fontoura Dorneles (333315)
 * Enunciado: Escreva um programa que encontra o vetor intersecção entre 2 vetores
 *            de inteiros lidos do usuário. O número máximo de elementos em cada
 *            vetor é 20. Seu programa deve ter uma função void com o seguinte protótipo:
 *
 *            void calc_intersec(int a[], int na, int b[], int nb, int c[], int *nc);
 *
 *            Esta função recebe os vetores a e b, o número de elementos de a (na) e b (nb),
 *            retornando em c o vetor intersecção e na variável nc o número de elementos
 *            do vetor c. Os vetores podem ter um número diferente de elementos, mas considere
 *            que não há elementos repetidos em cada um dos vetores de entrada.
 *
 *            Observação: a impressão do vetor intersecção deve ser no main.
 */

 void calc_intersec(int a[], int na, int b[], int nb, int c[], int *nc); // Cálculo o vetor intersecção entre A e B e salva no vetor C
 void ler_array(int vet[], int tam, char nome_vet); // Lê do teclado os elementos de um vetor e os salva no vetor VET
 void ler_num_elementos(int *num, char nome_vet); // Lê do teclado o número de elementos de um vetor e salva no inteiro NUM

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

    printf("Vetor intersecção: ");
    if (tam_saida >= 1){
        for (int i = 0; i < tam_saida; i++) printf("%d ", vet_c[i]);

    } else printf("vazio\n");

    return 0;
}


void calc_intersec(int a[], int na, int b[], int nb, int c[], int *nc){
    int tam_c = 0, pos_c = 0;

    // Determinação do tamanho do vetor c
    for (int i = 0; i < na; i++){ // Vetor a
        for (int j = 0; j < nb; j++){ // Vetor b
            // Se um elemento de a exister em b, aumenta em 1 a capacidade do vetor c
            if (a[i] == b[j]) tam_c++;
        }
    }

    *nc = tam_c;

    // Construção do vetor c
    for (int i = 0; i < na; i++){ // Vetor a
        for (int j = 0; j < nb; j++){ // Vetor b
            // Se um elemento de a exister em b, copia esse elemento para c e anda 1 posição no vetor
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
        printf("Entre com o número de elementos do vetor %c: ", nome_vet);
        scanf("%d", &lido);

        if(lido > MAX) printf("O número de elementos do vetor deve ser menor ou igual que %d.\n", MAX);
    } while(lido > MAX); // Validação
    *num = lido;
}
