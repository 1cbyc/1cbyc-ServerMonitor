#include "include/monitor.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int start_monitoring() {
    while (1) {
        struct sysinfo info;
        if (sysinfo(&info) != 0) {
            perror("sysinfo");
            return 0;
        }

        printf("Uptime: %ld seconds\n", info.uptime);
        printf("Total RAM: %lu MB\n", info.totalram / (1024 * 1024));
        printf("Free RAM: %lu MB\n", info.freeram / (1024 * 1024));

        sleep(5); // Refresh every 5 seconds
    }

    return 1;
}