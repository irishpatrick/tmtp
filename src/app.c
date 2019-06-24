#include <stdio.h>
#include <string.h>

#include "str_util.h"
#include "ctrl_util.h"
#include "generator.h"
#include "app.h"

const char* opts[] = {
    "new",
    "resize",
    "scale"
};

void print_options()
{
    printf("usage: ./tmtp <option> [filename]\n");
    printf("list of options:\n");
    int i;
    for (i = 0; i < NUM_OPTS; ++i)
    {
        printf("\t%s\n", opts[i]);
    }
}

void exec_option(const char* opt, const char* fn)
{
    int i;
    for (i = 0; i < NUM_OPTS; ++i)
    {
        if (!strcmp(opt, opts[i]))
        {
            break;
        }
    }
    switch (i)
    {
        case 0:
            new_template(fn);
            break;
        case 1:
            resize_template(fn);
            break;
        case 2:
            scale_template(fn);
            break;
        case NUM_OPTS:
            printf("invalid option!\n\n");
            print_options();
            break;
        default:
            printf("fatal error!\n");
    }
}

int main(int argc, char** argv)
{
    char* opt;
    char* fn = "";
    if (argc < 2)
    {
        print_options();
        return 0;
    }
    else
    {
       opt = argv[1];
    }
    if (argc > 2)
    {
        fn = argv[2];
    }

    exec_option(opt, fn);
    
    return 0;
}
