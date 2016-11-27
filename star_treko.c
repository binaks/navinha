#include "raylib.h"
#include "geral_funcoes.c"

int main()
{
    Vector2 posicaoNave = {10.0f, 225.0f};
    //inicialização da posição da nave

    Vector2 *nav;
    nav = &posicaoNave;

    IniciarJogo(nav, posicaoNave);

    // Main game loop
    while (!WindowShouldClose()) {    // Detect window close button or ESC key

        Navinha_Desenhar(nav, posicaoNave);

        Update(nav, posicaoNave);

    }

    // De-Initialization
 
    CloseWindow();        // Close window and OpenGL context


    return 0;
}