/*
    Minimal init for Docker containers.
    http://ewontfix.com/14/
*/
#define _XOPEN_SOURCE 700
#include <signal.h>
#include <unistd.h>

#include <stdlib.h> // exit
#include <stdio.h> // printf


/* Need a global for this so the signal handler knows who to talk to */
int child = 0;


/* Signal handler passes signal to child */
static void sig_handler(int sig) {
    int status;
    kill(child, sig);
    waitpid(child, &status, 0);
    exit(0);
}


int execute(sigset_t *pset, char *prog, char *argv[], char *env[]) {
    child = fork();
    if ( child > 1 ) {
        return child;
    } else if ( child < 0 ) {
        printf("fork failed\n");
        exit(EXIT_FAILURE);
    }
    // We're now in the child so need to exec the requested program
    sigprocmask(SIG_SETMASK, pset, 0);
    setsid();
    setpgid(0, 0);
    execvpe(prog, argv, env);
    printf("execvpe failed\n");
    exit(255);
}


int main(int argc, char *argv[], char *env[]) {
    sigset_t set, oldset;
    int status, child;

    if (getpid() != 1) {
        return 1;
    } else if ( argc < 2 ) {
        printf("Must supply a program to execute");
        exit(EXIT_FAILURE);
    }

    sigfillset(&set);
    sigdelset(&set, SIGINT); // Allow ctrl-c to work interactively
    sigdelset(&set, SIGTERM); // Allow docker stop
    sigprocmask(SIG_BLOCK, &set, &oldset);

    child = execute(&oldset, argv[1], argv + 1, env);
    signal(SIGINT, sig_handler);
    signal(SIGTERM, sig_handler);
    for ( ;; ) {
        if ( wait(&status) == child ) {
#ifdef RESTART
            sleep(1);
            child = execute(&set, argv[1], argv + 1, env);
#else
            exit(status);
#endif
        }
    }
}

