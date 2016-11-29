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

#define NUM_MAX_INIMIGOS 40
#define NUM_MAX_TIROS 300

static bool gameOver;
static bool pause;

static Vector2 *nav = &nave.posicao;
static Vector2 posicaoVidas = {10, 430};

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

	nave.posicao = *nav;

	nave.posicao.x = 10;
	nave.posicao.y = 225;
	nave.vidas = 3;
	nave.pontos = 0;

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
	        if (inimigos1[i].ativo) DrawCircleV(inimigos1[i].posicao, 10, MAROON);
		}
		for (int i = 0; i < NUM_MAX_TIROS; i++) {	
			if (tiro[i].ativo) {
				DrawCircleV(tiro[i].posicao, 3, GREEN);
			}
		}

		for (int i = 0; i < nave.vidas; i++) {

	  		posicaoVidas.x = 20 + (i * 30);
	        DrawCircleV (posicaoVidas, 10, DARKBLUE);

	    }

		DrawText(FormatText("%04i", nave.pontos), 20, 20, 40, GRAY);

}

void Update () {

    ClearBackground(BLACK); //background

	if (!gameOver) {

		if (IsKeyPressed('P')) pause = !pause;

		Navinha_Desenhar(nav);

		if (!pause) {

			Navinha_Mover(nav); //mover

			Desenhar();

    		if (IsKeyDown(KEY_SPACE)) {
    			tiros += 5;

        		for (int i = 0; i < NUM_MAX_TIROS; i++) {
			        if (!tiro[i].ativo && tiros%20 == 0) {
			            tiro[i].ativo = true;
						tiro[i].posicao.x = nave.posicao.x;
			            tiro[i].posicao.y = nave.posicao.y;
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

					if (CheckCollisionCircles(nave.posicao,10,inimigos1[i].posicao, 5) ){
						inimigos1[i].posicao.x += 800;
						inimigos1[i].posicao.y = GetRandomValue(450, 0);
						nave.vidas -= 1;
						nave.posicao.x = 10.0f;
						nave.posicao.y = 225.0f;
					}

				}
			}
			for (int i = 0; i < NUM_MAX_TIROS; i++){
				if (tiro[i].ativo) {
		        //Movimento
		        	tiro[i].posicao.x += tiro[i].velocidade.x;

	        	for(int j = 0; j < NUM_MAX_INIMIGOS; j++){
	        		if (CheckCollisionCircles(tiro[i].posicao, 3, inimigos1[j].posicao, 5) ){
						inimigos1[j].posicao.x += 800;
						inimigos1[j].posicao.y = GetRandomValue(450, 0);
						tiro[i].ativo = false;
						nave.pontos++;
					}
				}		        	

		        }
		    	
		    	//sair da tela
		    	if (tiro[i].posicao.x + 1 >= 800) {
		    		tiro[i].ativo = false;
		    	}

//		    	if (nave.vidas == 0) gameOver = true;
		    }

		}

	}

}
