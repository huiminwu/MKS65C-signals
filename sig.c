#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>

static void sighandler(int signo) {
    if(signo == SIGINT) {
        int fd = open("file.txt", O_APPEND | O_RDWR | O_CREAT);
        printf("Errno: %d\n", errno);
        if(errno != 0) {
            printf("%s\n", strerror(errno));
        }
        write(fd, "Program ended due to SIGINT\n", sizeof("Program ended dueto SIGINT\n"));
        printf("file.txt has been written in!\n");
        close(fd);
        exit(0);
    }
    if(signo == SIGUSR1) {
        printf("Parent process: %i\n", getppid());
    }
}

int main() {
    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);
    while(1) {
        printf("Process' PID: %d\n", getpid());
        sleep(1);
    }
    return 0;

}
