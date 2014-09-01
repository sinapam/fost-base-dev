/*
    Minimal init for Docker containers.
    http://ewontfix.com/14/
*/
#define _XOPEN_SOURCE 700
#include <signal.h>
#include <unistd.h>


int main(int argc, char *argv[], char *env[]) {
    sigset_t set;
    int status, child;

    if (getpid() != 1) {
        return 1;
    }

    sigfillset(&set);
    sigprocmask(SIG_BLOCK, &set, 0);

    child = fork();
    if ( child > 0 ) {
        for ( ;; ) {
            if ( wait(&status) == child ) {
                exit(status);
            }
        }
    } else {
        printf("fork failed\n");
        exit(EXIT_FAILURE);
    }

    sigprocmask(SIG_UNBLOCK, &set, 0);
    setsid();
    setpgid(0, 0);
    if ( argc > 1 ) {
        execve(argv[1], argv + 1, env);
        printf("execve failed\n");
        exit(EXIT_FAILURE);
    } else {
        return execve("/etc/rc", (char *[]){ "/etc/rc", 0 }, env);
    }
}
