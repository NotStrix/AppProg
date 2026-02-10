#include <stdio.h>

int main() {
    int drivingSpeed;
    int speedLimit;
    int ticketCost;

    scanf("%d", &speedLimit);
    scanf("%d", &drivingSpeed);

    int speedDifference = drivingSpeed - speedLimit;

    if (speedDifference <= -10) {
        ticketCost = 50;
    } else if (speedDifference >= 6 && speedDifference <=20) {
        ticketCost = 75;
    } else if (speedDifference >= 21 && speedDifference <=40) {
        ticketCost = 150;
    } else if (speedDifference >= 41) {
        ticketCost = 300;
    } else {
        ticketCost = 0;
    }
    printf("%d\n", ticketCost);


    return 0;
}