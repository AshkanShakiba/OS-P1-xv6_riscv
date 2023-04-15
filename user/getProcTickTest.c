#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
    int pid = atoi(argv[1]);
    fprintf(2, "%d\n", getProcTick(pid));
    exit(0);
}
