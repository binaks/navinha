#include "raylib.h"
#include "nave_funcoes.c"

typedef struct Tiro {
    Rectangle tiro;
    Vector2 velocidade;
    bool ativo;
    Color cor;
} Tiro;

typedef struct Nave {
	Vector2 posicaoNave;
	int vidas;
} Nave;

static bool gameOver;
static bool pause;

//static Nave nave;


//void Atirar (Vector2 posicaoTiro) {



//}

void IniciarJogo (void) {
	//Inicializa as variáveis do jogo

	//Inicializa jogador

	//Inicializa inimigos

	//Inicializa tiros

	gameOver = false;
	pause = false;
}

void Update (void) {

	if (!gameOver) {

		if (IsKeyPressed('P')) pause = !pause;

		if (!pause) {

//			Navinha_Mover(nav, posicaoNave); //mover
//	        Navinha_Atirar(nav, posicaoNave); //atirar

		}
	}

}