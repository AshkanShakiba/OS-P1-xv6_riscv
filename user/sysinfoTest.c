#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "../kernel/sysinfo.h"
#include "user.h"

int main(int argc, char **argv) {
    struct sysinfo si;
    sysinfo((uint64) &si);
    printf("uptime: %l\n"
           "total memory: %l\n"
           "free memory: %l\n"
           "active processes: %d\n",
           si.uptime,
           si.totalram,
           si.freeram,
           si.procs);
    exit(0);
}
