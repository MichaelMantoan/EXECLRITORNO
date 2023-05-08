#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int pid;
    pid = fork();
    if (pid == 0)
    {
        execl("./a.out", "vocali.c", argv[1], NULL);
        exit(1);
    }

    if (pid > 0)
    {
        int status;
        waitpid(pid, &status, 0);
        if ((status >> 8) < 8)
        {
            printf("programma terminato trovando errori ");
        }
        else
        {
            printf("programma terminato con successo e il file %s contiene %d vocali", argv[1], status >> 8);
        }
    }
    return 0;
}