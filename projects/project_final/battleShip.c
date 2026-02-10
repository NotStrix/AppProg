#include <stdio.h>
#include <stdlib.h>

int main() {

    char playerGrid[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            playerGrid[i][j] = '*'; // Initialize grid with water symbol
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", playerGrid[i][j]);
        }
        printf("\n");
    }

    return 0;
}