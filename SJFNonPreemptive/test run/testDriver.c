#include "SJFNonPreemptive.h"

int main (){

    list process_list;
    int n_process;
    createList(&process_list);
    insert_sjf_Process(&n_process,&process_list);
    simulate_sjf_process_execution(process_list,n_process);
}