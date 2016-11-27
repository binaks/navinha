#include "raylib.h"
#include "nave_funcoes.c"

typedef struct Tiro {
    Rectangle bala;
    Vector2 velocidade;
    bool ativo;
    Color cor;
} Tiro;

typedef struct Nave {
	Vector2 posicao;
	int vidas;
} Nave;

static bool gameOver;
static bool pause;

static Nave nave;


//void Atirar (Vector2 posicaoTiro) {



//}

void IniciarJogo (Vector2 *nav, Vector2 posicaoNave) {
	//Inicializa as variáveis do jogo

	//Inicializa inimigos

	//Inicializa tiros

    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Star Treko"); //nome na barra

    SetTargetFPS(60); //configura o fps

	gameOver = false;
	pause = false;

	posicaoNave = *nav;

	nave.posicao.x = posicaoNave.x;
	nave.posicao.y = posicaoNave.y;
	nave.vidas = 3;

}

void Update (Vector2 *nav, Vector2 posicaoNave) {

	if (!gameOver) {

		if (IsKeyPressed('P')) pause = !pause;

		if (!pause) {

			Navinha_Mover(nav, posicaoNave); //mover
//	        Navinha_Atirar(nav, posicaoNave); //atirar

		}

		for (int i = 0; i < nave.vidas; i++) {
			BeginDrawing();
				DrawRectangle (20, 770, 35, 10, LIGHTGRAY);
			EndDrawing();
		}
	}

}