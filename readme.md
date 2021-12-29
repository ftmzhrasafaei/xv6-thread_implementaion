# System Call implementation in XV6

Here, I implemented two system calls in xv6 operating system.

The files that I changed are commited as "2de version".
- getProcCount syscall: it calculates and returns the number of the processes in the system
- getReadCount syscall: it calculates and returns the number of times that the "sys_read" syscall is used. I used a variable named "read" to do so. You can use this syscall for other syscalls as well.
