#include "raylib.h"
#include "geral_funcoes.c"

int main()
{
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Star Treko");
    SetTargetFPS(60);

    IniciarJogo ();

    while (!WindowShouldClose()) {

        Update();

    }
 
    CloseWindow();

    return 0;
}