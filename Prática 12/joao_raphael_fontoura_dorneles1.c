#include <stdio.h>
#include <locale.h>
#include <strings.h>

#define MAX_CARROS 3

/*
 * Aluno: João Raphael Fontoura Dorneles (333315)
 */

typedef struct carro{
    int cod, ano;
    char modelo[45], marca[45];
    float preco;
} CARRO;

// Imprime menu na tela, faz validação e retorna a opção desejada
int menu();

// Lê informações e cadastra um carro
void cadastraCarro(CARRO *c);

// Imprime as informações de um determinado carro na tela na opção consulta de
// carro. Esta função deverá ser usada também para a impressão de todo o estoque
// da revenda.
void print_carro(CARRO c);

// Calcula o preco médio de todos os carros cadastrados
float calcMediaPreco(CARRO carros[], int ncarros);

// Procura um carro com o código fornecido entre todos os cadastrados. Caso não
// exista o carro, retorna -1 no campo cod do carro retornado
CARRO procuraCarro(CARRO carros[], int ncarros, int cod);

int main(){
    setlocale(LC_ALL, "Portuguese");

    CARRO vet_carros[MAX_CARROS];
    int cadastrados = 0;

    int opcao;


    do {
        opcao = menu();
        int codigo; // valor que será lido no case 2, não é possível criar variáveis dentro do case de um switch

        switch(opcao){
            case 1: // Cadastro
                // Se houver espaço no vetor, cadastra um novo carro e aumenta em 1 a contagem de
                //carros cadastrados
                if (cadastrados < MAX_CARROS) cadastraCarro(&vet_carros[cadastrados++]);
                else printf("Não é possível cadastrar mais carros. Limite (%d) atingido.\n\n", MAX_CARROS);
                break;
            case 2: // Consulta
                printf("Informe o código do carro: ");
                scanf("%d", &codigo);
                printf("\n");

                CARRO pesquisa = procuraCarro(vet_carros, cadastrados, codigo);

                // Caso a pesquisa não tenha retornado um código de erro, imprime os dados do carro
                if (pesquisa.cod != -1) print_carro(pesquisa);
                else printf("Carro não encontrado. Código %d não existe.\n\n", codigo);
                break;
            case 3: // Preço médio do estoque
                // Caso exista ao menos um carro cadastrado, calcula e imprime a média de preços
                if (cadastrados >= 1) printf("Preço médio dos carros: %.2f\n\n", calcMediaPreco(vet_carros, cadastrados));
                else printf("Não há nenhum carro cadastrado. Não foi possível determinar o preço médio.\n\n");
                break;
            case 4: // Estoque de revenda
                printf("Carros no estoque: %d\n\n", cadastrados);
                // Caso o número de carros cadastrados seja igual a 0, o for não será executado por não
                // ter satisfeita a sua condição
                for (int i = 0; i < cadastrados; i++){
                    printf("== Carro %d ==\n", i + 1); // Imprime o número do carro de 1 até o número de carros cadastrados
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
        printf("3 - Preço médio dos carros\n");
        printf("4 - Imprime estoque revenda\n");
        printf("5 - Fim\n");
        printf("Escolha uma opção: ");
        scanf("%d", &lido);

        opcao_valida = lido >= 1 && lido <= 5;
        if (!opcao_valida) printf("Opção inválida.");
        printf("\n");
    } while(!opcao_valida);
    return lido;
}

void cadastraCarro(CARRO *c){

    int codigo, codigo_valido; // Variáveis para salvar o código lido e fazer sua validação
    do {
        printf("Código: ");
        scanf("%d", &codigo);

        codigo_valido = codigo > 0;

        if (!codigo_valido) printf("Código inválido. Insira um número maior que 0.\n");
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

    printf("Preço: ");
    scanf("%f", &c->preco);

    printf("\nCarro cadastrado com sucesso!\n\n");
}

void print_carro(CARRO c){
    printf("Código: %d\n", c.cod);
    printf("Ano: %d\n", c.ano);
    printf("Modelo: %s\n", c.modelo);
    printf("Marca: %s\n", c.marca);
    printf("Preço: %.2f\n\n", c.preco);
}

float calcMediaPreco(CARRO carros[], int ncarros){
    float media = 0;
    for (int i = 0; i < ncarros; i++) media += carros[i].preco;
    return media / ncarros;
}

CARRO procuraCarro(CARRO carros[], int ncarros, int cod){
    CARRO c;
    int localizacao = -1; // Valor padrão é um código de erro, será trocado caso o carro procurado seja encontrado

    for (int i = 0; i < ncarros; i++){
        int encontrou = carros[i].cod == cod;
        if (encontrou) localizacao = i;
    }

    if (localizacao != -1) c = carros[localizacao]; // Caso o carro seja encontrado pelo código, retorna ele
    else c.cod = localizacao; // Caso contrário, retorna um carro somente com o código representando erro

    return c;
}
