#include <stdio.h>
#include <locale.h>
#include <strings.h>

#define MAX_CARROS 3

/*
 * Aluno: Jo�o Raphael Fontoura Dorneles (333315)
 */

typedef struct carro{
    int cod, ano;
    char modelo[45], marca[45];
    float preco;
} CARRO;

// Imprime menu na tela, faz valida��o e retorna a op��o desejada
int menu();

// L� informa��es e cadastra um carro
void cadastraCarro(CARRO *c);

// Imprime as informa��es de um determinado carro na tela na op��o consulta de
// carro. Esta fun��o dever� ser usada tamb�m para a impress�o de todo o estoque
// da revenda.
void print_carro(CARRO c);

// Calcula o preco m�dio de todos os carros cadastrados
float calcMediaPreco(CARRO carros[], int ncarros);

// Procura um carro com o c�digo fornecido entre todos os cadastrados. Caso n�o
// exista o carro, retorna -1 no campo cod do carro retornado
CARRO procuraCarro(CARRO carros[], int ncarros, int cod);

int main(){
    setlocale(LC_ALL, "Portuguese");

    CARRO vet_carros[MAX_CARROS];
    int cadastrados = 0;

    int opcao;


    do {
        opcao = menu();
        int codigo; // valor que ser� lido no case 2, n�o � poss�vel criar vari�veis dentro do case de um switch

        switch(opcao){
            case 1: // Cadastro
                // Se houver espa�o no vetor, cadastra um novo carro e aumenta em 1 a contagem de
                //carros cadastrados
                if (cadastrados < MAX_CARROS) cadastraCarro(&vet_carros[cadastrados++]);
                else printf("N�o � poss�vel cadastrar mais carros. Limite (%d) atingido.\n\n", MAX_CARROS);
                break;
            case 2: // Consulta
                printf("Informe o c�digo do carro: ");
                scanf("%d", &codigo);
                printf("\n");

                CARRO pesquisa = procuraCarro(vet_carros, cadastrados, codigo);

                // Caso a pesquisa n�o tenha retornado um c�digo de erro, imprime os dados do carro
                if (pesquisa.cod != -1) print_carro(pesquisa);
                else printf("Carro n�o encontrado. C�digo %d n�o existe.\n\n", codigo);
                break;
            case 3: // Pre�o m�dio do estoque
                // Caso exista ao menos um carro cadastrado, calcula e imprime a m�dia de pre�os
                if (cadastrados >= 1) printf("Pre�o m�dio dos carros: %.2f\n\n", calcMediaPreco(vet_carros, cadastrados));
                else printf("N�o h� nenhum carro cadastrado. N�o foi poss�vel determinar o pre�o m�dio.\n\n");
                break;
            case 4: // Estoque de revenda
                printf("Carros no estoque: %d\n\n", cadastrados);
                // Caso o n�mero de carros cadastrados seja igual a 0, o for n�o ser� executado por n�o
                // ter satisfeita a sua condi��o
                for (int i = 0; i < cadastrados; i++){
                    printf("== Carro %d ==\n", i + 1); // Imprime o n�mero do carro de 1 at� o n�mero de carros cadastrados
                    print_carro(vet_carros[i]);
                }
        }
    } while (opcao != 5);
    printf("Programa encerrado.\n");
    return 0;
}

int menu(){
    int lido, opcao_valida;

    do {
        printf("1 - Cadastro de carro\n");
        printf("2 - Consulta de carro\n");
        printf("3 - Pre�o m�dio dos carros\n");
        printf("4 - Imprime estoque revenda\n");
        printf("5 - Fim\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &lido);

        opcao_valida = lido >= 1 && lido <= 5;
        if (!opcao_valida) printf("Op��o inv�lida.");
        printf("\n");
    } while(!opcao_valida);
    return lido;
}

void cadastraCarro(CARRO *c){

    int codigo, codigo_valido; // Vari�veis para salvar o c�digo lido e fazer sua valida��o
    do {
        printf("C�digo: ");
        scanf("%d", &codigo);

        codigo_valido = codigo > 0;

        if (!codigo_valido) printf("C�digo inv�lido. Insira um n�mero maior que 0.\n");
    } while (!codigo_valido);
    c->cod = codigo;

    printf("Ano: ");
    scanf("%d", &c->ano);

    printf("Modelo: ");
    fflush(stdin); // Evite que o ENTER da leitura anterior seja lido pelo fgets
    fgets(c->modelo, 45 + 1, stdin);
    c->modelo[strlen(c->modelo) - 1] = '\0'; // Substitui o \n lido pelo finalizador de string

    printf("Marca: ");
    fgets(c->marca, 45 + 1, stdin);
    c->marca[strlen(c->marca) - 1] = '\0'; // Substitui o \n lido pelo finalizador de string

    printf("Pre�o: ");
    scanf("%f", &c->preco);

    printf("\nCarro cadastrado com sucesso!\n\n");
}

void print_carro(CARRO c){
    printf("C�digo: %d\n", c.cod);
    printf("Ano: %d\n", c.ano);
    printf("Modelo: %s\n", c.modelo);
    printf("Marca: %s\n", c.marca);
    printf("Pre�o: %.2f\n\n", c.preco);
}

float calcMediaPreco(CARRO carros[], int ncarros){
    float media = 0;
    for (int i = 0; i < ncarros; i++) media += carros[i].preco;
    return media / ncarros;
}

CARRO procuraCarro(CARRO carros[], int ncarros, int cod){
    CARRO c;
    int localizacao = -1; // Valor padr�o � um c�digo de erro, ser� trocado caso o carro procurado seja encontrado

    for (int i = 0; i < ncarros; i++){
        int encontrou = carros[i].cod == cod;
        if (encontrou) localizacao = i;
    }

    if (localizacao != -1) c = carros[localizacao]; // Caso o carro seja encontrado pelo c�digo, retorna ele
    else c.cod = localizacao; // Caso contr�rio, retorna um carro somente com o c�digo representando erro

    return c;
}
