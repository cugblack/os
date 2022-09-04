#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    /* code */
    printf("hello word (pid:%d)\n", (int) getpid());
    int rc=fork();
    if (rc < 0) 
    {   // fork failed
        fprintf(stderr, "forked error\n");
        exit(0);
    } else if (rc == 0)
    {   // child new process
        printf("hello, I'm a child of (pid: %d)\n", (int) getpid());
        sleep(5);

    } else if (rc > 0)
    {   // main
        printf("hello, I'm parent of %d, (pid:%d)\n", rc, (int) getpid());
    }
    return 0;
}
