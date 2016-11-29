#include "raylib.h"

typedef struct Nave {
    Vector2 posicao;
    int vidas;
    int pontos;
} Nave;

static Nave nave;

void Navinha_Mover (Vector2 *nav) {

    if (IsKeyDown(KEY_RIGHT)) {
        if (nave.posicao.x < 790.0f) { //para não sair da janela
            nave.posicao.x += 5.0f;
        }
    }

    if (IsKeyDown(KEY_LEFT)) {
        if (nave.posicao.x > 12.0f) {
            nave.posicao.x -= 5.0f;
        }
    }

    if (IsKeyDown(KEY_UP)) {
        if (nave.posicao.y > 10.0f) {
            nave.posicao.y -= 5.0f;
        }
    }

    if (IsKeyDown(KEY_DOWN)) {
        if (nave.posicao.y < 440.0f) {
            nave.posicao.y += 5.0f;
        }
    }

    *nav = nave.posicao;

}

void Navinha_Desenhar (Vector2 *nav) {

    BeginDrawing();

        DrawCircleV(nave.posicao, 10, BLUE);

    EndDrawing();

    *nav = nave.posicao;

}