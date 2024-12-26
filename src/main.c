#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/monitor.h"
#include "include/logger.h"
#include "include/config_parser.h"
#include "include/alert_handler.h"

void print_usage(const char *prog_name) {
    printf("Usage: %s [options]\n", prog_name);
    printf("Options:\n");
    printf("  -c <config_file>  Specify the configuration file (default: config/server_monitor_config.ini)\n");
    printf("  -h                Display this help message\n");
}

int main(int argc, char *argv[]) {
    const char *config_file = "config/server_monitor_config.ini";

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-c") == 0 && i + 1 < argc) {
            config_file = argv[++i];
        } else if (strcmp(argv[i], "-h") == 0) {
            print_usage(argv[0]);
            return 0;
        } else {
            fprintf(stderr, "Unknown option: %s\n", argv[i]);
            print_usage(argv[0]);
            return 1;
        }
    }

    printf("Loading configuration from: %s\n", config_file);
    if (!load_config(config_file)) {
        fprintf(stderr, "Failed to load configuration\n");
        return 1;
    }

    printf("Starting monitoring...\n");
    if (!start_monitoring()) {
        fprintf(stderr, "Monitoring failed to start\n");
        return 1;
    }

    printf("Monitoring stopped.\n");
    return 0;
}
