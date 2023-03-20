#include "../header.h"
#include "PrioSchedulingNonPreemptive.h"

void PrioSchedulingNonPreemptive()
{
    // printf("Hello, world");
    simulation();
}

int checkProcess(processor *executor, queue *q)
{
    for (int i = q->first; i <= q->last; i++)
    {
        if (executor->systemTime >= q->data[i].arrivalTime)
        {
            return 1;
        }
    }
}

// TODO layout formatting
void executeProcess(process *p, processor *executor, queue *q, queue *processDone)
{

    Sleep(1000);
    printf("*time: %d executing process P%d time left = %d\n", executor->systemTime, p->pid, p->burstTimeLeft);
    p->burstTimeLeft--;
    p->turnAroundTime++;

    if (isEmpty(*q) == 0)
    {
        for (int i = q->first; i <= q->last; i++)
        {
            if (executor->systemTime >= q->data[i].arrivalTime)
            {
                // printf("time: %d in queue: P%d wait time = %d turn around time = %d\n", executor->systemTime, q->data[i].pid, q->data[i].waitTime, q->data[i].turnAroundTime);
                q->data[i].waitTime++;
                q->data[i].turnAroundTime++;
            }
        }

        // while (state == 0)
        // {
        //     // printf("time: %d\n", executor->systemTime, p->pid);
        //     executor->systemTime++;
        //     for (int i = q->first; i <= q->last; i++)
        //     {
        //         // printf("test\n");
        //         if (executor->systemTime >= q->data[i].arrivalTime)
        //         {
        //             state = 1;
        //             break;
        //         }
        //     }
        // }
    }
}

void simulation()
{
    queue q;
    queue processDone;
    createEmpty(&q);
    createEmpty(&processDone);
    printQueue(q);
    printf("Processing Begin\n");
    processor executor = {executor.systemTime = 0, executor.state = 1};

    process p0 = {p0.pid = 0, p0.priority = 2, p0.arrivalTime = 0, p0.burstTime = 2, p0.burstTimeLeft = 0, p0.waitTime = 0, p0.turnAroundTime = 0};
    process p1 = {p1.pid = 1, p1.priority = 3, p1.arrivalTime = 1, p1.burstTime = 6, p1.burstTimeLeft = 0, p1.waitTime = 0, p1.turnAroundTime = 0};
    process p2 = {p2.pid = 2, p2.priority = 1, p2.arrivalTime = 2, p2.burstTime = 4, p2.burstTimeLeft = 0, p2.waitTime = 0, p2.turnAroundTime = 0};

    p0.burstTimeLeft = p0.burstTime;
    p1.burstTimeLeft = p1.burstTime;
    p2.burstTimeLeft = p2.burstTime;

    queue listProcess;
    createEmpty(&listProcess);

    add(p0, &listProcess);
    add(p1, &listProcess);
    add(p2, &listProcess);

    printQueue(listProcess);

    int jumlahProcess = 3;
    int state = 0;
    process temp1;
    process temp2;
    while (state == 0)
    {
        if (isEmpty(listProcess) == 0)
        {
            for (int i = listProcess.first; i <= listProcess.last; i++)
            {
                if (executor.systemTime >= listProcess.data[i].arrivalTime)
                {
                    temp1 = popDel(i, &listProcess);
                    add(temp1, &q);
                    printf("process P%d arrived\n", temp1.pid);
                    i--;
                }
            }
        }

        if (executor.state == 1)
        {
            if (isEmpty(q) == 0)
            {
                temp2 = popHighestPriority(&q);
                executor.state = 0;
            }
        }
        if (temp2.burstTimeLeft > 0)
        {
            executeProcess(&temp2, &executor, &q, &processDone); /* code */
        }
        
        if (executor.state == 1)
        {
            Sleep(1000);
            printf("*time: %d no process is executed\n", executor.systemTime);
        }
        

        if (temp2.burstTimeLeft == 0)
        {
            add(temp2, &processDone);
            executor.state = 1;
        }
        

        if (isEmpty(listProcess) == 1 && isEmpty(q) == 1 && executor.state == 1)
        {
            state = 1;
        }

        executor.systemTime++;
    }

    // add(p0, &q);
    // add(p1, &q);
    // add(p2, &q);

    // while (isEmpty(q) == 0)
    // {
    //     while (checkProcess(&executor, &q) != 1)
    //     {
    //         executor.systemTime++;
    //     }
    //     executeProcess(&temp,&executor,&q,&processDone);
    //     add(temp, &processDone);
    // }

    printf("================\n");
    printf("Executor State\n");
    printf("system time : %d\n", executor.systemTime);

    printQueue(processDone);

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