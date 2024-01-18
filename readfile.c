#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 2) {
        write(1, "Usage: ./readfile <filename>\n", 30);
        exit(EXIT_FAILURE);
    }

    // Open the file
    const char *file = argv[1];
    int fd = open(file, O_RDONLY);
    
    // check for errors
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Read the file and write to screen
    char buffer[2048];
    ssize_t bytes_read;
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        write(1, buffer, bytes_read);
    }

    // Close the file
    close(fd);

    return 0;
}
