#include "raylib.h"
#include "nave_funcoes.c"

typedef struct Inimigos1{
	Vector2 posicao;
	Vector2 velocidade;
	bool ativo;
	Color cor;
} Inimigos1;

#define NUM_MAX_INIMIGOS 10

static bool gameOver;
static bool pause;

static Vector2 posicaoNave = {10.0f, 225.0f};
static Vector2 *nav = &posicaoNave;

static Tiro tiro;
static int tiros;

static Inimigos1 inimigos1[NUM_MAX_INIMIGOS];

void IniciarJogo () {

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

	tiros = 0;

//Inimigo 1
for (int i = 0; i < NUM_MAX_INIMIGOS; i++){
	inimigos1[i].posicao.x = GetRandomValue(screenWidth, screenWidth + 1000);
	inimigos1[i].posicao.y = GetRandomValue(0, screenHeight - 10);
	inimigos1[i].velocidade.x = 6;
	inimigos1[i].velocidade.y = 0;
	inimigos1[i].ativo = true;
	inimigos1[i].cor = RED;
}

//Inicializando tiros
	tiro.bala.x = nave.posicao.x;
	tiro.bala.y = nave.posicao.y;
	tiro.bala.width = 10;
	tiro.bala.height = 5;
	tiro.velocidade.x = 7;
	tiro.velocidade.y = 0;
	tiro.ativo = false;
	tiro.cor = MAROON;

//Lógica do tiro
    if (tiro.ativo) {
        //Movimento
        tiro.bala.x += tiro.velocidade.x;
    	
    	//sair da tela
    	if (tiro.bala.x + tiro.bala.width >= screenWidth) {
    		tiro.ativo = false;
    		tiros = 0;
    	}
    }

}

void DesenharInimigos() {
    for (int i = 0;i < NUM_MAX_INIMIGOS; i++)
    {
        if (inimigos1[i].ativo) DrawCircleV(inimigos1[i].posicao, 5, RAYWHITE);
	}
}

void Update () {

    ClearBackground(BLACK); //background

	if (!gameOver) {

		if (IsKeyPressed('P')) pause = !pause;

		Navinha_Desenhar(nav, posicaoNave);
		DesenharInimigos();

		if (!pause) {

			Navinha_Mover(nav, posicaoNave); //mover
	        Navinha_Atirar(tiro, tiros); //atirar

			for (int i = 0; i < NUM_MAX_INIMIGOS; i++){
				//movimenta os inimigos
				if (inimigos1[i].ativo){
					inimigos1[i].posicao.x -= inimigos1[i].velocidade.x;
				}
			}


		}

		for (int i = 0; i < nave.vidas; i++) {

				DrawRectangle (20, 770, 35, 10, LIGHTGRAY);

		}
	}

}
