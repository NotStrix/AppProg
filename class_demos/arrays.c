#include <stdio.h>

int main()
{
    int i;
/*
    int arr[4] = {10, 30, 2160, -1}; // Initialize array with values

    for (i = 0; i < 4; i++)
    {
        printf("%d\n", arr[i]);
    }
*/
    int twoDarr[5][2] = {{10,10},
                         {20,20},
                         {30,30},
                         {40,40},
                         {50,50}}; // Initialize 2D array with values
    int j;

    for (i = 0; i < 5; i++){
        for (j = 0; j < 2; j++){
            printf("%d ", twoDarr[i][j]);
        }
        printf("\n");
    }

    return 0;
}