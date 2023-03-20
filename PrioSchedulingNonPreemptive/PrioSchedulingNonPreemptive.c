#include "../header.h"
#include "PrioSchedulingNonPreemptive.h"

void PrioSchedulingNonPreemptive()
{
    // Executor bertindak sebagai "processor" yang bertugas untuk mengeksekusi process
    processor executor = {executor.systemTime = 0, executor.state = 1};

    // Process p-n adalah perwujudan dari proses dengan berbagai atributnya
    process p0 = {p0.pid = 0, p0.priority = 2, p0.arrivalTime = 0, p0.burstTime = 2, p0.burstTimeLeft = 0, p0.waitTime = 0, p0.turnAroundTime = 0};
    process p1 = {p1.pid = 1, p1.priority = 3, p1.arrivalTime = 1, p1.burstTime = 6, p1.burstTimeLeft = 0, p1.waitTime = 0, p1.turnAroundTime = 0};
    process p2 = {p2.pid = 2, p2.priority = 1, p2.arrivalTime = 2, p2.burstTime = 4, p2.burstTimeLeft = 0, p2.waitTime = 0, p2.turnAroundTime = 0};

    // set BurstTimeLeft untuk keperluan pemrosesan
    p0.burstTimeLeft = p0.burstTime;
    p1.burstTimeLeft = p1.burstTime;
    p2.burstTimeLeft = p2.burstTime;

    // buat queue untuk tempat penyimpanan sementara untuk process (bukan ready queue)
    queue listProcess;
    createEmpty(&listProcess);

    add(p0, &listProcess);
    add(p1, &listProcess);
    add(p2, &listProcess);

    // panggil prosedur simulasi
    simulation(&executor, &listProcess);
}

// TODO layout formatting with table and gantt chart
void simulation(processor *executor, queue *listProcess)
{
    queue q;           // (ready queue)
    queue processDone; // (terminated queue)
    createEmpty(&q);
    createEmpty(&processDone);
    printQueue(q);
    printf("Processing Begin\n");

    // menampilkan prosess awal setelah masukan user
    printQueue(*listProcess);

    // variabel bantu
    int state = 0;
    process temp1;
    process temp2;

    // inti pemrosesan
    while (state == 0)
    {
        // cek apakah "new" queue kosong, jika kosong maka cek isinya
        // apakah ada process yang arrival time nya
        // sama atau lebih dari systemTime executor
        if (isEmpty(*listProcess) == 0)
        {
            for (int i = listProcess->first; i <= listProcess->last; i++)
            {
                if (executor->systemTime >= listProcess->data[i].arrivalTime)
                {
                    // jika ada maka masukkan proses tersebut ke "ready" queue, dan keluarkan dari listProcess
                    temp1 = popDel(i, listProcess);
                    add(temp1, &q);
                    printf("process P%d arrived\n", temp1.pid); // tampilkan bahwa process arrived
                    i--;
                }
            }
        }

        // jika CPU sedang tidak mengerjakan proses
        // maka ambil process yang memiliki prioritas paling tinggi pada "ready" queue
        // jika pada "ready" queue terdapat proses
        if (executor->state == 1)
        {
            if (isEmpty(q) == 0)
            {
                temp2 = popHighestPriority(&q);
                executor->state = 0;
            }
        }

        // pada bagian ini dipastikan bahwa ada proses yang sedang dieksekusi
        // berfungsi untuk memproses proses dengan cara
        // mengurangi -1 burstTimeLeft dari proses yang ada pada variabel temp2
        // dan menambah +1 wait time dan turn around time untuk proses lainnya
        if (temp2.burstTimeLeft > 0 && executor->state == 0)
        {
            executeProcess(&temp2, executor, &q); /* code */
        }

        // jika CPU tidak sedang meksekusi maka tampilkan bahwa "idle"
        if (executor->state == 1)
        {
            Sleep(1000);
            printf("*time: %d no process is executed\n", executor->systemTime);
        }

        // jika process yang sedang dieksekusi tepat sudah selesai maka
        // pindahkan ke terminated queue
        if (temp2.burstTimeLeft == 0 && executor->state == 0)
        {
            add(temp2, &processDone);
            executor->state = 1;
        }

        // jika new queue dan ready queue kosong, serta CPU sudah tidak mengeksekusi
        // maka tetapkan bahwa semua process sudah dieksekusi
        if (isEmpty(*listProcess) == 1 && isEmpty(q) == 1 && executor->state == 1)
        {
            state = 1;
        }

        // iterator untuk menambah systemTime +1 agar seakan akan berjalan seiring dengan waktu
        executor->systemTime++;
    }

    // menampilkan status terkahir executor
    printf("================\n");
    printf("Executor State\n");
    printf("system time : %d\n", executor->systemTime);

    // menampilkan status proses yang telah dieksekusi
    printQueue(processDone);

    int i;
    scanf("%d", &i);
}

void executeProcess(process *p, processor *executor, queue *q)
{
    // menampilkan status pemrosesan process yang sedang dieksekusi
    Sleep(1000);
    printf("*time: %d executing process P%d time left = %d\n", executor->systemTime, p->pid, p->burstTimeLeft);
    p->burstTimeLeft--; // ini berfungsi untuk mengurangi burstTime, karena sudah "diseksekusi"
    p->turnAroundTime++; // menambahkan turn around time

    // menambahkan wait time dan turn around time pada semua proses yang ada
    // di dalam ready queue
    if (isEmpty(*q) == 0)
    {
        for (int i = q->first; i <= q->last; i++)
        {
            if (executor->systemTime >= q->data[i].arrivalTime)
            {
                q->data[i].waitTime++;
                q->data[i].turnAroundTime++;
            }
        }
    }
}