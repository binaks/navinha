#include "raylib.h"
#include "nave_funcoes.c"

static bool gameOver;
static bool pause;

static Vector2 posicaoNave = {10.0f, 225.0f};
static Vector2 *nav = &posicaoNave;

static Tiro tiro;
static int tiros;

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

void Update () {

	if (!gameOver) {

		if (IsKeyPressed('P')) pause = !pause;

		Navinha_Desenhar(nav, posicaoNave);

		if (!pause) {

			Navinha_Mover(nav, posicaoNave); //mover
	        Navinha_Atirar(tiro, tiros); //atirar

		}

		for (int i = 0; i < nave.vidas; i++) {
				DrawRectangle (20, 770, 35, 10, LIGHTGRAY);
		}
	}

}