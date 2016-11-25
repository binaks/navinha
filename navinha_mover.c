#include "raylib.h"

void navinha_mover (Vector2 *nav, Vector2 posicaoNave) {

    if (IsKeyDown(KEY_RIGHT)) {
    	if (posicaoNave.x < 790.0f) {
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

	if (IsKeyDown(KEY_SPACE)) {
		DrawCircleV(posicaoNave, 5, RAYWHITE);
	}

}