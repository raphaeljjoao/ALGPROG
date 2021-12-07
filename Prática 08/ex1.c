#include <stdio.h>
#include "raylib.h"

int main(void){

    const int larguraJanela = 800;
    const int alturaJanela = 450;

    InitWindow(larguraJanela, alturaJanela, "Raphael (333315)");
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        ClearBackground(RAYWHITE);
        BeginDrawing();

        int charUsed = 0;
        const int charMax = 9;
        char contChar[18];
        // Formatação da string que informará o número de caracteres digitados
        sprintf(contChar, "NUM DE CHARS: %d/%d", charUsed, charMax);

        Rectangle texto = {larguraJanela/3 - 20, 150, 300, 60};

        DrawText("Digite o seu nome com 9 caracteres", larguraJanela/4 + 10, 120, 20, GRAY);
        DrawRectangleRec(texto, GRAY);
        DrawRectangleLines(texto.x, texto.y, texto.width, texto.height, RED);
        DrawText(contChar, larguraJanela/2 - 110, 225, 20, DARKGRAY);
        DrawText("Pressione BACKSPACE para deletar chars...", larguraJanela/4 - 20, 270, 20, GRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
