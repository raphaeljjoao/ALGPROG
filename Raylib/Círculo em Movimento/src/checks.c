#include "raylib.h"
#include "checks.h"

void circle_limits(Vector2 *circle_position, int circle_radius){

        float circle_x = circle_position->x;
        float circle_y = circle_position->y;

        float radius = circle_radius;

        float w_width = GetScreenWidth();
        float w_heigth = GetScreenHeight();

        // Se o círculo ultrapassar a largura da janela para menos
        if (circle_x < radius - 0.1) circle_position->x = radius;

        // Se o círculo ultrapassar a largura da janela para mais
        if (circle_x > w_width - radius) circle_position->x = w_width - radius;

        // Se o círculo ultrapassar a altura da janela para menos
        if (circle_y < radius - 0.1) circle_position->y = radius;

        // Se o círculo ultrapassar a altura da janela para mais
        if (circle_y > w_heigth - radius) circle_position->y = w_heigth - radius;
}

void allowMoves(int *allow){
    if (IsMouseButtonReleased(MOUSE_RIGHT_BUTTON)) *allow = true;
    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) *allow = false;
}

void circle_size(int *size, int step){
    float w_width = GetScreenWidth();

    if (IsKeyReleased(KEY_UP) && (*size + step) < w_width / 4) *size += step;
    if (IsKeyReleased(KEY_DOWN) && (*size - step) >= 25) *size -= step;
}

void step_size(int *step){

    int step_for_step = 5;

    if (IsKeyReleased(KEY_RIGHT) && (*step + step_for_step) <= step_for_step * 10) *step += step_for_step;
    if (IsKeyReleased(KEY_LEFT) && (*step - step_for_step) >= step_for_step) *step -= step_for_step;
}
