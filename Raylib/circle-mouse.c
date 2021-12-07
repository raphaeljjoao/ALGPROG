#include "raylib.h"
#include <stdio.h>

int main(){

    Vector2 janela = {800, 450};

    // Inicialização

    InitWindow(janela.x, janela.y, "Circulo");
    SetTargetFPS(60);

    Vector2 circle = {400, 225};

    Color cor = BLUE;

    int circle_tam = 50;
    int tam_passo = 5;
    int tam_font_info = 20;
    int tam_cor = 40;

    int movimento = true;

    // Retângulos coloridos
    Rectangle rec1 = {janela.x - tam_cor * 2.3, 10, tam_cor, tam_cor};
    Rectangle rec2 = {janela.x - tam_cor * 1.3, 10, tam_cor, tam_cor};
    Rectangle rec3 = {janela.x - tam_cor * 2.3, 10 + tam_cor, tam_cor, tam_cor};
    Rectangle rec4 = {janela.x - tam_cor * 1.3, 10 + tam_cor, tam_cor, tam_cor};

    Color cor1 = BLACK;
    Color cor2 = RED;
    Color cor3 = ORANGE;
    Color cor4 = GREEN;


    while(!WindowShouldClose()){
        // Alterações

        /* Desativado, agora a troca de cor é escolhida clicando na tela
        // Cor do círculo
        if (IsKeyReleased(KEY_W)) cor = cor1;
        if (IsKeyReleased(KEY_A)) cor = cor2;
        if (IsKeyReleased(KEY_S)) cor = cor3;
        if (IsKeyReleased(KEY_D)) cor = cor4;
        */


        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
            if (CheckCollisionPointRec(GetMousePosition(), rec1)) cor = cor1;
            if (CheckCollisionPointRec(GetMousePosition(), rec2)) cor = cor2;
            if (CheckCollisionPointRec(GetMousePosition(), rec3)) cor = cor3;
            if (CheckCollisionPointRec(GetMousePosition(), rec4)) cor = cor4;
        }


        // Tamanho do círculo
        if (IsKeyReleased(KEY_UP) && circle_tam < janela.x / 4) circle_tam += tam_passo;
        if (IsKeyReleased(KEY_DOWN) && circle_tam > 25) circle_tam -= tam_passo;

        // Tamanho do passo
        if (IsKeyReleased(KEY_RIGHT) && tam_passo < 50) tam_passo++;
        if (IsKeyReleased(KEY_LEFT) && tam_passo > 1) tam_passo--;

        // O círculo pode se movimentar?
        if (IsMouseButtonReleased(MOUSE_RIGHT_BUTTON)) movimento = true;
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) movimento = false;

        if (movimento){
            circle = GetMousePosition();

            // Limites da janela
            if (circle.x < circle_tam - 0.1) circle.x = circle_tam;
            if (circle.y < circle_tam - 0.1) circle.y = circle_tam;
            if (circle.x > janela.x - circle_tam) circle.x = janela.x - circle_tam;
            if (circle.y > janela.y - circle_tam) circle.y = janela.y - circle_tam;
        }

        char circle_pos[100];
        sprintf(circle_pos, "Pos: x=%.2f y=%.2f", circle.x, circle.y);

        char circle_tam_s[50];
        sprintf(circle_tam_s, "Tam: %d", circle_tam);

        char passo_s[50];
        sprintf(passo_s, "Passo: %d", tam_passo);

        // Desenho
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Informações
        DrawText(circle_pos, 10, 10, tam_font_info, BLACK);
        DrawText(circle_tam_s, 10, 10 + tam_font_info, tam_font_info, BLACK);
        DrawText(passo_s, 10, 10 + tam_font_info * 2, tam_font_info, BLACK);

        // Cores disponíveis
        DrawRectangleRec(rec1, cor1);
        DrawRectangleRec(rec2, cor2);
        DrawRectangleRec(rec3, cor3);
        DrawRectangleRec(rec4, cor4);

        DrawCircle(circle.x, circle.y, circle_tam, cor);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
