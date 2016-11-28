#include "raylib.h"
#include "nave_funcoes.c"

typedef struct Tiro {
    Vector2 posicao;
    Vector2 velocidade;
    bool ativo;
    Color cor;
} Tiro;

typedef struct Inimigos1{
	Vector2 posicao;
	Vector2 velocidade;
	bool ativo;
} Inimigos1;

#define NUM_MAX_INIMIGOS 10
#define NUM_MAX_TIROS 3000

static bool gameOver;
static bool pause;

static Vector2 posicaoNave = {10.0f, 225.0f};
static Vector2 *nav = &posicaoNave;

static int tiros;

static Inimigos1 inimigos1[NUM_MAX_INIMIGOS];
static Tiro tiro[NUM_MAX_TIROS];

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
	}

	//Inicializando tiros
	for (int i = 0; i < NUM_MAX_TIROS; i++) {
		tiro[i].posicao.x = nave.posicao.x;
		tiro[i].posicao.y = nave.posicao.y;
		tiro[i].velocidade.x = 10;
		tiro[i].velocidade.y = 0;
		tiro[i].ativo = false;
		tiro[i].cor = MAROON;

	}

//Lógica do tiro

}

void Desenhar() {
    for (int i = 0;i < NUM_MAX_INIMIGOS; i++)
    {
        if (inimigos1[i].ativo) DrawCircleV(inimigos1[i].posicao, 5, RAYWHITE);
	}
	for (int i = 0; i < NUM_MAX_TIROS; i++) {	
		if (tiro[i].ativo) {
			DrawCircleV(tiro[i].posicao, 3, MAROON);
		}
	}
}

void Update () {

    ClearBackground(BLACK); //background

	if (!gameOver) {

		if (IsKeyPressed('P')) pause = !pause;

		Navinha_Desenhar(nav, posicaoNave);

		if (!pause) {

			Navinha_Mover(nav, posicaoNave); //mover

			Desenhar();

    		if (IsKeyDown(KEY_SPACE)) {
    			tiros += 20;

        		for (int i = 0; i < NUM_MAX_TIROS; i++) {
			        if (!tiro[i].ativo && tiros%20 == 0) {
			            tiro[i].ativo = true;
						tiro[i].posicao.x = posicaoNave.x;
			            tiro[i].posicao.y = posicaoNave.y;
			            break;
			        }
        		}
    		}

			for (int i = 0; i < NUM_MAX_INIMIGOS; i++){
				//movimenta os inimigos
				if (inimigos1[i].ativo){
					if (inimigos1[i].posicao.x > 0){
						inimigos1[i].posicao.x -= inimigos1[i].velocidade.x;
					}
					else{
						inimigos1[i].posicao.x += 800;
						inimigos1[i].posicao.y = GetRandomValue(450, 0);
					}
				}
			}
			for (int i = 0; i < NUM_MAX_TIROS; i++){
				if (tiro[i].ativo) {
		        //Movimento
		        	tiro[i].posicao.x += tiro[i].velocidade.x;
		        }
		    	
		    	//sair da tela
		    	if (tiro[i].posicao.x + 1 >= 800) {
		    		tiro[i].ativo = false;
		    		tiros = 0;
		    	}
		    }

		}

		for (int i = 0; i < nave.vidas; i++) {

				DrawRectangle (20, 770, 35, 10, LIGHTGRAY); //não funciona

		}
	}

}
