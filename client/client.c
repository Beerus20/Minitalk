#include "client.h"

int main(int argc, char **argv)
{
    printf("VALUE GOT   : [%s]\n", argv[1]);
    kill(atoi(argv[1]), SIGUSR1);
    return (0);
}
