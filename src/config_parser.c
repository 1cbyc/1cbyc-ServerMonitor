// #include "include/config_parser.h"
#include "config_parser.h"
#include <stdio.h>
#include <string.h>

int load_config(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("fopen");
        return 0;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("Config: %s", line);
    }

    fclose(file);
    return 1;
}