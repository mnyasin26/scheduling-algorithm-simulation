#include "../header.h"

typedef struct
{
    int pid;  // id proses
    int at;   // arrival time
    int bt;   // burst time
    int tuat; // turn around time
    int wt;   // waiting time
} data;

void FCFS();

void minPlusFCFS(int x);
void sorting(int n, data fcfs[n], int x);
void inputProcess(int n, data fcfs[n]);
void beginProcess(int n, data fcfs[n]);
void printProcess(int n, data fcfs[n]);
