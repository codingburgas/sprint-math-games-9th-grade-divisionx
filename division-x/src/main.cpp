#include "raylib.h"
#include <stdio.h>
#include <string>

int bord[4][4] = { {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };

// Ôóíêöèÿ çà äîáàâÿíå íà íîâà äâîéêà íà ïðîèçâîëíà ñâîáîäíà êëåòêà
void addNewTile() {
    int emptyCells[16][2];
    int emptyCount = 0;

    // Íàìèðàíå íà âñè÷êè ïðàçíè êëåòêè
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (bord[i][j] == 0) {
                emptyCells[emptyCount][0] = i;
                emptyCells[emptyCount][1] = j;
                emptyCount++;
            }
        }
    }

    // Äîáàâÿíå íà 2 â ñëó÷àéíà ïðàçíà êëåòêà, àêî èìà íàëè÷íè
    if (emptyCount > 0) {
        int randomIndex = GetRandomValue(0, emptyCount - 1);
        int x = emptyCells[randomIndex][0];
        int y = emptyCells[randomIndex][1];
        bord[x][y] = 2;
    }
}
// Функция за преместване и обединяване на плочки в ляво
void moveLeft() {
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            if (bord[i][j] != 0) {
                int k = j;
                while (k > 0 && bord[i][k - 1] == 0) {
                    bord[i][k - 1] = bord[i][k];
                    bord[i][k] = 0;
                    k--;
                }
                if (k > 0 && bord[i][k] == bord[i][k - 1]) {
                    bord[i][k - 1] *= 2;
                    bord[i][k] = 0;
                }
            }
        }
    }
}
// Функция за преместване и обединяване на плочки в дясно
void moveRight() {
    for (int i = 0; i < 4; i++) {
        for (int j = 2; j >= 0; j--) {
            if (bord[i][j] != 0) {
                int k = j;
                while (k < 3 && bord[i][k + 1] == 0) {
                    bord[i][k + 1] = bord[i][k];
                    bord[i][k] = 0;
                    k++;
                }
                if (k < 3 && bord[i][k] == bord[i][k + 1]) {
                    bord[i][k + 1] *= 2;
                    bord[i][k] = 0;
                }
            }
        }
    }
}

int main()
{
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "2048 Game in raylib");
    SetTargetFPS(60);

    // Äîáàâÿíå íà ïúðâèòå äâå ïðîèçâîëíè ÷èñëà â ïîëåòî
    addNewTile();
    addNewTile();

    while (!WindowShouldClose())
    {
        // Управление на играта
        if (IsKeyPressed(KEY_RIGHT)) {
            moveRight();
            addNewTile();
        }
        else if (IsKeyPressed(KEY_LEFT)) {
            moveLeft();
            addNewTile();
        }
        else if (IsKeyPressed(KEY_UP)) {
            
            addNewTile();
        }
        else if (IsKeyPressed(KEY_DOWN)) {
            
            addNewTile();
        }


        BeginDrawing();
        ClearBackground(BEIGE);

        // Çàãëàâèå è ïðàâèëà íà èãðàòà
        DrawText("2048", 70, 100, 200, WHITE);
        DrawText("RULES:", 5, 340, 20, WHITE);


        // Ðèñóâàíå íà ïîëåòî è ïîêàçâàíå íà ñòîéíîñòèòå îò `bord`
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                // Ðèñóâàíå íà êëåòêà
                DrawRectangleLines(740 + j * 120, 125 + i * 120, 120, 120, WHITE);

                // Ïîêàçâàíå íà ñòîéíîñò â êëåòêàòà (àêî èìà òàêàâà)
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