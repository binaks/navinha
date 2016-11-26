#include "raylib.h"
#include "geral_funcoes.c"
#include "nave_funcoes.c"

int main()
{
    // Initialization

    int screenWidth = 800;
    int screenHeight = 450;
    //dimensões da janela

    Vector2 posicaoNave = {10.0f, 225.0f};
    //inicialização da posição da nave, no caso, meio da tela

    Vector2 *nav;
    nav = &posicaoNave;
    //ponteiro apontando para a posição da nave

    InitWindow(screenWidth, screenHeight, "Star Treko"); //nome na barra
    SetTargetFPS(60); //configura o fps

    // Main game loop
    while (!WindowShouldClose()) {    // Detect window close button or ESC key

        Navinha_Mover(nav, posicaoNave); //mover
        Navinha_Atirar(nav, posicaoNave); //atirar

        // Draw

        BeginDrawing(); //essa parte também poderia estar modularizada, né?

            ClearBackground(BLACK); //background

            DrawCircleV(posicaoNave, 10, DARKGRAY); //círculo da nave
            //posicaoNave indica onde o círculo vai ser desenhado

        EndDrawing();

    }

    // De-Initialization
 
    CloseWindow();        // Close window and OpenGL context


    return 0;
}