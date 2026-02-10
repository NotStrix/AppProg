/*
Jose Rosario, Almostapha Khyaty, Eyoale Teshager

ECE App Programming Final Project
BattleShip Game

Description: Very simple battleship game that is played on a 5x5 grid.
             The main game only has the user play against a computer that
             randomly places a ship on the grid. Each member has additional
             features such as play with cpu, decoy/hints, and a point system.

*/

#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int main()
{

    int choice;
    char playerGrid[5][5];
    char cpuGrid[5][5];
    char guessGrid[5][5];
    int shipsPlaced = 0;
    int playerShipsPlaced = 0;
    int hits = 0;
    int cpuHits = 0;
    int i, j;
    int decoyActive[5] = {0}; // Tracks active decoys in each column
    int missStreak = 0;
    int points = 0;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            cpuGrid[i][j] = '~';
            playerGrid[i][j] = '~';
            guessGrid[i][j] = '~';
        }
    }

    // Initalizes CPU Ships
    srand(time(NULL));
    while (shipsPlaced < 3)
    {
        int horizontal = rand() % 2; // 0 for vertical, 1 for horizontal
        int row = rand() % 5;
        int col = rand() % 5;

        if (horizontal && col < 4)
        {
            if (cpuGrid[row][col] == '~' && cpuGrid[row][col + 1] == '~')
            {
                cpuGrid[row][col] = 'S';
                cpuGrid[row][col + 1] = 'S';
                shipsPlaced++;
            }
        }
        else if (!horizontal && row < 4)
        {
            if (cpuGrid[row][col] == '~' && cpuGrid[row + 1][col] == '~')
            {
                cpuGrid[row][col] = 'S';
                cpuGrid[row + 1][col] = 'S';
                shipsPlaced++;
            }
        }
    }

    placeDecoys(cpuGrid, decoyActive, 3);

    int scanResult;
    do
    {
        printf("1. Play against CPU\n");
        printf("2. Play with CPU\n");
        printf("Enter your choice: ");

        scanResult = scanf("%d", &choice);
        if (scanResult != 1)
        {
            printf("Invalid input. Please enter 1 or 2.\n");
            while (getchar() != '\n')
                ;       // clear the rest of the line from the input buffer
            choice = 0; // repeats the loop
        }

    } while (choice != 1 && choice != 2);

    /* DEBUGGING PURPOSES!!
    // Prints CPU grid for testing purposes
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%c ", cpuGrid[i][j]);
        }
        printf("\n");
    }
    */

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%c ", guessGrid[i][j]);
        }
        printf("\n");
    }

    // Only player fights against CPU
    if (choice == 1)
    {
        hits = 0;
        missStreak = 0;

        while (hits < 6)
        {
            playerTurn(cpuGrid, guessGrid, decoyActive, &hits, &missStreak, &points);

            if (hits >= 6)
            {
                printf("\nYou sank all CPU ships! You win!\n");
                printf("Final Points: %d\n", points);
                break;
            }
        }
    }

    // CPU and Player fight each other
    else if (choice == 2)
    {
        // Player can place 3 ships of length 2 with different orientations
        while (playerShipsPlaced < 3)
        {
            char orientation;
            int row, col;
            int valid = 1;

            printf("\nPlacing ship %d of 3 (length 2)\n", playerShipsPlaced + 1);
            printf("Enter orientation (H for horizontal, V for vertical): ");
            scanf(" %c", &orientation);

            printf("Enter starting row and column (1-5 1-5): ");
            scanf("%d %d", &row, &col);

            // Allows 1-5 not 0-4
            row--;
            col--;

            if (orientation == 'H' || orientation == 'h') // Horizontal placement ex: 0 1 places ship at (0,1) and (0,2)
            {
                if (row < 0 || row > 4 || col < 0 || col + 1 > 4)
                {
                    printf("Out of bounds. Try again.\n");
                    valid = 0;
                }
                else if (playerGrid[row][col] != '~' || playerGrid[row][col + 1] != '~')
                {
                    printf("Overlaps another ship. Try again.\n");
                    valid = 0;
                }
                else if (valid)
                {
                    playerGrid[row][col] = 'S';
                    playerGrid[row][col + 1] = 'S';
                    playerShipsPlaced++;
                }
            }
            else if (orientation == 'V' || orientation == 'v') // Vertical placement ex: 1 2 places ship at (1,2) and (2,2)
            {
                if (row < 0 || row + 1 > 4 || col < 0 || col > 4)
                {
                    printf("Out of bounds. Try again.\n");
                    valid = 0;
                }
                else if (playerGrid[row][col] != '~' || playerGrid[row + 1][col] != '~')
                {
                    printf("Overlaps another ship. Try again.\n");
                    valid = 0;
                }
                else if (valid)
                {
                    playerGrid[row][col] = 'S';
                    playerGrid[row + 1][col] = 'S';
                    playerShipsPlaced++;
                }
            }
            else
            {
                printf("Invalid orientation. Use H or V.\n");
                valid = 0;
            }

            // Show player's grid after each placement
            printf("Your grid:\n");
            for (i = 0; i < 5; i++)
            {
                for (j = 0; j < 5; j++)
                {
                    printf("%c ", playerGrid[i][j]);
                }
                printf("\n");
            }
        }

        // Main game loop where player and CPU take turns
        hits = 0;
        cpuHits = 0;

        while (hits < 6 && cpuHits < 6)
        {
            // Players turn
            playerTurn(cpuGrid, guessGrid, decoyActive, &hits, &missStreak, &points);
            if (hits >= 6)
            {
                printf("\nYou sank all CPU ships! You win!\n");
                printf("Final Points: %d\n", points);
                break;
            }

            // CPUs turn
            printf("\nCPU's turn...\n");
            int cpuRow, cpuCol;
            do
            {
                cpuRow = rand() % 5;
                cpuCol = rand() % 5;
            } while (playerGrid[cpuRow][cpuCol] == 'X' || playerGrid[cpuRow][cpuCol] == 'O');

            printf("CPU fires at (%d, %d): ", cpuRow, cpuCol);

            if (playerGrid[cpuRow][cpuCol] == 'S')
            {
                printf("Hit!\n");
                playerGrid[cpuRow][cpuCol] = 'X';
                cpuHits++;
            }
            else if (playerGrid[cpuRow][cpuCol] == '~')
            {
                printf("Miss.\n");
                playerGrid[cpuRow][cpuCol] = 'O';
            }

            printf("Your grid (X = CPU hit, O = CPU miss):\n");
            for (i = 0; i < 5; i++)
            {
                for (j = 0; j < 5; j++)
                {
                    printf("%c ", playerGrid[i][j]);
                }
                printf("\n");
            }

            if (cpuHits >= 6)
            {
                printf("\nThe CPU sank all your ships. You lose.\n");
                printf("Final Points: %d\n", points);
                break;
            }
        }
    }

    return 0;
}