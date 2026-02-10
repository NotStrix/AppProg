#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void playerTurn(char cpuGrid[5][5],
                char guessGrid[5][5],
                int decoyActive[5],
                int *hits,
                int *missStreak,
                int *points);

void placeDecoys(char cpuGrid[5][5], int decoyActive[5], int numDecoys);
int columnHasShip(char cpuGrid[5][5], int col);

#endif
