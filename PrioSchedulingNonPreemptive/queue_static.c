
#include "PrioSchedulingNonPreemptive.h"

void createEmpty(queue *Q)
{
    (*Q).first = -1;
    (*Q).last = -1;
}

int isEmpty(queue Q)
{
    int hasil = 0;
    if (Q.first == -1)
    {
        hasil = 1;
    }
    return hasil;
}

int isFull(queue Q)
{
    int hasil = 0;
    if (Q.last == 9)
    {
        hasil = 1;
    }
    return hasil;
}

void add(process p, queue *Q)
{
    if (isEmpty(*Q) == 1)
    {
        // Jika queue kosong
        // printf("Queue penuh\n");
        (*Q).first = 0;
        (*Q).last = 0;
        
        Q->data[0] = p;
    }
    else
    {
        if (isFull(*Q) != 1)
        {
            (*Q).last++;
            Q->data[Q->last] = p;
        }
        else
        {
            printf("queue penuh\n");
        }
    }
}

void del(queue *Q)
{
    if ((*Q).last == 0)
    {
        (*Q).first = -1;
        (*Q).last = -1;
    }
    else
    {
        int i;
        for (i = (*Q).first + 1; i < (*Q).last; i++)
        {
            Q->data[i - 1] = Q->data[i];
        }
        (*Q).last = (*Q).last - 1;
    }
}

process popDel(int index, queue *Q)
{
    if (Q->first != -1)
    {
        process temp;

        if (Q->last == 0)
        {
            Q->first = -1;
            Q->last = -1;
            temp = Q->data[0];
        }
        else
        {
            int i;
            temp = Q->data[index];
            if (index != Q->last)
            {
                for (i = index; i < Q->last; i++)
                {
                    Q->data[i] = Q->data[i + 1];
                }
            }
            Q->last = Q->last - 1;
        }
        return temp;
    }
    else
    {
        // proses jika stack kosong
        printf("queue kosong\n");
    }
};

process popHighestPriority(queue *Q){
    if (Q->first != -1)
    {
        process temp;
        int i;
        int index = Q->first;
        int maxPrio = Q->data[Q->first].priority;
        for (i = Q->first; i <= Q->last; i++)
        {
            if (Q->data[i].priority < maxPrio)
            {
                maxPrio = Q->data[i].priority;
                index = i;
            }
        }

        if (Q->last == 0)
        {
            Q->first = -1;
            Q->last = -1;
            temp = Q->data[0];
        }
        else
        {
            int i;
            temp = Q->data[index];
            if (index != Q->last)
            {
                for (i = index; i < Q->last; i++)
                {
                    Q->data[i] = Q->data[i + 1];
                }
            }
            Q->last = Q->last - 1;
        }
        return temp;
    }
    else
    {
        // proses jika stack kosong
        printf("queue kosong\n");
    }
};

void printQueue(queue Q)
{
    if (Q.first != -1)
    {
        printf("------isi queue------\n");
        int i;
        for (i = Q.first; i <= Q.last; i++)
        {
            printf("================\n");
            printf("elemen ke : %d\n", i);
            printf("pid : %d\n", Q.data[i].process_id);
            printf("priority : %d\n", Q.data[i].priority);
            printf("arrival time : %d\n", Q.data[i].arrival_time);
            printf("burst time : %d\n", Q.data[i].burst_time);
            printf("wait time : %d\n", Q.data[i].waiting_time);
            printf("turn around time : %d\n", Q.data[i].turnaround_time);
        }
        printf("---------------------\n");
    }
    else
    {
        // proses jika stack kosong
        printf("queue kosong\n");
    }
}

// int main()
// {
//     queue Q;
//     createEmpty(&Q);
//     printQueue(Q);
//     printf("=================\n");
//     add("13507701", "Nana", 64.75, &Q);
//     add("13507702", "Rudi", 75.11, &Q);
//     add("13507703", "Dea", 84.63, &Q);
//     printQueue(Q);
//     printf("=================\n");
//     del(&Q);
//     del(&Q);
//     printQueue(Q);
//     printf("=================\n");
//     return 0;
// }