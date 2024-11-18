#include "raylib.h"
#include <stdio.h>
#include <string>

int bord[4][4] = { {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };

// ������� �� �������� �� ���� ������ �� ���������� �������� ������
void addNewTile() {
    int emptyCells[16][2];
    int emptyCount = 0;

    // �������� �� ������ ������ ������
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (bord[i][j] == 0) {
                emptyCells[emptyCount][0] = i;
                emptyCells[emptyCount][1] = j;
                emptyCount++;
            }
        }
    }

    // �������� �� 2 � �������� ������ ������, ��� ��� �������
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

    // �������� �� ������� ��� ���������� ����� � ������
    addNewTile();
    addNewTile();

    while (!WindowShouldClose())
    {
        
        

        BeginDrawing();
        ClearBackground(BEIGE);

        // �������� � ������� �� ������
        DrawText("2048", 70, 100, 200, WHITE);
        DrawText("RULES:", 5, 340, 20, WHITE);


        // �������� �� ������ � ��������� �� ����������� �� `bord`
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                // �������� �� ������
                DrawRectangleLines(740 + j * 120, 125 + i * 120, 120, 120, WHITE);

                // ��������� �� �������� � �������� (��� ��� ������)
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
