#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int fd1, fd2, fd3, fd4;
    char *line;

    fd1 = open("test.txt", O_RDONLY);
    fd2 = open("one_line_no_nl.txt", O_RDONLY);
    fd3 = open("nothing.txt", O_RDONLY);
    fd4 = open("one_line_with_nl.txt", O_RDONLY);
    if (fd1 < 0 || fd2 < 0)
    {
        perror("open");
        return (1);
    }
    printf("---- normal ----\n");
    line = get_next_line(fd1);
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd1);
    }
    close(fd1);
    printf("\n---- one line no nl ----\n");
    line = get_next_line(fd2);
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd2);
    }
    close(fd2);
    printf("\n---- nothing ----\n");
    line = get_next_line(fd3);
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd3);
    }
    close(fd3);
    printf("\n---- one line with nl ----\n");
    line = get_next_line(fd4);
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd4);
    }
    close(fd4);
    return 0;
}
