#include "SJFNonPreemptive.h"

int main (){

    showUpAndDownside();

    list L;
    createList(&L);

    int n;
    n = insert_sjf_process(&L);

    simulate_sjf_process_execution(L, n);
}