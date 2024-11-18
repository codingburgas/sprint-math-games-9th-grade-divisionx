#include "raylib.h"
#include <stdio.h>
#include <string>

int bord[4][4] = { {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };

// Функция за добавяне на нова двойка на произволна свободна клетка
void addNewTile() {
    int emptyCells[16][2];
    int emptyCount = 0;

    // Намиране на всички празни клетки
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (bord[i][j] == 0) {
                emptyCells[emptyCount][0] = i;
                emptyCells[emptyCount][1] = j;
                emptyCount++;
            }
        }
    }

    // Добавяне на 2 в случайна празна клетка, ако има налични
    if (emptyCount > 0) {
        int randomIndex = GetRandomValue(0, emptyCount - 1);
        int x = emptyCells[randomIndex][0];
        int y = emptyCells[randomIndex][1];
        bord[x][y] = 2;
    }
}

int main()
{
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "2048 Game in raylib");
    SetTargetFPS(60);

    // Добавяне на първите две произволни числа в полето
    addNewTile();
    addNewTile();

    while (!WindowShouldClose())
    {
        
        

        BeginDrawing();
        ClearBackground(BEIGE);

        // Заглавие и правила на играта
        DrawText("2048", 70, 100, 200, WHITE);
        DrawText("RULES:", 5, 340, 20, WHITE);


        // Рисуване на полето и показване на стойностите от `bord`
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                // Рисуване на клетка
                DrawRectangleLines(740 + j * 120, 125 + i * 120, 120, 120, WHITE);

                // Показване на стойност в клетката (ако има такава)
                if (bord[i][j] != 0)
                {
                    char value[8];

                    DrawText(std::to_string(bord[i][j]).c_str(), 790 + j * 120, 165 + i * 120, 40, WHITE);
                }
            }
        }


        EndDrawing();
    }

    CloseWindow();

}
