/**
 * example.c
 * Copyright (c) 2025 Your Name
**/


#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


bool example(FILE *input, char *path)
{
    int c;
    while ((c = fgetc(input)) != EOF) {
        putchar(c);
    }
    if (ferror(input)) {
        fprintf(stderr, "error while reading from %s\n", path);
        return false;
    }
    return true;
}

bool handle_option(char *option)
{
    if (strncmp(option, "-", 2) == 0) {
        return example(stdin, "stdin");
    }
    return true;
}

bool handle_arg(char *arg)
{
    if (arg[0] == '-') {
        return handle_option(arg);
    }
    FILE *file = fopen(arg, "r");
    if (file == NULL) {
        perror(arg);
        return false;
    }
    bool result = example(file, arg);
    fclose(file);
    return result;
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        return example(stdin, "stdin") ? EXIT_SUCCESS : EXIT_FAILURE;
    }
    for (size_t i = 1; i < argc; i++) {
        if (!handle_arg(argv[i])) {
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}
