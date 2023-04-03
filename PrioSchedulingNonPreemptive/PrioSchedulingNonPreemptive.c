// #include "../header.h"
#include "PrioSchedulingNonPreemptive.h"

#define COL_LENGTH_TERMINATED_TASK 8
#define COL_LENGTH_READY_TASK 4
#define COL_LENGTH_LOG_TASK 3
#define COL_LENGTH_STATISTICS 4
void PSNPmeaning()
{
    printf("+----------------------------------------------------------------+\n");
    printf("|                   RINGKASAN PS NON PREEMPTIVE                  |\n");
    printf("+----------------------------------------------------------------+\n");
    printf("|Priority scheduling non-preemptive adalah salah satu metode     |\n");
    printf("|proses pada sistem operasi yang memprioritaskan proses-proses   |\n");
    printf("|penjadwalan  yang memiliki prioritas tertinggi.                 |\n");
    printf("|Pada metode ini, ketika sebuah proses telah dimulai,            |\n");
    printf("|maka proses tersebut akan berjalan hingga selesai               |\n");
    printf("|tanpa diinterupsi oleh proses yang prioritasnya lebih tinggi.   |\n");
    printf("|Dalam priority scheduling non-preemptive,                       |\n");
    printf("|urutan eksekusi proses ditentukan berdasarkan                   |\n");
    printf("|nilai prioritas yang diberikan kepada masing-masing proses.     |\n");
    printf("|Semakin tinggi nilai prioritas suatu proses,                    |\n");
    printf("|semakin cepat proses tersebut akan diproses dan selesai.        |\n");
    printf("|Proses dengan nilai prioritas yang lebih rendah                 |\n");
    printf("|akan menunggu hingga proses dengan nilai prioritas              |\n");
    printf("|lebih tinggi selesai dijalankan.                                |\n");
    printf("+----------------------------------------------------------------+\n");
    getch();
}
void PSNPpros()
{
    printf("+----------------------------------------------------------------+\n");
    printf("|                   KELEBIHAN PS NON PREEMPTIVE                  |\n");
    printf("+----------------------------------------------------------------+\n");
    printf("|1.  Meningkatkan performa sistem: Metode ini dapat meningkatkan |\n");
    printf("|    performa sistem dengan memprioritaskan eksekusi             |\n");
    printf("|    proses-prosesnyang memiliki prioritas tertinggi             |\n");
    printf("|    sehingga waktu eksekusi menjadi lebih efisien.              |\n");
    printf("|2.  Meningkatkan responsifitas sistem: Dengan menerapkan        |\n");
    printf("|    priority scheduling non-preemptive, proses-proses yang      |\n");
    printf("|    penting dan memiliki prioritas tinggi dapat segera          |\n");
    printf("|    dieksekusi dan menyelesaikan tugasnya, sehingga             |\n");
    printf("|    responsifitas sistem menjadi lebih baik.                    |\n");
    printf("|3.  Memberikan keamanan pada sistem: Dengan memberikan prioritas|\n");
    printf("|    yang tepat pada proses-proses kritis dan penting, maka      |\n");
    printf("|    kemanan sistem akan terjaga dan proses-proses tersebut akan |\n");
    printf("|    segera diproses.|\n");
    printf("|4.  Menghindari starvation: Dalam metode ini, proses-proses     |\n");
    printf("|    dengan prioritas rendah tetap mendapat kesempatan untuk     |\n");
    printf("|    diproses sehingga tidak terjadi starvation atau             |\n");
    printf("|    proses-proses dengan prioritas rendah terus menerus tertunda|\n");
    printf("|    eksekusinya.|\n");
    printf("|5.  Mudah diimplementasikan: Metode ini mudah diimplementasikan |\n");
    printf("|    karena hanya memerlukan satu algoritma yang sederhana dan   |\n");
    printf("|    mudah dipahami.|\n");
    printf("+----------------------------------------------------------------+\n");
    getch();
}
void PSNPcons()
{
    printf("+----------------------------------------------------------------+\n");
    printf("|                  KEKURANGAN PS NON PREEMPTIVE                  |\n");
    printf("+----------------------------------------------------------------+\n");
    printf("|1.  Tidak efektif dalam memanfaatkan sumber daya sistem: Dalam  |\n");
    printf("|    metode ini, proses dengan prioritas tinggi akan diproses    |\n");
    printf("|    terlebih dahulu, bahkan jika proses tersebut memerlukan     |\n");
    printf("|    sumber daya sistem yang banyak. Hal ini dapat menyebabkan   |\n");
    printf("|    sumber daya sistem lainnya terabaikan dan tidak efektif     |\n");
    printf("|    dalam memanfaatkan sumber daya sistem.|\n");
    printf("|2.  Tidak sesuai untuk sistem yang dinamis: Jika prioritas suatu|\n");
    printf("|    proses berubah-ubah seiring waktu, maka metode ini tidak    |\n");
    printf("|    efektif karena memerlukan pengaturan ulang prioritas setiap |\n");
    printf("|    kali terjadi perubahan prioritas.|\n");
    printf("|3.  Memerlukan pengaturan prioritas yang hati-hati: Dalam metode|\n");
    printf("|    ini, pengaturan prioritas harus dilakukan dengan hati-hati  |\n");
    printf("|    karena jika prioritas salah ditentukan, maka proses dengan  |\n");
    printf("|    prioritas rendah bisa mengalami penundaan eksekusi yang lama|\n");
    printf("|4.  Memerlukan waktu eksekusi yang lebih lama: Metode ini       |\n");
    printf("|    memerlukan waktu eksekusi yang lebih lama daripada metode   |\n");
    printf("|    preemptive karena tidak ada interupsi pada proses-proses    |\n");
    printf("|    yang sedang berjalan.|\n");
    printf("|5.  Tidak dapat mencegah deadlock: Metode ini tidak dapat       |\n");
    printf("|    mencegah terjadinya deadlock, yaitu situasi dimana beberapa |\n");
    printf("|    proses saling memblokir satu sama lain sehingga tidak dapat |\n");
    printf("|    terselesaikan.|\n");
    printf("+----------------------------------------------------------------+\n");
    getch();
}
void PrioSchedulingNonPreemptive()
{
    int menu;
    printf("=====================================================\n");
    printf("=   Welcome to Priority Scheduling NonPreemptive!   =\n");
    printf("=====================================================\n");
    printf("\n");

    printf("!!  Type any of the number listed below            !!\n");
    printf("!!  to find out more about this method             !!\n");
    printf("\n");

    printf("||  0. What is PS NonPreemptive?                   ||\n");
    printf("||  1. PS NonPreemtive Pros                        ||\n");
    printf("||  2. PS NonPreemtive Cons                        ||\n");
    printf("||  3. PS NonPreemtive Simulation                  ||\n");
    printf("||  4. Exit                                        ||\n");
    printf("\n");

    printf("-= Choose what to do =-:\n");
    scanf("%d", &menu);
    switch (menu)
    {
    case 0:
        system("cls");
        PSNPmeaning();
        break;
    case 1:
        system("cls");
        PSNPpros();
        break;
    case 2:
        system("cls");
        PSNPcons();
        break;
    case 3:
        system("cls");
        PrioSchedulingNonPreemptiveInput();
        break;
    case 4:
        exit(0);

    default:
        break;
    }
}

