#include "SJFNonPreemptive.h"

int main(){

    process arr[1];
    arr[0].process_id = 1;
    arr[0].burst_time = 10;
    arr[0].waiting_time = 15;
    arr[0].arrival_time =100;

    printTableForProcesses(arr, 1);

    return 0;
}