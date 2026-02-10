#include <stdio.h>

int main() {
    int i, iSquared;
    i = 0;

    for (i = 0; i <=10; i++) {
        iSquared = i * i;
        printf("%d squared is %d\n", i, iSquared);
    }

    return 0;
}

/* ++i vs i++:
    ++i increments i before its value is used in an expression.
    i++ increments i after its value is used in an expression.
    In a for loop, both have the same effect because the increment happens at the end of each iteration.
*/