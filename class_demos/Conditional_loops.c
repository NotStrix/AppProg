/*
Prompt user to enter single input char by an int n.
if not correct print error clear and repeat
F/f = factorial
input: F 5 = n! = 120
P/p = 2^n
input; p 2 = n^2 = 4
X/x = exit


*/

#include <stdio.h>

int main()
{
    int n;
    char cmd;
    int nv;

    do
    {
        printf("Enter Command and int: \n");
        nv = scanf(" %c %d", &cmd, &n);

        if (nv < 2)
        {
            printf("ERROR: Invalid Input!\n");

            char junk;
            do
            {
                scanf("%c", &junk);
            } while (junk != '\n');
        }
    } while (nv < 2);

    int result;
    int i;
    result = 1;

    switch (cmd)
    {
    case 'F':
    case 'f':
        for (i = 1; i <= n; i++)
        {
            result = result * i;
        }
        printf("%d! = %d\n", n, result);
        break;

    case 'P':
    case 'p':
        for (i = 1; i <= n; i++)
        {
            result = n * n;
        }
        printf("%d^2 = %d\n", n, result);
        break;

    case 'X':
    case 'x':
        printf("Exiting...\n");
        break;
    }

    return 0;
}