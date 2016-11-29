#include "raylib.h"

typedef enum {SCORE = 0, HIGH_SCORE} Dados;

static int hiscore = 0;

void High_Score (int score) {
    if (IsKeyPressed(KEY_ENTER)) {
        StorageSaveValue(SCORE, score);
        StorageSaveValue(HIGH_SCORE, hiscore);
    }

    BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText(FormatText("SCORE: %i", score), 280, 130, 40, MAROON);
        DrawText(FormatText("HI-SCORE: %i", hiscore), 210, 200, 50, BLACK);
        
        DrawText("Pressione ENTER para salvar", 250, 310, 20, LIGHTGRAY);

    EndDrawing();
}