#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "user.h"

struct proc_times {
    long burst_time;
    long turnaround_time;
    long waiting_time;
};

int main() {
  int i, n, pid;
  int processes_count = 32;

  toggleScheduler();
  for (i = 0; i < processes_count; i++) {
    pid = fork();
    if (pid < 0)
      return -1;
    else if (pid == 0) {
      for (i = 0; i < 100000000; i++)
        n++;
      exit(0);
    }
  }

  for (i = 0; i < processes_count; i++) {
    struct proc_times properties;
    pid = childWait(0, (uint64) &properties);
    printf("Process %d: {\n  Burst Time: %d,\n  Waiting Time: %d,\n  Turnaround Time: %d\n}\n",
           pid, properties.burst_time, properties.waiting_time, properties.turnaround_time);
  }

  exit(0);
}
