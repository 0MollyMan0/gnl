#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int fd1, fd2;
    char *line;

    fd1 = open("test.txt", O_RDONLY);
    fd2 = open("one_line.txt", O_RDONLY);
    if (fd1 < 0 || fd2 < 0)
    {
        perror("open");
        return (1);
    }
    printf("---- Reading file1 ----\n");
    line = get_next_line(fd1);
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd1);
    }
    close(fd1);

    // printf("\n---- Reading file2 ----\n");
    // line = get_next_line(fd2);
    // while (line)
    // {
    //     printf("%s", line);
    //     free(line);
    //     line = get_next_line(fd2);
    // }
    // close(fd2);

    return 0;
}
