#include "types.h"
#include "stat.h"
#include "user.h"



void childPrint(void* args){
    printf(1 , "HI, childs function executed properly with arguments : %d\n" , *(int*) args);

}


int main(void){
    int argument = 0x0F01; //3841
    int thread_id =  thread_creator(&childPrint , (void*)&argument);
    //printf(1, "LESTS SEEEEEEEEEEE , %d\n " , thread_id);
    if(thread_id < 0)
        printf(1, "Thread Creatation Failded\n ");
   // printf(1 , "before wait \n");
    thread_wait();
   // printf(1 , "thread ID in test : %d \n" , thread_id);
   // printf(1,"going to exit\n");
    
    exit();
}