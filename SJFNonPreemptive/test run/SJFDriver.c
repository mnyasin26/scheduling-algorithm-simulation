#include "SJFNonPreemptive.h"

int main(){

    process test;
    test.process_id = 1;
    test.burst_time = 10;
    test.waiting_time = 15;
    test.arrival_time =100;

    process arr[1] = {test};

    printTableForProcesses(arr);

    return 0;
}