#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(int ac, char **av)
{
    int pid = fork();
    if (pid == -1)
        return -1;

    printf("Hello form processes %d\n", getpid());
    if (pid != 0)
        wait(NULL);
 return 0;   
}