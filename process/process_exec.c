#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    /* code */
    printf("hello word (pid:%d)\n", (int)getpid());
    int rc = fork();
    if (rc < 0)
    { // fork failed
        fprintf(stderr, "forked error\n");
        exit(0);
    }
    else if (rc == 0)
    { // child new process
        printf("hello, I'm a child of (pid: %d)\n", (int)getpid());
        char *myargs[3];
        myargs[0] = strdup("wc");             // program : wc (word count)
        myargs[1] = strdup("process_exec.c"); // argument: file to count
        myargs[2] = NULL;                     // marks end of array
        execvp(myargs[0], myargs);            // run word count
        printf("this should not print");
    }
    else if (rc > 0)
    { // main
        int wc = wait(NULL);
        printf("hello, I'm parent of %d (wc:%d) (pid:%d)\n", rc, wc, (int)getpid());
    }
    return 0;
}