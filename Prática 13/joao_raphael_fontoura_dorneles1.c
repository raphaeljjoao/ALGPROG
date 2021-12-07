#include <stdio.h>
#include <locale.h>
#include <string.h>

/*
 * Aluno: João Raphael Fontoura Dorneles (333315)
 * Enunciado: Escreva um programa que lê os dados de estudantes do ensino médio que prestaram ENEM. O seu
 * programa deve armazenar numa struct os dados: nome do aluno (arranjo com 60 caracteres), a idade do
 * aluno e a média final que o aluno obteve (inteiro entre 0 e 100, não precisa fazer consistência).
 * Leia os dados e armazene num arquivo binário cujo nome será lido do usuário. O programa deve parar
 * de ler dados quando o usuário digitar a string “sair” para o nome do aluno.
 *
 * Após a leitura e armazenamento dos dados no arquivo, o programa deve solicitar ao usuário uma média
 * qualquer e o programa deve listar o nome e média de todos os alunos que tiveram média maior ou igual
 * à média informada. Ainda deve informar a idade média de todos os alunos que prestaram ENEM. Estas
 * informações devem ser obtidas a partir da leitura do arquivo salvo.
 */

typedef struct strAluno{
     char nome[60];
     int idade;
     int media;
 } ALUNO;

// Cadastra um aluno e retorna se a leitura foi feita com sucesso
int cadastraAluno(ALUNO *a);

// Imprime na tela as informações de um aluno
ALUNO printAluno(ALUNO a);

// Retorna se uma média é válida
int validaMedia(int media);

int main(){
    setlocale(LC_ALL, "Portuguese");

    // Leitura do nome do arquivo
    char *arqNome;

    printf("Entre com o nome do arquivo (sem a extensão): ");
    fgets(arqNome, 35+1, stdin);
    arqNome[strlen(arqNome) - 1] = '\0';
    strcat(arqNome, ".bin"); // adiciona a extensão .bin ao final da string lida
    printf("\n");

    // Criação e/ou abertura do arquivo para escrita

    FILE *arq;
    arq = fopen(arqNome, "ab"); /* o arquivo é criado se ainda não existir; no modo "ab" novos
                             *  dados são acrescentados no final do arquivo */

    // Escrita dos alunos informados pelo usuário no arquivo

    if (arq != NULL){
        int continuarLendo;
        ALUNO alunoLido;

        printf("Digite sair no nome do aluno para interromper a inserção de novos alunos no arquivo.\n\n");

        do{
            continuarLendo = cadastraAluno(&alunoLido);

            if (continuarLendo){
                if (fwrite(&alunoLido, sizeof(ALUNO), 1, arq) != 1)
                    printf("Erro na escrita do aluno %s no arquivo %s", alunoLido.nome, arqNome);
            }

        } while(continuarLendo);
        printf("\n");
        fclose(arq);
    } else printf("Erro na abertura do arquivo %s\n", arqNome);


    // Abertura do arquivo para leitura
    arq = fopen(arqNome, "rb"); // Modo "read binary"

    // Leitura das informações para consulta
    if (arq != NULL){
        int media;

        do{
            printf("Entre com a média para a consulta: ");
            scanf("%d", &media);

            if (!validaMedia(media)) printf("Média inválida. Insira um número inteiro entre 0 e 100.\n");
        } while(!validaMedia(media));
        printf("\n");

        // Leitura do arquivo
        ALUNO alunoArquivo;
        int contTotal = 0; // Número de alunos cadastrados no arquivo
        int contMedia = 0; // Número de alunos com média maior ou igual ao informado
        int totalIdade = 0; // Soma da idade de todos os alunos

        printf("Lista de alunos com média maior ou igual a %d:\n", media);

        while (!feof(arq)){ // Enquanto não chegar ao fim do arquivo
            if (fread(&alunoArquivo, sizeof(ALUNO), 1, arq) == 1){ // Lê um aluno e prossegue se não houve erro
                // Soma da idade de todos os alunos
                totalIdade += alunoArquivo.idade;

                // Impressão dos alunos com média maior ou igual ao informado
                if (alunoArquivo.media >= media){
                    printf("== Aluno %d ==\n", ++contMedia);
                    printAluno(alunoArquivo);
                    printf("\n");
                }
            }
        }

        // Posição final do ponteiro após a leitura / tamanho em bytes da estrutura aluno
        contTotal = ftell(arq) / sizeof(ALUNO);

        printf("== Informações sobre o arquivo: ==\n");
        printf("Alunos cadastrados: %d\n", contTotal);
        printf("Alunos encontrados na consulta: %d\n", contMedia);
        printf("Idade média dos alunos: ");
        if (contTotal != 0) printf("%.2f\n", (float) totalIdade / contTotal); // Evita que seja realizada uma divisão por 0
        else printf("não foi possível definir\n");

        fclose(arq);
    } else printf("Erro na abertura do arquivo %s\n", arqNome);
    return 0;
}

int cadastraAluno(ALUNO *a){
    fflush(stdin);
    printf("Nome: ");
    fgets(a->nome, 60 + 1, stdin);
    a->nome[strlen(a->nome) - 1] = '\0';

    int continuarLendo = strcmp(a->nome, "sair");

    if (continuarLendo){
        printf("Idade: ");
        scanf("%d", &a->idade);

        int media = -1;

        while(!validaMedia(media)){
            printf("Média: ");
            scanf("%d", &media);
            if (!validaMedia(media))
                printf("Média inválida. Insira um número inteiro entre 0 e 100.\n");
        }
        a->media = media;
    }
    printf("\n");

    return continuarLendo;
}

ALUNO printAluno(ALUNO a){
    printf("Nome: %s\n", a.nome);
    printf("Idade: %d\n", a.idade);
    printf("Média: %d\n", a.media);
}

int validaMedia(int media){
    return media >= 0 && media <= 100;
}
