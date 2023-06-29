#include "../kernel/types.h"
#include "../kernel/memlayout.h"
#include "user.h"

void
test(int test_num) {
  uint64 phys_size = PHYSTOP - KERNBASE;
  int sz = (phys_size / 3) * 2;
  char *p = sbrk(sz);
  if (p == (char *) 0xffffffffffffffffL) {
    printf("Error: sbrk(%d) failed\n", sz);
    exit(-1);
  }
  for (char *q = p; q < p + sz; q += 4096) {
    *(int *) q = getpid();
  }
  int pid = fork();
  if (pid < 0) {
    printf("Error: fork() failed\n");
    exit(-1);
  }
  if (pid == 0) {
    exit(0);
  }
  wait(0);
  if (sbrk(-sz) == (char *) 0xffffffffffffffffL) {
    printf("Error: sbrk(-%d) failed\n", sz);
    exit(-1);
  }
  printf("Test #%d Result: OK\n", test_num);
}

int
main(int argc, char *argv[]) {
  test(1);
  test(2);
  printf("All Tests OK\n");
  return 0;
}
