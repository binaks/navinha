#include "raylib.h"
#include "nave_funcoes.c"

/*typedef struct Tiro {
    Rectangle tiro;
    Vector2 velocidade;
    bool ativo;
    Color cor;
} Tiro;*/

typedef struct Nave {
	Vector2 posicao;
	int vidas;
} Nave;

static bool gameOver;
static bool pause;

static Nave nave;


/*void Atirar (Vector2 posicaoTiro) {

}*/

void IniciarJogo () {
	//Inicializa as variáveis do jogo

	//Inicializa jogador

	//Inicializa inimigos

	//Inicializa tiros

	gameOver = false;
	pause = false;

	nave.posicao.x = 10.0f;
	nave.posicao.y = 225.0f;
	nave.vidas = 3;
}

void Update () {

    Vector2 *nav;
    nav = &nave.posicao;
    //ponteiro apontando para a posição da nave


	if (!gameOver) {

		if (IsKeyPressed('P')) pause = !pause;

		if (!pause) {

			Navinha_Mover(nav, nave.posicao); //mover
//	        Navinha_Atirar(nav, nave.posicao); //atirar

		}
	}

}