#include <stdio.h>
#include <math.h>

int main(){

    float x1, x2, y1, y2;

    printf("=== Distancia entre dois pontos em um plano cartesiano ===\n");

    printf("Insira as coordenadas do primeiro ponto:\n");
    printf("x1: ");
    scanf("%f", &x1);
    printf("y1:");
    scanf("%f", &y1);


    printf("Insira as coordenadas do segundo ponto:\n");
    printf("x2: ");
    scanf("%f", &x2);
    printf("y2: ");
    scanf("%f", &y2);

    printf("Valores informados: x1(%f), x2(%f), y1(%f) e y2(%f)\n", x1, x2, y1, y2);

    printf("A distancia entre os pontos A(%.2f,%.2f) e B (%.2f,%.2f) e de %.2f: ", x1, y1, x2, y2, sqrt(pow(x2-x1, 2) + pow(y2-y1, 2)));

    return 0;
}
