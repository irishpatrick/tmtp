#include "str_util.h"
#include <string.h>

int startswith(const char* a, const char* prt)
{
    if (strlen(a) < strlen(prt))
    {
        return 0;
    }

    while (*a != 0)
    {
        if (*a != *prt)
        {
            return 0;
        }
        ++a;
        ++prt;
    }

    return 1;
}

int endswith(const char* a, const char* prt)
{
    if (strlen(a) < strlen(prt))
    {
        return 0;
    }

    a = a + strlen(a) - strlen(prt);

    while (*a != 0)
    {
        if (*a != *prt)
        {
            return 0;
        }
        ++a;
        ++prt;
    }

    return 1;
}