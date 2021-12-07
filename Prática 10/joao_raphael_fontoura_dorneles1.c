#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>

/*
 * Aluno: Jo�o Raphael Fontoura Dorneles (333315)
 * Enunciado: Escreva uma fun��o com o prot�tipo abaixo:
 *
 *            char triangulo(float a, float b, float c, float *area);
 *
 *            A fun��o verifica primeiro se os lados a, b e c recebidos como par�metros
 *            formam um tri�ngulo e, em caso afirmativo, qual o tipo de tri�ngulo. O valor de
 *            retorno deve ser o char �q� para equil�tero, �i� para is�sceles e �e� para escaleno,
 *            ou �n� para n�o-tri�ngulo. Caso ele seja tri�ngulo retornar na vari�vel �rea o valor da �rea.
 *
 *            Utilize essa fun��o no programa principal que l� os valores de a,b,c e imprime a
 *            mensagem do tipo de tri�ngulo e a �rea. Al�m disso utilize a fun��o char le_s_n()
 *            que vimos na aula 17 para implementar a pergunta se o usu�rio deseja executar o
 *            programa novamente.
 */

char triangulo(float a, float b, float c, float *area); // Retorna o tipo de um tri�ngulo e atribui sua �rea ao conte�do de
                                                        // um ponteiro especificado
int valida_triangulo(float a, float b, float c); // Retorna se tr�s medidas satisfazem as condi��es de exist�ncia de um tri�ngulo
float area_triangulo(float a, float b, float c); // Retorna a �rea de um tri�ngulo, dados as medidas dos seus lados
char le_s_n(); // Retorna a letra mai�scula s ou n

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
                sprintf(classificacao, "%s", "equil�tero");
                break;
            case 'e':
                sprintf(classificacao, "%s", "escaleno");
                break;
            case 'i':
                sprintf(classificacao, "%s", "is�sceles");
                break;
        }

        if (tipo != 'n') printf("Tri�ngulo %s com �rea %f\n", classificacao, area);
        else printf("N�o � um tri�ngulo.\n");

    } while(le_s_n() == 'S');

    return 0;
}

char triangulo(float a, float b, float c, float *area){
    char tipo = 'P';

    if (valida_triangulo(a, b, c)){
        *area = area_triangulo(a, b, c);

        // Equil�tero: 3 lados iguais
        if (a == b && b == c && a == c) tipo = 'q';

        // Escaleno: nenhum lado igual
        if (a != b && b != c && a != c) tipo = 'e';

        // Is�sceles: 2 lados iguais
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

    /* Condi��es de exist�ncia de um tri�ngulo (pdf da pr�tica)
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
        if(s_n != 'S' && s_n != 'N') printf("Resposta inv�lida. ");
    } while (s_n != 'S' && s_n != 'N');
    return s_n;
}
