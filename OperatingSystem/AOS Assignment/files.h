#include <stdio.h> 
#include <fcntl.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

void readFile(int argc, char *argv[]) {
    //./assgn file read file.txt start bytes
    if (argc != 6) {
        printf("Invalid number of arguments.\n");
    } else {
        // Open file in read-only mode
        int fd = open(argv[3], O_RDONLY);
        if (fd == -1) {
            printf("Error in opening file.\n");
        } else {
            // Convert string to integer for start, bytes
            int start = atoi(argv[4]);
            int nbytes = atoi(argv[5]);
            // Move pointer for random read
            if (start != 0) {
                lseek(fd, start, SEEK_SET);
            }
            int n, bytes_read = 0;
            char buff[1]; // Initialize buffer to store data
            printf("\nThe bytes read are: ");
            // Keep reading till the end of the file or max bytes to be read is reached 
            while (((n = read(fd, buff, 1)) > 0) && (bytes_read < nbytes)) {
                printf("%s", buff); 
                bytes_read += n;
            }
            // Print total bytes read
            printf("\n\nTotal bytes read: %d\n", bytes_read);
            // Close file
            if (close(fd) < 0) {
                printf("Error in closing file.\n");
            }
        }
    }
}

void infoFile(int argc, char *argv[]) {
    //./assgn file info file.txt
    if (argc != 4) {
        printf("Invalid number of arguments.");
    } else {
        // Define stat to store file info
        struct stat sfile;

        if (stat(argv[3], &sfile) == -1) {
            printf("Error Occurred\n");
        }
        printf("\nInformation for file: %s\n", argv[3]);

        // Accessing data members of stat struct
        printf("\nUser ID of owner: %d", sfile.st_uid);
        printf("\nBlocksize for system I/O: %d", sfile.st_blksize);
        printf("\nGroup ID of owner: %d", sfile.st_gid);
        printf("\nNumber of blocks allocated: %d", sfile.st_blocks);
        printf("\nTotal size, in bytes: %d", sfile.st_size);
        printf("\nNumber of hard links: %u", (unsigned int) sfile.st_nlink);
        printf("\nFile Permissions for User: ");
        printf((sfile.st_mode & S_IRUSR) ? "r" : "-");
        printf((sfile.st_mode & S_IWUSR) ? "w" : "-");
        printf((sfile.st_mode & S_IXUSR) ? "x" : "-");
        printf("\nFile Permissions for Group: ");
        printf((sfile.st_mode & S_IRGRP) ? "r" : "-");
        printf((sfile.st_mode & S_IWGRP) ? "w" : "-");
        printf((sfile.st_mode & S_IXGRP) ? "x" : "-");
        printf("\nFile Permissions for Other: ");
        printf((sfile.st_mode & S_IROTH) ? "r" : "-");
        printf((sfile.st_mode & S_IWOTH) ? "w" : "-");
        printf((sfile.st_mode & S_IXOTH) ? "x" : "-");

        printf("\n");
    }
}

mode_t toMode(char *perm) {
    // Converts string permission to mode_t format
    // Example: "rw-r--r--" to 0644
    int mode = 0;
    int index = 0;
    // Set user permissions
    if (perm[index] == 'r')
        mode |= S_IRUSR;
    if (perm[index + 1] == 'w')
        mode |= S_IWUSR;
    if (perm[index + 2] == 'x')
        mode |= S_IXUSR;

    index += 3;

    // Set group permissions
    if (perm[index] == 'r')
        mode |= S_IRGRP;
    if (perm[index + 1] == 'w')
        mode |= S_IWGRP;
    if (perm[index + 2] == 'x')
        mode |= S_IXGRP;

    index += 3;

    // Set other permissions
    if (perm[index] == 'r')
        mode |= S_IROTH;
    if (perm[index + 1] == 'w')
        mode |= S_IWOTH;
    if (perm[index + 2] == 'x')
        mode |= S_IXOTH;

    return (mode_t)mode;
}

void createFile(int argc, char *argv[]) {
    //./assgn file create file.txt permissions
    if (argc != 5) {
        printf("Invalid number of arguments.\n");
    } else {
        // Convert permission string to mode_t format
        mode_t mode = toMode(argv[4]);

        // Create file with specified permissions
        int fd = open(argv[3], O_CREAT | O_EXCL, mode);

        if (fd == -1) {
            printf("Error in creating file.\n");
        } else {
            printf("File created successfully.\n");
            // Close file
            if (close(fd) < 0) {
                printf("Error in closing file.\n");
            }
        }
    }
}

int findOpenMode(char *m) {
    // Find open mode based on input string
    if (strcmp(m, "r") == 0) {
        return O_RDONLY;
    } else if (strcmp(m, "w") == 0) {
        return O_WRONLY | O_CREAT | O_TRUNC;
    } else if (strcmp(m, "a") == 0) {
        return O_WRONLY | O_CREAT | O_APPEND;
    } else {
        return -1;
    }
}

void openAndCloseFile(int argc, char *argv[]) {
    //./assgn file open file.txt mode
    if (argc != 5) {
        printf("Invalid number of arguments.\n");
    } else {
        int mode = findOpenMode(argv[4]);
        if (mode == -1) {
            printf("Invalid mode.\n");
        } else {
            // Open file with specified mode
            int fd = open(argv[3], mode, 0644);
            if (fd == -1) {
                printf("Error in opening file.\n");
            } else {
                printf("File opened successfully.\n");
                // Close file
                if (close(fd) < 0) {
                    printf("Error in closing file.\n");
                }
            }
        }
    }
}

void writeFile(int argc, char *argv[]) {
    //./assgn file write file.txt start text
    if (argc != 5) {
        printf("Invalid number of arguments.\n");
    } else {
        // Open file in write mode
        int fd = open(argv[3], O_WRONLY);
        if (fd == -1) {
            printf("Error in opening file.\n");
        } else {
            // Convert string to integer for start
            int start = atoi(argv[4]);
            // Move pointer for random write
            if (start != 0) {
                lseek(fd, start, SEEK_SET);
            }
            // Write text to file
            if (write(fd, argv[5], strlen(argv[5])) == -1) {
                printf("Error in writing to file.\n");
            } else {
                printf("Text written to file successfully.\n");
            }
            // Close file
            if (close(fd) < 0) {
                printf("Error in closing file.\n");
            }
        }
    }
}
