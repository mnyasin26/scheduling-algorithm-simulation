#include <stdio.h>
#include <string.h>

typedef struct
{
    int pid; // stands for process id
    int arrivalTime;
    int burstTime;
    int burstTimeLeft;
    int priority;
} process;

typedef struct
{
    int systemTime; // stands for process id
    int state; // 0 means "running", 1 means "available"
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

// simulation functions
void simulation();
