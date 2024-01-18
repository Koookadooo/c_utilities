#include <stdio.h>

int main(int argc, char *argv[]) {
    // Print the program name
    printf("0: %s\n", argv[0]);

    // Print command line arguments
    for (int i = 1; i < argc; i++) {
        printf("%d: %s\n", i, argv[i]);
    }

    return 0;
}