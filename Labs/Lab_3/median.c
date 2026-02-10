#include <stdio.h>

int main() {

    int a, b, c;
    int median;
    printf("Enter three integers: \n");
    scanf("%d %d %d", &a, &b, &c);

    if ((a >= b && a <= c) || (a <= b && a >= c)) {
        median = a;
    } else if ((b >= a && b <= c) || (b <= a && b >= c)) {
        median = b;
    } else {
        median = c;
    }

    printf("The median is %d\n", median);
    return 0;

}