#include "raylib.h"

typedef struct Nave {
    Vector2 posicao;
    int vidas;
} Nave;

typedef struct Tiro {
    Rectangle bala;
    Vector2 velocidade;
    bool ativo;
    Color cor;
} Tiro;

static Nave nave;

void Navinha_Mover (Vector2 *nav, Vector2 posicaoNave) {

    if (IsKeyDown(KEY_RIGHT)) {
        if (posicaoNave.x < 790.0f) { //para não sair da janela
            posicaoNave.x += 5.0f;
        }
    }

    if (IsKeyDown(KEY_LEFT)) {
        if (posicaoNave.x > 12.0f) {
            posicaoNave.x -= 5.0f;
        }
    }

    if (IsKeyDown(KEY_UP)) {
        if (posicaoNave.y > 10.0f) {
            posicaoNave.y -= 5.0f;
        }
    }

    if (IsKeyDown(KEY_DOWN)) {
        if (posicaoNave.y < 440.0f) {
            posicaoNave.y += 5.0f;
        }
    }

    *nav = posicaoNave;

}

void Navinha_Atirar (Tiro tiro, int tiros) {
    if (IsKeyDown(KEY_SPACE)) {
        tiros += 5;

        if (!tiro.ativo && tiros%20 == 0) {
            tiro.bala.x = nave.posicao.x;
            tiro.bala.y = nave.posicao.y;
            tiro.ativo = true;
        }
    }
}

void Navinha_Desenhar (Vector2 *nav, Vector2 posicaoNave) {

    BeginDrawing();

        DrawCircleV(posicaoNave, 10, DARKGRAY);
        //posicaoNave indica onde o círculo vai ser desenhado

    EndDrawing();

    *nav = posicaoNave;

}