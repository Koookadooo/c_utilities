#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc == 1) {
        // No file specified, read from stdin
        int fd = 0; // file descriptor for stdin

        // Read and write loop
        char buffer[2048];
        ssize_t bytes_read;

        while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
            write(1, buffer, bytes_read);
        }

        if (bytes_read == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
    } else {
        // Loop through the files specified on the command line
        for (int i = 1; i < argc; i++) {
            // Open the file
            const char *file = argv[i];
            int fd = open(file, O_RDONLY);

            // Check for errors
            if (fd == -1) {
                perror("open");
                exit(EXIT_FAILURE);
            }

            // Read and write loop
            char buffer[2048];
            ssize_t bytes_read;

            while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
                write(1, buffer, bytes_read);
            }

            if (bytes_read == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            }

            // Close the file
            close(fd);
        }
    }

    return 0;
}