void PrioSchedulingNonPreemptiveInput()
{
    // set banyaknya proses
    int banyakproses;
    printf("Berapa banyak proses: ");
    scanf("%d", &banyakproses);

    process Pp[100];

    // input dari proses id, priority, arrival dan burst time
    for (int i = 0; i < banyakproses; i++)
    {
        printf("Proses ke-%d\n", i);
        printf("  Prosed ID : ");
        scanf("%d", &Pp[i].process_id);
        printf("  Prioritas : ");
        scanf("%d", &Pp[i].priority);
        printf("  Arrival Time : ");
        scanf("%d", &Pp[i].arrival_time);
        printf("  Burst Time : ");
        scanf("%d", &Pp[i].burst_time);
        Pp[i].burstTimeLeft = Pp[i].burst_time;
        Pp[i].waiting_time = 0;
        Pp[i].turnaround_time = 0;
        Pp[i].response_time = 0;
    }

    // set burstimeleft, waiting sama turnaround ke 0
    // for (int i = 0; i < banyakproses; i++)
    // {
    //     Pp[i].burstTimeLeft = 0;
    //     Pp[i].waiting_time = 0;
    //     Pp[i].turnaround_time = 0;
    // }

    // Executor bertindak sebagai "processor" yang bertugas untuk mengeksekusi process
    processor executor = {executor.systemTime = 0, executor.state = 1};

    // Process p-n adalah perwujudan dari proses dengan berbagai atributnya
    // process p0 = {p0.process_id = 0, p0.priority = 2, p0.burst_time = 2, p0.burstTimeLeft = 0, p0.arrival_time = 0, p0.waiting_time = 0, p0.turnaround_time = 0};
    // process p1 = {p1.process_id = 1, p1.priority = 3, p1.burst_time = 6, p1.burstTimeLeft = 0, p1.arrival_time = 1, p1.waiting_time = 0, p1.turnaround_time = 0};
    // process p2 = {p2.process_id = 2, p2.priority = 1, p2.burst_time = 4, p2.burstTimeLeft = 0, p2.arrival_time = 2, p2.waiting_time = 0, p2.turnaround_time = 0};

    // printf("%s",temp);
    // set BurstTimeLeft untuk keperluan pemrosesan
    // p0.burstTimeLeft = p0.burst_time;
    // p1.burstTimeLeft = p1.burst_time;
    // p2.burstTimeLeft = p2.burst_time;

    // buat queue untuk tempat penyimpanan sementara untuk process (bukan ready queue)
    queue listProcess;
    createEmpty(&listProcess);

    for (int i = 0; i < banyakproses; i++)
    {
        add(Pp[i], &listProcess);
    }

    // add(p0, &listProcess);
    // add(p1, &listProcess);
    // add(p2, &listProcess);

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

    table TableReadyQueue;      // (ready queue)
    table TableTerminatedQueue; // (terminated queue)
    table TableLogQueue;        // (running queue)
    table Stats;                // (Statistics)
    char colnames[COL_LENGTH_READY_TASK][100] = {"Process ID", "Priority", "Burst Time", "Arrival Time"};
    char colnames2[COL_LENGTH_TERMINATED_TASK][100] = {"No.", "Process ID", "Priority", "Burst Time", "Arrival Time", "Waiting Time", "Turn Around Time", "Response Time"};
    char colnamesStats[COL_LENGTH_STATISTICS][100] = {"Throughput", "Avg Response Time", "Avg Waiting TIme", "Avg Turn Around Time"};
    char *ptr_colnames[COL_LENGTH_READY_TASK];
    char *ptr_colnames2[COL_LENGTH_TERMINATED_TASK];
    char *ptr_colnamesStats[COL_LENGTH_STATISTICS];
    for (int i = 0; i < COL_LENGTH_READY_TASK; i++)
    {
        ptr_colnames[i] = colnames[i];
    }
    for (int i = 0; i < COL_LENGTH_TERMINATED_TASK; i++)
    {
        ptr_colnames2[i] = colnames2[i];
    }
    for (int i = 0; i < COL_LENGTH_STATISTICS; i++)
    {
        ptr_colnamesStats[i] = colnamesStats[i];
    }
    createTable(ptr_colnames, COL_LENGTH_READY_TASK, &TableReadyQueue);
    createTable(ptr_colnames2, COL_LENGTH_TERMINATED_TASK, &TableTerminatedQueue);
    createTable(ptr_colnamesStats, COL_LENGTH_STATISTICS, &Stats);
    char colnamesLog[COL_LENGTH_LOG_TASK][100] = {"Time System", "Process ID", "Burst Time Left"};
    char *ptr_colnamesLog[COL_LENGTH_LOG_TASK];
    for (int i = 0; i < COL_LENGTH_LOG_TASK; i++)
    {
        ptr_colnamesLog[i] = colnamesLog[i];
    }
    createTable(ptr_colnamesLog, COL_LENGTH_LOG_TASK, &TableLogQueue);

    printf("Processing Begin\n");

    // menampilkan prosess awal setelah masukan user
    printQueue(*listProcess);

    // variabel bantu
    int state = 0;
    int state2 = 0;
    process temp1;
    process temp2;

    int number = 1;

    float avgWaitingTime = 0.0f;
    float avgTurnAroundTime = 0.0f;
    float avgResponseTime = 0.0f;
    float throughput = 0.0f;

    // inti pemrosesan
    while (state == 0)
    {

        system("cls");
        printf("System Time: %d\n\n", executor->systemTime);

        // cek apakah "new" queue kosong, jika kosong maka cek isinya
        // apakah ada process yang arrival time nya
        // sama atau lebih dari systemTime executor
        if (isEmpty(*listProcess) == 0)
        {
            for (int i = listProcess->first; i <= listProcess->last; i++)
            {
                if (executor->systemTime >= listProcess->data[i].arrival_time)
                {
                    // jika ada maka masukkan proses tersebut ke "ready" queue, dan keluarkan dari listProcess
                    temp1 = popDel(i, listProcess);
                    char temp[50];

                    sprintf(temp, "P%d", temp1.process_id);
                    strcpy(colnames[0], temp);

                    sprintf(temp, "%d", temp1.priority);
                    strcpy(colnames[1], temp);

                    sprintf(temp, "%d", temp1.burst_time);
                    strcpy(colnames[2], temp);

                    sprintf(temp, "%d", temp1.arrival_time);
                    strcpy(colnames[3], temp);

                    addRow(ptr_colnames, &TableReadyQueue);
                    add(temp1, &q);
                    // printf("process P%d arrived\n", temp1.process_id); // tampilkan bahwa process arrived
                    i--;
                    break;
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
                // delRow(&T);
                char temp[50];

                sprintf(temp, "%d", number++);
                strcpy(colnames2[0], temp);

                sprintf(temp, "P%d", temp2.process_id);
                strcpy(colnames2[1], temp);

                delRowByID(&TableReadyQueue, temp);

                sprintf(temp, "%d", temp2.priority);
                strcpy(colnames2[2], temp);

                sprintf(temp, "%d", temp2.burst_time);
                strcpy(colnames2[3], temp);

                sprintf(temp, "%d", temp2.arrival_time);
                strcpy(colnames2[4], temp);

                // printf("test\n");

                executor->state = 0;
            }
        }
        printf("Ready Queue:\n");
        printTable(&TableReadyQueue);

        // pada bagian ini dipastikan bahwa ada proses yang sedang dieksekusi
        // berfungsi untuk memproses proses dengan cara
        // mengurangi -1 burstTimeLeft dari proses yang ada pada variabel temp2
        // dan menambah +1 wait time dan turn around time untuk proses lainnya
        if (temp2.burstTimeLeft > 0 && executor->state == 0)
        {
            // printf("Running System Log:\n");
            executeProcess(&temp2, executor, &q, &TableLogQueue); /* code */
        }

        // jika CPU tidak sedang meksekusi maka tampilkan bahwa "idle"
        if (executor->state == 1)
        {
            printf("\nStatus: No process is executed\n\n");
            char temp[50];
            sprintf(temp, "%d", executor->systemTime);
            strcpy(colnamesLog[0], temp);
            sprintf(temp, "-");
            strcpy(colnamesLog[1], temp);
            sprintf(temp, "-");
            strcpy(colnamesLog[2], temp);

            addRow(ptr_colnamesLog, &TableLogQueue);
        }
        else
        {
            printf("\nStatus: CPU is busy\n\n");
        }
        printf("Task Logging:\n");
        printTable(&TableLogQueue);

        // jika process yang sedang dieksekusi tepat sudah selesai maka
        // pindahkan ke terminated queue

        printf("\nTerminated Task:\n");
        printTable(&TableTerminatedQueue);
        if (temp2.burstTimeLeft == 0 && executor->state == 0)
        {
            char temp[50];
            sprintf(temp, "%d", temp2.waiting_time);
            strcpy(colnames2[5], temp);
            avgWaitingTime += temp2.waiting_time;

            sprintf(temp, "%d", temp2.turnaround_time);
            strcpy(colnames2[6], temp);
            avgTurnAroundTime += temp2.turnaround_time;

            sprintf(temp, "%d", temp2.response_time);
            strcpy(colnames2[7], temp);
            avgResponseTime += temp2.response_time;

            throughput = throughput + 1.0f;
            addRow(ptr_colnames2, &TableTerminatedQueue);
            add(temp2, &processDone);
            executor->state = 1;
        }

        // if (executor->systemTime >= currentTime+1)
        // {

        // }

        // jika new queue dan ready queue kosong, serta CPU sudah tidak mengeksekusi
        // maka tetapkan bahwa semua process sudah dieksekusi
        if (isEmpty(*listProcess) == 1 && isEmpty(q) == 1 && executor->state == 1)
        {
            if (state2 == 1)
            {
                state = 1;
            }
            state2 = 1;
        }

        Sleep(2000);
        // iterator untuk menambah systemTime +1 agar seakan akan berjalan seiring dengan waktu
        executor->systemTime++;
    }

    // menampilkan status terkahir executor
    // printf("================\n");
    // printf("Executor State\n");
    // printf("system time : %d\n", executor->systemTime);
    printf("\nStatistics\n");

    avgWaitingTime /= processDone.last + 1;
    avgTurnAroundTime /= processDone.last + 1;
    avgResponseTime /= processDone.last + 1;
    throughput /= executor->systemTime - 1;

    char temp[50];
    sprintf(temp, "%.2f", throughput);
    strcpy(colnamesStats[0], temp);

    sprintf(temp, "%.2f", avgResponseTime);
    strcpy(colnamesStats[1], temp);

    sprintf(temp, "%.2f", avgWaitingTime);
    strcpy(colnamesStats[2], temp);

    sprintf(temp, "%.2f", avgTurnAroundTime);
    strcpy(colnamesStats[3], temp);

    addRow(ptr_colnamesStats, &Stats);
    printTable(&Stats);
    // menampilkan status proses yang telah dieksekusi
    // printQueue(processDone);

    int i;
    scanf("%d", &i);
}

void executeProcess(process *p, processor *executor, queue *q, table *t)
{
    // menampilkan status pemrosesan process yang sedang dieksekusi
    // printf("*time: %d executing process P%d time left = %d\n", executor->systemTime, p->process_id, p->burstTimeLeft);

    char colnamesLog[3][100] = {"Time System", "Process ID", "Burst Time Left"};
    char *ptr_colnamesLog[3];
    for (int i = 0; i < 3; i++)
    {
        ptr_colnamesLog[i] = colnamesLog[i];
    }
    char temp[50];
    sprintf(temp, "%d", executor->systemTime);
    strcpy(colnamesLog[0], temp);
    sprintf(temp, "P%d", p->process_id);
    strcpy(colnamesLog[1], temp);
    sprintf(temp, "%d", --p->burstTimeLeft);
    strcpy(colnamesLog[2], temp);

    addRow(ptr_colnamesLog, t);

    // p->burstTimeLeft--;   // ini berfungsi untuk mengurangi burstTime, karena sudah "diseksekusi"
    p->turnaround_time++; // menambahkan turn around time

    // menambahkan wait time dan turn around time pada semua proses yang ada
    // di dalam ready queue
    if (isEmpty(*q) == 0)
    {
        for (int i = q->first; i <= q->last; i++)
        {
            if (executor->systemTime >= q->data[i].arrival_time)
            {
                q->data[i].waiting_time++;
                q->data[i].turnaround_time++;
                q->data[i].response_time++;
            }
        }
    }
    // printTable(t);
}