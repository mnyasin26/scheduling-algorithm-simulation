/* lib */
#include <stdio.h>
#include <stdlib.h>

/* struct */
typedef struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
    int responseTime;
    int isCompleted;
} Process;

/* method(s) */
void minplus_FJFPreemptive(int x);
void initProcessSJFP(Process processes[], int n);
void executeProcessSJFP(Process processes[], int n);
void printProcessSJFP(Process processes[], int n);