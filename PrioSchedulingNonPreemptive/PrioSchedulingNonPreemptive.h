#include <stdio.h>
#include <string.h>

typedef struct
{
    int pid; // stands for process id
    int priority; // prioritas proses
    int arrivalTime;
    int burstTime;
    int burstTimeLeft; // burst time left digunakan untuk kegiatan eksekusi
    int waitTime;
    int turnAroundTime;
} process;

typedef struct
{
    int systemTime; // stands for real system time
    int state;      // 0 means "running", 1 means "available"
} processor;

typedef struct
{
    int first;
    int last;
    process data[10];
} queue;

// Queue functions
void createEmpty(queue *Q);
int isEmpty(queue Q);
int isFull(queue Q);
void add(process p, queue *Q);
void del(queue *Q);
void printQueue(queue Q);
process popHighestPriority(queue *Q);
process popDel(int index, queue *Q);

// simulation functions
void simulation(processor *executor, queue *listProcess);
void executeProcess(process *p, processor *executor, queue *q);
