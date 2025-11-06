#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int fd1, fd2;
    char *line;

    if (argc < 3)
    {
        printf("Usage: %s file1 file2\n", argv[0]);
        return (1);
    }

    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_RDONLY);
    if (fd1 < 0 || fd2 < 0)
    {
        perror("open");
        return (1);
    }

    printf("---- Reading file1 ----\n");
    while ((line = get_next_line(fd1)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd1);

    printf("\n---- Reading file2 ----\n");
    while ((line = get_next_line(fd2)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd2);

    return 0;
}
