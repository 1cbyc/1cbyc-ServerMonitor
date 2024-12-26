#include "include/logger.h"
#include <stdio.h>
#include <stdarg.h>
#include <time.h>

void log_message(const char *format, ...) {
    FILE *log_file = fopen("log.txt", "a");
    if (!log_file) {
        perror("fopen");
        return;
    }

    time_t now = time(NULL);
    fprintf(log_file, "%s ", ctime(&now));

    va_list args;
    va_start(args, format);
    vfprintf(log_file, format, args);
    va_end(args);

    fprintf(log_file, "\n");
    fclose(log_file);
}