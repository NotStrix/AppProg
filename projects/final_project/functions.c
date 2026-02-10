#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void playerTurn(char cpuGrid[5][5],
                char guessGrid[5][5],
                int decoyActive[5],
                int *hits,
                int *missStreak,
                int *points)
{
    int guessRow, guessCol;
    int i, j;
    int validGuess = 0;

    do
    {
        printf("Enter your guess (row and column, 1-5): ");
        if (scanf("%d %d", &guessRow, &guessCol) != 2) // Makes sure input is valid (numbers only)
        {
            printf("Invalid input. Numbers only.\n");
            while (getchar() != '\n')
                ;
            continue;
            ;
        }

        if (guessRow < 1 || guessRow > 5 || guessCol < 1 || guessCol > 5) // Makes sure input is within bounds
        {
            printf("Invalid input. Please enter values between 1 and 5.\n");
            continue;
        }
        if (guessGrid[guessRow - 1][guessCol - 1] != '~')
        {
            printf("You already guessed that position. Try again.\n");
            continue;
        }

        validGuess = 1;

    } while (!validGuess);

    // Allows user to input 1-5 rather than 0-4
    guessRow--;
    guessCol--;

    if (cpuGrid[guessRow][guessCol] == 'S') // Checks if its a ship
    {
        printf("Hit!\n");
        guessGrid[guessRow][guessCol] = 'X'; // Leaves an X for hit
        cpuGrid[guessRow][guessCol] = 'x';
        (*hits)++;
        (*points) += 10;
        printf("+10 points\n");
        *missStreak = 0; // reset miss streak on hit
    }
    else if (cpuGrid[guessRow][guessCol] == 'D') // Checks if its a decoy
    {

        printf("Decoy hit! revealing intel...\n");

        for (int k = 0; k < 5; k++)
        {
            if (columnHasShip(cpuGrid, k)) // provide hint if a ship is in the column
            {
                printf("Hint: Radar detects a ship in column %d!\n", k + 1);
                break; // Stop after finding one column
            }
        }
        cpuGrid[guessRow][guessCol] = 'd';
        guessGrid[guessRow][guessCol] = 'D';
        decoyActive[guessCol] = 0;
        (*points) += 5;
        printf("+5 points\n");
        *missStreak = 0;
    }
    else // Miss case
    {
        printf("Miss.\n");
        guessGrid[guessRow][guessCol] = 'O';
        (*missStreak)++; // increment miss streak on miss

        if (*points <= 0)
        {
            *points = 0;
        }
        else
        {
            *points -= 2;
            printf("-2 points\n");
        }
        if (*missStreak >= 3)
        { // provide hint after 3 consecutive misses
            printf("You've missed multiple times in a row! Here's a hint:\n");
            for (int k = 0; k < 5; k++)
            {
                if (columnHasShip(cpuGrid, k))
                {
                    printf("Hint: Radar detects a ship in column %d!\n", k + 1);
                    break; // Stop after finding the first one
                }
            }
            if (*points >= 10)
            {
                printf("Miss Streak: -10 points\n");
                *points -= 10;
            }
            else
            {
                printf("Miss Streak: -%d points\n", *points);
                *points = 0;
            }
        }
    }
    for (i = 0; i < 5; i++)
    { // prints an updates guess grid
        for (j = 0; j < 5; j++)
        {
            printf("%c ", guessGrid[i][j]);
        }
        printf("\n");
    }
}

void placeDecoys(char cpuGrid[5][5], int decoyActive[5], int numDecoys)
{ // function to place decoys at the start of the game

    int placed = 0;

    while (placed < numDecoys)
    {
        int row = rand() % 5;
        int col = rand() % 5;

        if (cpuGrid[row][col] == '~') // place decoy only on empty spots
        {
            cpuGrid[row][col] = 'D'; // 'D' represents a decoy
            decoyActive[col] = 1;    // mark this decoy as active
            placed++;
        }
    }
}

int columnHasShip(char cpuGrid[5][5], int col) // function to check if a column has a ship
{

    int i;

    for (i = 0; i < 5; i++)
    {
        if (cpuGrid[i][col] == 'S')
        {
            return 1;
        } // ship found in the column
    }
    return 0;
}
