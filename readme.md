# Thread implementation in XV6

## General procedure

To implement the thread concept, I defined three functions. The thread_create function, which is the threat constructor function, the thread_wait function, and the check_pgdir_share function, which check which processes have the same address space. I also defined two variables stackTop and threads in struct proc. stackTop is used to allocate the address space from the parent process to the child thread, and the threads in the parent process determine the number of threads and in thes have a value of -1.

The difference between thread_create and the fork function is that in thread_create, the child thread and the parent process have a common address space.

In thread_wait, it is noted that it does not wait for child processes, and in wait, it is noted that it does not wait for threads. This is checked using threads variable.

The system call numbers for thread_create and thread_wait are defined as 52 and 53.

Then in the "sysproc.c" file in the sys_thread_create function I used the argptr function to get the pointer to the input stack of the thread_create function.

## Test

Two tests have been written to test this concept.

### threasTest

This test checks the performance of thread_creat and thread_wait system calls. This test uses the thread_creator function to create the corresponding stack and call the thread_creat function.

### threadFunctionalityTest

This test shows the concept of thread. In the parent process, the variable x changes and in the child thread, this variable is printed, indicating that the parent process and the child thread have access to a common address space.
