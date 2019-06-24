#include "ctrl_util.h"
#include <stdio.h>
#include <unistd.h>

int file_exists(const char* fn)
{
    return access(fn, F_OK) != -1;
}

int yesno(const char* msg)
{
    char answer = 0;
    while (answer != 'y' && answer != 'n')
    {
        printf("%s", msg);
        scanf("%c", &answer);
        fflush(stdout);
    }

    while ((getchar()) != '\n');

    return answer == 'y';
}