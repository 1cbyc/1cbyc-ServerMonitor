// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// int main() {
//     while (1) {
//         system("git add .");

//         system("git commit -m 'quick build'");

//         system("git push");

//         sleep(10);
//     }

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void run_command(const char *command) {
    int result = system(command);
    if (result != 0) {
        fprintf(stderr, "Error executing command: %s\n", command);
        exit(1);
    }
}

int main() {
    // Generate a commit message with the current date and time
    char commit_message[128];
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(commit_message, sizeof(commit_message), "Auto-commit on %Y-%m-%d %H:%M:%S", t);

    // Stage all changes
    printf("Staging changes...\n");
    run_command("git add .");

    // Commit changes
    char git_commit_command[256];
    snprintf(git_commit_command, sizeof(git_commit_command), "git commit -m \"%s\"", commit_message);
    printf("Committing with message: %s\n", commit_message);
    run_command(git_commit_command);

    // Push changes
    printf("Pushing changes...\n");
    run_command("git push");

    printf("commit completed successfully.\n");
    return 0;
}
