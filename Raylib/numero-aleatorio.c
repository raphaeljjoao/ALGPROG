#include "raylib.h"
#include <stdio.h>
#include <limits.h>

int main(){

    Vector2 janela = {800, 450};
    int num, cont = 0, min = 0, max = 1000, passo = 10;

    InitWindow(janela.x, janela.y, "Random Number");
    SetTargetFPS(60);

    Color main_color = GRAY;

    while(!WindowShouldClose()){

        if (cont++ % 120 == 0) num = GetRandomValue(min, max);

        // Controle do passo
        if (IsKeyReleased(KEY_KP_ADD) && passo < 10000) passo *= 10;
        if (IsKeyReleased(KEY_KP_SUBTRACT) && (passo / 10) > 0) passo /= 10;

        // Controle do max
        if (IsKeyReleased(KEY_UP) && max < INT_MAX) max += passo;
        if (IsKeyReleased(KEY_DOWN) && max > INT_MIN && (max - passo) > min) max -= passo;

        // Controle do min
        if (IsKeyReleased(KEY_RIGHT) && min < INT_MAX && (min + passo) < max) min += passo;
        if (IsKeyReleased(KEY_LEFT) && min > INT_MIN ) min -= passo;



        char numero[13];
        sprintf(numero, "%d", num);

        char info[100];
        sprintf(info, "(min=%d, max=%d)", min, max);
        //SetWindowTitle(info);

        char info_passo[100];
        sprintf(info_passo, "Passo: %d", passo);

        BeginDrawing();
        ClearBackground(BLACK);

        Vector2 pinfo = {13, 35};

        DrawText("Random Number Generator", 15, 15, 20, main_color);
        DrawText(info, 15, 35, 20, main_color);
        DrawText(info_passo, 15, 55, 20, main_color);

        DrawText(numero, 15, 360, 50, main_color);

        Vector2 spos = {0, 420};
        Vector2 epos = {janela.x, 420};

        DrawLineEx(spos, epos, 6, main_color);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
