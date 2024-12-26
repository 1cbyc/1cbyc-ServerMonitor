#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    while (1) {
        system("git add .");

        system("git commit -m 'quick build'");

        system("git push");

        sleep(10);
    }

    return 0;
}
