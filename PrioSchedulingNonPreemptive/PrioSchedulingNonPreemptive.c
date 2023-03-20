#include "../header.h"
#include "PrioSchedulingNonPreemptive.h"

void PrioSchedulingNonPreemptive(){
    printf("Hello, world");
    simulation();
}

void executeProcess(process *p, processor *executor){
    while(p->burstTimeLeft > 0){
        printf("time: %d executing process P%d\n", executor->systemTime, p->pid);
        executor->systemTime++;
        p->burstTimeLeft--;
    }
}

void simulation()
{
    queue q;
    createEmpty(&q);
    printQueue(q);
    processor executor = {executor.systemTime = 0, executor.state = 1};

    process p0 = {p0.pid = 0, p0.arrivalTime = 0, p0.burstTime = 2, p0.priority = 2};
    process p1 = {p1.pid = 1, p1.arrivalTime = 1, p1.burstTime = 6, p1.priority = 3};
    process p2 = {p2.pid = 2, p2.arrivalTime = 2, p2.burstTime = 4, p2.priority = 1};

    p0.burstTimeLeft = p0.burstTime;
    p1.burstTimeLeft = p1.burstTime;
    p2.burstTimeLeft = p2.burstTime;

    add(p0, &q);
    add(p1, &q);
    add(p2, &q);

    while (isEmpty(q) == 0)
    {
        process temp = popHighestPriority(&q);
        executeProcess(&temp,&executor);
    }

    printf("================\n");
    printf("Executor State\n");
    printf("system time : %d\n", executor.systemTime);

    // printQueue(q);
    // process temp = popHighestPriority(&q);
    // printQueue(q);

    // printf("================\n");
    // printf("Popped Element");
    // printf("pid : %d\n", temp.pid);
    // printf("priority : %d\n", temp.priority);
    // printf("arrival time : %d\n", temp.arrivalTime);
    // printf("burst time : %d\n", temp.burstTime);

    int i;
    scanf("%d", &i);
}