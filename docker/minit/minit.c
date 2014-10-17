/*
    Minimal init for Docker containers.
    http://ewontfix.com/14/
*/
#define _XOPEN_SOURCE 700
#include <signal.h>
#include <unistd.h>

#include <stdlib.h> // exit
#include <stdio.h> // printf


int execute(sigset_t *pset, char *prog, char *argv[], char *env[]) {
    int child = fork();
    if ( child > 1 ) {
        return child;
    } else if ( child < 0 ) {
        printf("fork failed\n");
        exit(EXIT_FAILURE);
    }
    // We're now in the child so need to exec the requested program
    sigprocmask(SIG_UNBLOCK, pset, 0);
    setsid();
    setpgid(0, 0);
    execvpe(prog, argv, env);
    printf("execvpe failed\n");
    exit(255);
}


int main(int argc, char *argv[], char *env[]) {
    sigset_t set;
    int status, child;

    if (getpid() != 1) {
        return 1;
    } else if ( argc < 2 ) {
        printf("Must supply a program to execute");
        exit(EXIT_FAILURE);
    }

    sigfillset(&set);
    sigprocmask(SIG_BLOCK, &set, 0);

    child = execute(&set, argv[1], argv + 1, env);
    for ( ;; ) {
        if ( wait(&status) == child ) {
#ifdef RESTART
            child = execute(&set, argv[1], argv + 1, env);
#else
            exit(status);
#endif
        }
    }
}
