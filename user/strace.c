//STEP5
#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    if (argc < 2) {
        exit(1);
    }

    int pid = fork();

    if (pid == 0) {
        exec(argv[1], &argv[1]);
        exit(1);
    } else {
        trace(pid);
        wait(0);
    }

    exit(0);
}
