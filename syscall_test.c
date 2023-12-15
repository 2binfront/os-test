#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

//#define __NR_open 5
//#define __O_RDONLY 

// A function to handle signals
void signal_handler(int signum) {
    printf("Received signal %d\n", signum);
    exit(1);
}

// A function to generate and execute a system call
void test_syscall(int number,long  arg1, long arg2, long arg3) {
    printf("Testing syscall %d with args %ld, %ld, %ld\n", number, arg1, arg2, arg3);
    long result = syscall(number, arg1, arg2, arg3);
    if (result == -1) {
        perror("Syscall failed");
    } else {
        printf("Syscall succeeded with result %ld\n", result);
    }
}

int main() {
    // Register signal handlers
    signal(SIGSEGV, signal_handler);
    signal(SIGILL, signal_handler);

    // Test valid open system call
   	test_syscall(SYS_open,(long) "/home/njucs/os-test/test.txt",O_RDONLY, 0777);
	

    // Test invalid system call number
    test_syscall(999, 0, 0, 0);

    // Test invalid file name pointer
    test_syscall(__NR_open, 0x12345678, O_RDONLY, 0);

    // Test invalid file mode
    test_syscall(__NR_open,(long) "./test.txt", 999, 0);

    // Test invalid file descriptor pointer
    test_syscall(__NR_open,(long) "./test.txt", O_RDONLY, 0x12345678);

    return 0;
}
