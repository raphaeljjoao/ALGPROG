#include "raylib.h"
#include "infos.h"
#include <stdio.h>

#define FONT_SIZE 20
#define FONT_COLOR BLACK

const char* info_circle_pos(Vector2 circle_position){
    static char info[100];
    sprintf(info, "Pos: x=%.2f y=%.2f", circle_position.x, circle_position.y);
    return info;
}

const char* info_circle_size(int circle_size){
    static char info[15];
    sprintf(info, "Tam: %d", circle_size);
    return info;
}

const char* info_step_size(int step_size){
    static char info[15];
    sprintf(info, "Passo: %d", step_size);
    return info;
}

void draw_infos(Vector2 circle_position, int circle_size, int step_size){
    DrawText(info_circle_pos(circle_position), 10, 10, FONT_SIZE, FONT_COLOR);
    DrawText(info_circle_size(circle_size), 10, 10 + FONT_SIZE, FONT_SIZE, FONT_COLOR);
    DrawText(info_step_size(step_size), 10, 10 + FONT_SIZE * 2, FONT_SIZE, FONT_COLOR);
    //DrawFPS(GetScreenWidth() - 80, GetScreenHeight() - 25);
}

