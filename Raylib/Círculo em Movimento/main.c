#include <stdio.h>
#include "raylib.h"
#include "src/checks.h"
#include "src/circle_colors.h"
#include "src/infos.h"

int main(){

    Vector2 janela = {800, 450};
    int fps = 60;

    // Inicialização

    InitWindow(janela.x, janela.y, "Circulo");
    SetTargetFPS(fps);

    Vector2 circle_loc = {400, 225};

    Color cor;
    reset_color(&cor);

    int circle_tam = 50, tam_passo = 5;

    int allowMov = true;


    while(!WindowShouldClose()){
        // Alterações

        color_changer(&cor);
        circle_size(&circle_tam, tam_passo);
        step_size(&tam_passo);


        allowMoves(&allowMov);
        if (allowMov){
            circle_loc = GetMousePosition();
            circle_limits(&circle_loc, circle_tam);
        }

        // Desenho
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Informações em texto (canto superior esquerdo da tela)
        draw_infos(circle_loc, circle_tam, tam_passo);

        // Cores disponíveis (canto superior direito da tela)
        draw_colors_options(janela);

        DrawCircle(circle_loc.x, circle_loc.y, circle_tam, cor);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
