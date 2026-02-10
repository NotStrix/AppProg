#include <stdio.h>

int main() {
    int x;
    int y;
    int iterations = 0;

    scanf("%d %d", &x, &y);
    printf("Initially: x = %d y = %d\n", x, y);

    while (x<= y) {
        x = x + 1;
        y = y - 1;
        iterations = iterations + 1;
    }

    printf("iterations: %d\n", iterations);
    printf("Finally: x = %d y = %d\n", x, y);
    return 0;
}