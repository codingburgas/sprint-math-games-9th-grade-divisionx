﻿#include "raylib.h"
#include <stdio.h>
#include <string>
#include <array>
using namespace std;

array<array<int, 4>, 4> bord = { 0 };


// Function to add a new tile to a random empty cell
void addNewTile() {
    int emptyCells[16][2];
    int emptyCount = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (bord[i][j] == 0) {
                emptyCells[emptyCount][0] = i;
                emptyCells[emptyCount][1] = j;
                emptyCount++;
            }
        }
    }

    if (emptyCount > 0) {
        int randomIndex = GetRandomValue(0, emptyCount - 1);
        int x = emptyCells[randomIndex][0];
        int y = emptyCells[randomIndex][1];
        bord[x][y] = 2;
    }
}

// Move and merge functions
void moveUp() {
    for (int j = 0; j < 4; j++) {
        for (int i = 1; i < 4; i++) {
            if (bord[i][j] != 0) {
                int k = i;
                while (k > 0 && bord[k - 1][j] == 0) {
                    bord[k - 1][j] = bord[k][j];
                    bord[k][j] = 0;
                    k--;
                }
                if (k > 0 && bord[k][j] == bord[k - 1][j]) {
                    bord[k - 1][j] *= 2;
                    bord[k][j] = 0;
                  
                }
            }
        }
    }
}

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

void moveDown() {
    for (int j = 0; j < 4; j++) 
    {
        for (int i = 2; i >= 0; i--) 
        {
            if (bord[i][j] != 0) {
                int k = i;
                while (k < 3 && bord[k + 1][j] == 0) 
                {
                    bord[k + 1][j] = bord[k][j];
                    bord[k][j] = 0;
                    k++;
                }
                if (k < 3 && bord[k][j] == bord[k + 1][j]) 
                {
                    bord[k + 1][j] *= 2;
                    bord[k][j] = 0;
                }
            }
        }
    }
}bool isThereChange(string  dir)
{
    array<array<int, 4>, 4> oldboard = bord;
    if (dir == "right")
    {
        moveRight();
    }
    else if(dir == "left")
    {
        moveLeft();
    }
    else if (dir == "up")
    {
        moveUp();
    }
    else
    {
        moveDown();
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (bord[i][j] != oldboard[i][j])
            {
                return(true);
            }

        }
    }
    return false;

}
//Change color when your archive highter numbers
Color getTileColor(int value) {
    switch (value) {
    case 0: return BROWN;
    case 2: return LIGHTGRAY;
    case 4: return GRAY;
    case 8: return ORANGE;
    case 16: return RED;
    case 32: return DARKPURPLE;
    case 64: return PURPLE;
    case 128: return YELLOW;
    case 256: return GOLD;
    case 512: return MAROON;
    case 1024: return DARKBLUE;
    case 2048: return GREEN;
    default: return BLACK; 
    }
}
//  Game over
bool isGameOver() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (bord[i][j] == 0) return false; 
            if (i < 3 && bord[i][j] == bord[i + 1][j]) return false; 
            if (j < 3 && bord[i][j] == bord[i][j + 1]) return false; 
        }
    }
    return true; 
}


int main() {
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "2048 Game");
    SetTargetFPS(60);

    int gameState = 0; 
    int menuSelection = 0;
   

    addNewTile();
    addNewTile();


    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BEIGE);
        


        if (gameState == 0) {
            // Menu
            if (IsKeyPressed(KEY_DOWN)) menuSelection = (menuSelection + 1) % 2;
            if (IsKeyPressed(KEY_UP)) menuSelection = (menuSelection - 1 + 2) % 2;

            DrawText("2048 GAME", screenWidth / 2 - 150, screenHeight / 3, 50, WHITE);
            DrawText("Start Game", screenWidth / 2 - 100, screenHeight / 2, 30, menuSelection == 0 ? YELLOW : GRAY);
            DrawText("Exit", screenWidth / 2 - 50, screenHeight / 2 + 50, 30, menuSelection == 1 ? YELLOW : GRAY);

            if (IsKeyPressed(KEY_ENTER)) {
                if (menuSelection == 0) {
                    gameState = 1; 
                }
                else {
                    break;
                }
            }
        }
        // Rulse
        else if (gameState == 1) { 
            DrawText("2048", 70, 100, 200, WHITE);
            DrawText("Rulse:The game concept is simple and complex at the same time. ", 5, 300, 20, WHITE);
            DrawText("To only rule of the game is that you have to", 5, 320, 20, WHITE);
            DrawText("merge 2 tiles with the same numerical value and then they become 1 tile ", 5, 340, 20, WHITE);
            DrawText(" with x2 of their original value then you have to merge this new x2 tile", 5, 360, 20, WHITE);
            DrawText(" with another x2 tile until you reach 2048.", 5, 380, 20, WHITE);
            DrawText("You cant continue the game?That isn't problem.", 5 , 400 ,20 ,WHITE);
            DrawText("Just preas R buton to reset the game.Don't thank me ;-).", 5, 420, 20, WHITE);
            //In renderring function(Draw):
            
           // Restart game
            if (IsKeyPressed(KEY_R))
            {
                bord = { 0 };
                addNewTile();
                addNewTile();
            }
           // Move blocks
            if (IsKeyPressed(KEY_RIGHT)) {
                if (isThereChange("right"))
                {
                    addNewTile();
                }
                
            }

            else if (IsKeyPressed(KEY_LEFT)) {
                if (isThereChange("left"))
                {
                    addNewTile();
                }
            }
            else if (IsKeyPressed(KEY_UP)) {
                if (isThereChange("up"))
                {
                    addNewTile();
                }
            }
            else if (IsKeyPressed(KEY_DOWN)) {
                if (isThereChange("down"))
                {
                    addNewTile();
                }
            }

            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    DrawRectangle(740 + j * 120, 125 + i * 120, 120, 120, getTileColor(bord[i][j]));
                    if (bord[i][j] != 0) {
                        DrawText(to_string(bord[i][j]).c_str(), 790 + j * 120, 165 + i * 120, 40, WHITE);
                    }
                }
            }
            if (isGameOver()) {
                DrawText("Game Over!", screenWidth / 2 - 150, screenHeight / 2, 50, RED);
                if (IsKeyPressed(KEY_ENTER)) {
                    gameState = 0; // Return to menu
                    bord = { 0 };
                    addNewTile();
                    addNewTile();
                }
            }
        }
       

        EndDrawing();
    }

    CloseWindow();
    
}