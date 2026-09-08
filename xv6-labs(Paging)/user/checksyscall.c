#include "kernel/types.h"
#include "kernel/riscv.h"
#include "kernel/memlayout.h"
#include "user/user.h"



int
main(int argc, char *argv[])
{
  struct usyscall *u;

  // Point our pointer to the virtual address
  u = (struct usyscall *)USYSCALL;

  printf("checksyscall starting...\n");
  
  // Read the PID from the shared page
  int pid_from_page = u->pid;
  
  // Get the PID from the system call
  int pid_from_syscall = getpid();

  printf("  PID from USYSCALL page: %d\n", pid_from_page);
  printf("  PID from getpid() syscall: %d\n", pid_from_syscall);

  if (pid_from_page == pid_from_syscall) {
    printf("checksyscall: OK\n");
  } else {
    printf("checksyscall: FAILED!\n");
  }
  
  exit(0);
}
