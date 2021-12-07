#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>

/*
 * Aluno: João Raphael Fontoura Dorneles (333315)
 * Enunciado: Escreva uma função com o protótipo abaixo:
 *
 *            char triangulo(float a, float b, float c, float *area);
 *
 *            A função verifica primeiro se os lados a, b e c recebidos como parâmetros
 *            formam um triângulo e, em caso afirmativo, qual o tipo de triângulo. O valor de
 *            retorno deve ser o char ‘q’ para equilátero, ‘i’ para isósceles e ‘e’ para escaleno,
 *            ou ‘n’ para não-triângulo. Caso ele seja triângulo retornar na variável área o valor da área.
 *
 *            Utilize essa função no programa principal que lê os valores de a,b,c e imprime a
 *            mensagem do tipo de triângulo e a área. Além disso utilize a função char le_s_n()
 *            que vimos na aula 17 para implementar a pergunta se o usuário deseja executar o
 *            programa novamente.
 */

char triangulo(float a, float b, float c, float *area); // Retorna o tipo de um triângulo e atribui sua área ao conteúdo de
                                                        // um ponteiro especificado
int valida_triangulo(float a, float b, float c); // Retorna se três medidas satisfazem as condições de existência de um triângulo
float area_triangulo(float a, float b, float c); // Retorna a área de um triângulo, dados as medidas dos seus lados
char le_s_n(); // Retorna a letra maiúscula s ou n

int main(){
    setlocale(LC_ALL, "Portuguese");

    float lado1, lado2, lado3, area;
    char tipo, classificacao[11];

    do{
        printf("Entre com os valores de a, b e c: ");
        scanf("%f%f%f", &lado1, &lado2, &lado3);

        tipo = triangulo(lado1, lado2, lado3, &area);

        switch(tipo){
            case 'q':
                sprintf(classificacao, "%s", "equilátero");
                break;
            case 'e':
                sprintf(classificacao, "%s", "escaleno");
                break;
            case 'i':
                sprintf(classificacao, "%s", "isósceles");
                break;
        }

        if (tipo != 'n') printf("Triângulo %s com área %f\n", classificacao, area);
        else printf("Não é um triângulo.\n");

    } while(le_s_n() == 'S');

    return 0;
}

char triangulo(float a, float b, float c, float *area){
    char tipo = 'P';

    if (valida_triangulo(a, b, c)){
        *area = area_triangulo(a, b, c);

        // Equilátero: 3 lados iguais
        if (a == b && b == c && a == c) tipo = 'q';

        // Escaleno: nenhum lado igual
        if (a != b && b != c && a != c) tipo = 'e';

        // Isósceles: 2 lados iguais
        if (a == b && c != a) tipo = 'i';
        if (b == c && a != b) tipo = 'i';
        if (a == c && b != a) tipo = 'i';

    } else tipo = 'n';
    return tipo;
}

int valida_triangulo(float a, float b, float c){
    int valida1, valida2, valida3;

    valida1 = a + b > c;
    valida2 = b + c > a;
    valida3 = a + c > b;

    /* Condições de existência de um triângulo (pdf da prática)
    valida1 = fabs(b-c) < a && a < b + c;
    valida2 = fabs(a-c) < b && a < a + c;
    valida3 = fabs(a-b) < c && a < a + b;
    */

    return (valida1 && valida2 && valida3);
}

float area_triangulo(float a, float b, float c){
    float t = (a + b + c) / 2;
    return sqrt(t*(t-a) * (t - b) * (t - c));
}

char le_s_n(){
    char s_n;
    do{
        printf("Mais um (S /N)? ");
        scanf(" %c", &s_n);
        s_n = toupper(s_n);
        if(s_n != 'S' && s_n != 'N') printf("Resposta inválida. ");
    } while (s_n != 'S' && s_n != 'N');
    return s_n;
}
