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

static Vector2 posicaoNave = {10.0f, 225.0f};
static Vector2 *nav = &posicaoNave;

//void Atirar (Vector2 posicaoTiro) {



//}

void IniciarJogo () {
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

void Update () {

	if (!gameOver) {

		if (IsKeyPressed('P')) pause = !pause;

		Navinha_Desenhar(nav, posicaoNave);

		if (!pause) {

			Navinha_Mover(nav, posicaoNave); //mover
//	        Navinha_Atirar(nav, posicaoNave); //atirar

		}

/*		for (int i = 0; i < nave.vidas; i++) {
			BeginDrawing();
				DrawRectangle (20, 770, 35, 10, LIGHTGRAY);
			EndDrawing();
		} */
	}

}