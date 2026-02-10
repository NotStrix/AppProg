#include <stdio.h>

int main() {
    char cmd;

    do {
        printf("Enter command: ");
        scand(" %c", &cmd);
    } while (cmd != 'X' && cmd != 'x');
    
}