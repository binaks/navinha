#include "raylib.h"
#include "geral_funcoes.c"

int main() {

    IniciarJogo();

    while (!WindowShouldClose()) {    // Detect window close button or ESC key

        Update();

    }
 
    CloseWindow();        // Close window and OpenGL context


    return 0;
}