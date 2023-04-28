#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    for (int i = 0; i < 5; i++) {
        if (fork() == 0) {
            printf("PID: %d, PPID: %d - Process C%d\n", getpid(), getppid(), i+1);
            return 0;
        }
    }

    printf("PID: %d, PPID: %d - Process P\n", getpid(), getppid());
    for (int i = 0; i < 5; i++) {
        wait(NULL);
    }

    return 0;
}
