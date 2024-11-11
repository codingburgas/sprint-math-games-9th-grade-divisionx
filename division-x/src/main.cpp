#include "raylib.h"

int main()
{
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BEIGE);

        DrawText("2048", 70, 100, 200, WHITE);
        DrawText("Rulse:The game concept is simple and complex at the same time. ", 5, 340, 20, WHITE);
        DrawText("To only rule of the game is that you have to", 5, 360, 20, WHITE);
        DrawText("merge 2 tiles with the same numerical value and then they become 1 tile ", 5, 380, 20, WHITE);
        DrawText(" with x2 of their original value then you have to merge this new x2 tile", 5, 400, 20, WHITE);
        DrawText(" with another x2 tile until you reach 2048.", 5, 420, 20, WHITE);
        DrawRectangleLines(  740,  125,  530,  450, WHITE );
       

        

        EndDrawing();
    }
}