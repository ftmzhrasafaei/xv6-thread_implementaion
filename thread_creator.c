#include "types.h"
#include "stat.h"
#include "user.h"

#define PAGESIZE 4096


int
thread_creator(void (*fn)(void *), void *arg)
{
    //printf(1 , "THIS THREAD TEST\n");
    void *fptr = malloc(2 * (PAGESIZE));
    void *stack;

    if(fptr == 0)
        return -1;
    int mod = (uint)fptr % PAGESIZE;

    if(mod == 0)
        stack = fptr;
    else
        stack = fptr + (PAGESIZE - mod);
    //printf(1, "CALLING THREAD_CREATE\n");
    int thread_id = thread_create((void*)stack);
    //printf(1, "CALLED    %d\n" , thread_id);
    if(thread_id < 0)
        printf(1 ,"thread_create failed\n");
    else if(thread_id == 0){
        //printf(1, "THREAD_ID = 0");
        (fn)(arg);
        free(stack);
        exit();
    }
    return thread_id;
}