/* lib */
#include <stdio.h>
#include <stdlib.h>

/* struct */
typedef struct Process {
    int pid;                    // process id
    int burstTime;         
    int remainingTime;     
    int arrivalTime;       
    int waitingTime;       
    int turnaroundTime;    
    int responseTime;      
    int isCompleted;            // condition (completed/not completed)
} Process;

/* method(s) */
void minplus_FJFPreemptive(int x);
void initProcess(Process processes[], int n);
void executeProcess(Process processes[], int n);
void printProcess(Process processes[], int n);