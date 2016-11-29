#include "raylib.h"

void High_Score (int high_score, int score) {

    BeginDrawing();

        ClearBackground(BLACK);

        DrawText(FormatText("SCORE: %i", score), 280, 130, 40, MAROON);
        DrawText(FormatText("HI-SCORE: %i", high_score), 210, 200, 50, GRAY);
        
        DrawText("Pressione ENTER para salvar", 250, 310, 20, LIGHTGRAY);

    EndDrawing();
}