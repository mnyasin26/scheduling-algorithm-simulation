#include "../header.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int pid;  // id proses
    int at;   // arrival time
    int bt;   // burst time
    int tuat; // turn around time
    int wt;   // waiting time
} data;

void minPlusFCFS(int x);
void sorting(int n, data fcfs[], int x);
void inputProcess(int n, data fcfs[]);
void beginProcess(int n, data fcfs[]);
void printProcess(int n, data fcfs[]);

void FCFS();
