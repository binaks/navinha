#include "raylib.h"
#include "stdio.h"

void High_Score (int high_score, int score) {

    BeginDrawing();

        ClearBackground(BLACK);
        
        if (score >= high_score) {
            DrawText(FormatText("NEW HIGH SCORE"), 160, 100, 50, DARKBLUE);
        } else {
            DrawText(FormatText("SCORE: %i", score), 290, 130, 40, GRAY);
            DrawText(FormatText("HI-SCORE: %i", high_score), 220, 200, 50, MAROON);
            DrawText(FormatText("Pressione ENTER para jogar novamente"), 90, 300, 30, DARKBLUE);
        }

    EndDrawing();
}