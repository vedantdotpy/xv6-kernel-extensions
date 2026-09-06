
# xv6 Kernel Optimization: Shared Memory & Concurrency

This repository contains my modified version of the **xv6 operating system kernel** (RISC-V architecture).

The project focuses on two major areas of OS engineering: **Memory Management Optimization** and **Concurrency Control**. 
-----

## How to Build & Run

### Prerequisites

You need a RISC-V toolchain and QEMU.

  * **MacOS:** `brew install riscv-gnu-toolchain qemu`
  * **Linux:** `sudo apt-get install git build-essential gdb-multiarch qemu-system-misc gcc-riscv64-linux-gnu binutils-riscv64-linux-gnu`

### Compiling

To compile the kernel and build the file system image:

```bash
make clean
make qemu
```

### Running Tests

This project includes specific test suites to verify the optimizations.

**1. Test Page Tables & Shared Memory:**
Inside the xv6 shell (`$`), run:

```bash
$ pgtbltest
```

  * Verifies that the `USYSCALL` page is mapped with correct permissions (User-Read, Kernel-Write).
  * Prints the page table structure using the custom `vmprint` tool.

**2. Test Reader-Writer Locks:**
Inside the xv6 shell (`$`), run:

```bash
$ rwlktest
```

  * Spawns multiple processes on 4 CPUs.
  * Verifies that multiple readers can access the critical section simultaneously.
  * Verifies that a waiting writer successfully blocks new readers (Priority Check).

**3. Run All System Tests:**

```bash
$ usertests
```

  * Runs the standard xv6 test suite to ensure no regressions were introduced.

-----

## Technical Details

  * **Architecture:** RISC-V (64-bit)
  * **Memory Model:** Sv39 Paging
  * **Emulator:** QEMU
  * **Language:** C, RISC-V Assembly

## Acknowledgments

This project is based on the xv6-riscv operating system developed by MIT PDOS for the 6.S081 Operating Systems Engineering course.


