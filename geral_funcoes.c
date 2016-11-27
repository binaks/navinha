#include "raylib.h"
#include "nave_funcoes.c"

typedef struct Tiro {
    Rectangle tiro;
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

	//Inicializa jogador

	//Inicializa inimigos

	//Inicializa tiros

	gameOver = false;
	pause = false;

	posicaoNave = *nav;

	nave.posicao.x = posicaoNave.x;
	nave.posicao.y = posicaoNave.y;
}

void Update (Vector2 *nav, Vector2 posicaoNave) {

	if (!gameOver) {

		if (IsKeyPressed('P')) pause = !pause;

		if (!pause) {

			Navinha_Mover(nav, posicaoNave); //mover
//	        Navinha_Atirar(nav, posicaoNave); //atirar

		}
	}

}