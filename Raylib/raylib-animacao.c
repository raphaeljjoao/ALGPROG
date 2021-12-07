#include "raylib.h"

int main(void){
    // Initialization
    //--------------------------------------------------------------------------------------
    Vector2 tjanela = (Vector2) {1000, 550};
    Vector2 texto;

    int x = 365, y = 260;
    int xt = x, yt = y;

    int passada = 60, suavizacao = passada/10;

    InitWindow(tjanela.x, tjanela.y, "Primeira janela no Raylib");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    do {

        // Atualizações

        // x para a direita
        if(IsKeyPressed(KEY_RIGHT)) xt += passada;

        // x para a esquerda
        if(IsKeyPressed(KEY_LEFT)) xt -= passada;

        // y para baixo
        if(IsKeyPressed(KEY_DOWN)) yt += passada;

        // y para cima
        if(IsKeyPressed(KEY_UP)) yt -= passada;


        // Limites da tela
        if(xt > tjanela.x){
            x = - 200;
            xt = 10;
        }

        if (xt < -270){
            x = tjanela.x + 100;
            xt = tjanela.x - 270;
        }

        if (yt < 0){
            y = tjanela.y + 100;
            yt = tjanela.y - 50;
        }

        if (yt > tjanela.y){
            y = -200;
            yt = 10;
        }

        // Suavização
        if(x < xt) x += suavizacao;
        if(x > xt) x -= suavizacao;

        if(y < yt) y += suavizacao;
        if(y > yt) y -= suavizacao;



        texto.x = x;
        texto.y = y;


        // Desenho

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Qualquer coisa", texto.x, texto.y, 35, BLUE);

        EndDrawing();

    }while(!WindowShouldClose());

    CloseWindow();

    return 0;
}
