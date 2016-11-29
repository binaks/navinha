#include "raylib.h"
#include "stdio.h"

static char nome[3];

void High_Score (int high_score, int score) {

    FILE *hs = fopen ("high_score.txt", "a+");

    BeginDrawing();

        ClearBackground(BLACK);
        
        if (score >= high_score) {
            DrawText(FormatText("NEW HIGH SCORE"), 160, 100, 50, DARKBLUE);
            DrawText(FormatText("Nome:"), 160, 200, 30, LIGHTGRAY);

            for (int i = 0; i < 3; i++) {

                if (IsKeyPressed(KEY_A)) nome[i] = 'A';
                if (IsKeyPressed(KEY_B)) nome[i] = 'B';
                if (IsKeyPressed(KEY_C)) nome[i] = 'C';
                if (IsKeyPressed(KEY_D)) nome[i] = 'D';
                if (IsKeyPressed(KEY_E)) nome[i] = 'E';
                if (IsKeyPressed(KEY_F)) nome[i] = 'F';
                if (IsKeyPressed(KEY_G)) nome[i] = 'G';
                if (IsKeyPressed(KEY_H)) nome[i] = 'H';
                if (IsKeyPressed(KEY_I)) nome[i] = 'I';
                if (IsKeyPressed(KEY_J)) nome[i] = 'J';
                if (IsKeyPressed(KEY_K)) nome[i] = 'K';
                if (IsKeyPressed(KEY_L)) nome[i] = 'L';
                if (IsKeyPressed(KEY_M)) nome[i] = 'M';
                if (IsKeyPressed(KEY_N)) nome[i] = 'N';
                if (IsKeyPressed(KEY_O)) nome[i] = 'O';
                if (IsKeyPressed(KEY_P)) nome[i] = 'P';
                if (IsKeyPressed(KEY_Q)) nome[i] = 'Q';
                if (IsKeyPressed(KEY_R)) nome[i] = 'R';
                if (IsKeyPressed(KEY_S)) nome[i] = 'S';
                if (IsKeyPressed(KEY_T)) nome[i] = 'T';
                if (IsKeyPressed(KEY_U)) nome[i] = 'U';
                if (IsKeyPressed(KEY_V)) nome[i] = 'V';
                if (IsKeyPressed(KEY_W)) nome[i] = 'W';
                if (IsKeyPressed(KEY_X)) nome[i] = 'X';
                if (IsKeyPressed(KEY_Y)) nome[i] = 'Y';
                if (IsKeyPressed(KEY_Z)) nome[i] = 'Z';

            }

            fprintf (hs, "%s    %i", nome, score);



        } else {
            DrawText(FormatText("SCORE: %i", score), 290, 130, 40, GRAY);
            DrawText(FormatText("HI-SCORE: %i", high_score), 220, 200, 50, MAROON);
            DrawText(FormatText("Pressione ENTER para jogar novamente"), 90, 300, 30, DARKBLUE);
        }

    EndDrawing();
}