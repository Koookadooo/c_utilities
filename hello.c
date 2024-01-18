#include <stdio.h>

int main() {
    // Define variables
    int x = 12;
    float y = 3.14;
    const char* s = "Hello, world!";

    // Print variable values
    printf("x is %d, y is %.6f\n", x, y);
    printf("%s\n", s);

    // Print multiples of 5 using a loop
    for (int i = 0; i < 5; i++) {
        printf("%d x 5 = %d\n", i, i * 5);
    }

    return 0;
}
