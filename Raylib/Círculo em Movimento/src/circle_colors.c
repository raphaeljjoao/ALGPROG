#include "raylib.h"
#include "circle_colors.h"

#define NUM_OPTIONS 5
#define COLOR_SIZE 40

// A última cor armazenada será definida como o padrão
Color color_options[NUM_OPTIONS] = {LIME, GOLD, MAROON, VIOLET, SKYBLUE};
const int w_width = 800;

const Rectangle rec1 = {w_width - COLOR_SIZE * 2.3, 10, COLOR_SIZE, COLOR_SIZE};
const Rectangle rec2 = {w_width - COLOR_SIZE * 1.3, 10, COLOR_SIZE, COLOR_SIZE};
const Rectangle rec3 = {w_width - COLOR_SIZE * 2.3, 10 + COLOR_SIZE, COLOR_SIZE, COLOR_SIZE};
const Rectangle rec4 = {w_width - COLOR_SIZE * 1.3, 10 + COLOR_SIZE, COLOR_SIZE, COLOR_SIZE};



void reset_color(Color *circle_color){
    *circle_color = color_options[NUM_OPTIONS - 1];
}

void draw_colors_options(Vector2 window_dimensions){
    DrawRectangleRec(rec1, color_options[0]);
    DrawRectangleRec(rec2, color_options[1]);
    DrawRectangleRec(rec3, color_options[2]);
    DrawRectangleRec(rec4, color_options[3]);
}

int equal_color(Color c1, Color c2){
    int r, g, b, a;

    r = c1.r == c2.r;
    g = c1.g == c2.g;
    b = c1.b == c2.b;
    a = c1.a == c2.a;

    return (r && g && b && a);
}

void color_changer(Color *circle_color){
    Color c = *circle_color;
    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
        if (CheckCollisionPointRec(GetMousePosition(), rec1)) c = color_options[0];
        if (CheckCollisionPointRec(GetMousePosition(), rec2)) c = color_options[1];
        if (CheckCollisionPointRec(GetMousePosition(), rec3)) c = color_options[2];
        if (CheckCollisionPointRec(GetMousePosition(), rec4)) c = color_options[3];
        *circle_color = c;
    }

    if (IsKeyReleased(KEY_R)) reset_color(circle_color);
}
