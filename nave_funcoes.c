#include "raylib.h"
#include "geral_funcoes.c"

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

void Navinha_Atirar (Vector2 *nav, Vector2 posicaoNave) {

	if (IsKeyDown(KEY_SPACE)) {
		Atirar (posicaoNave);
	}

}