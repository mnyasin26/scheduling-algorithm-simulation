#include "SJFPreemptive.h"

void minplus_FJFPreemptive(int x) { // gak kepikiran cara buat tabel otomatis yang ngebungkus text,jadi manual aja wkwk (laah)
    if (x == 0) {
        printf("+---------------------------------------------------------------+\n");
        printf("|                    KELEBIHAN FJF PREEMPTIVE                   |\n");
        printf("+---------------------------------------------------------------+\n");
        printf("| 1. Meningkatkan responsivitas sistem: Dalam SJF preemptive    |\n");
        printf("|    proses dengan waktu eksekusi yang lebih pendek diberi      |\n");
        printf("|    diberi prioritas untuk dieksekusi terlebih dahulu.         |\n");
        printf("|    Dengan demikian, proses yang menunggu dapat dihentikan     |\n");
        printf("|    dan diberikan kepada proses yang lebih pendek. Hal ini     |\n");
        printf("|    akan meningkatkan responsivitas sistem secara keseluruhan. |\n");
        printf("| 2. Meningkatkan efisiensi: Dalam SJF preemptive, waktu tunggu |\n");
        printf("|    proses dikurangi karena proses dengan waktu eksekusi yang  |\n");
        printf("|    lebih pendek diberi prioritas. Hal ini mengurangi waktu    |\n");
        printf("|    pemrosesan yang tidak perlu dan meningkatkan efisiensi     |\n");
        printf("|    sistem                                                     |\n");
        printf("| 3. Memastikan pemanfaatan sumber daya: SJF preemptive         |\n");
        printf("|    memastikan pemanfaatan sumber daya yang lebih baik. Proses |\n");
        printf("|    yang lebih singkat waktu eksekusinya dapat dijalankan lebih|\n");
        printf("|    cepat, sehingga CPU tidak menganggur dan dapat mengeksekusi|\n");
        printf("|    proses lain.                                               |\n");
        printf("| 4. SJF preemptive memberikan prioritas kepada proses dengan   |\n");
        printf("|    waktu eksekusi yang lebih pendek. Dengan demikian, proses  |\n");
        printf("|    yang lebih penting dan kritis dapat diselesaikan lebih     |\n");
        printf("|    cepat, meningkatkan performa dan kinerja sistem secara     |\n");
        printf("|    keseluruhan.                                               |\n");
        printf("+---------------------------------------------------------------+\n");
    } else if (x == 1) {
        printf("+---------------------------------------------------------------+\n");
        printf("|                   KEKURANGAN FJF PREEMPTIVE                   |\n");
        printf("+---------------------------------------------------------------+\n");
        printf("| 1. Adanya starvation: SJF Preemptive berpotensi mengalami     |\n");
        printf("|    starvation, yaitu beberapa proses dengan waktu eksekusi    |\n");
        printf("|    yang lebih panjang dapat terus-menerus mengalami preemption|\n");
        printf("|    sehingga tidak pernah selesai dieksekusi. Hal ini dapat    |\n");
        printf("|    memperlambat kinerja sistem dan menurunkan throughput.     |\n");
        printf("| 2. Tidak cocok untuk lingkungan produksi: SJF Preemptive sulit|\n");
        printf("|    diimplementasikan pada lingkungan produksi karena sulit    |\n");
        printf("|    memprediksi waktu eksekusi setiap proses. Selain itu, SJF  |\n");
        printf("|    Preemptive juga rentan terhadap variasi waktu eksekusi yang|\n");
        printf("|    tidak terduga, sehingga sulit untuk memprediksi waktu      |\n");
        printf("|    selesai dari satu proses dan berpotensi menimbulkan masalah|\n");
        printf("|    pada waktu produksi.                                       |\n");
        printf("+---------------------------------------------------------------+\n");
    }
}

/* Procedure to initialize an array of n processes */
void initProcessSJFP(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        // set process ID
        processes[i].pid = i + 1;
        // input user (arrival & burst time)
        printf("Enter arrival time (process %d): ", processes[i].pid);
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter burst time (process %d): ", processes[i].pid);
        scanf("%d", &processes[i].burstTime);
        // set remainning time & flag (true/false completed)
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].isCompleted = 0;
    }
}

/* Procedure to execute processes */
void executeProcessSJFP(Process processes[], int n) {
    // init
    int currentTime = 0;
    int completed = 0;
    int last_completion_time = 0;
    printf("\n");
    printf("PID\tTime System\n");
    // loop proceses
    while (completed != n) {
        // range SJF-index & time
        int shortest_job_index = -1;
        int shortest_job_time = 999999;
        for (int i = 0; i < n; i++) {
            // if the process is SHORTEST than current time and not completed, then
            if (processes[i].arrivalTime <= currentTime && !processes[i].isCompleted) {
                // if the remain time is shorter
                if (processes[i].remainingTime < shortest_job_time) {
                    // process now
                    shortest_job_index = i;
                    shortest_job_time = processes[i].remainingTime;
                }
            }
        }
        // set current time if idle
        if (shortest_job_index == -1) {
            printf("Idle at time %d\n", currentTime);
            currentTime++;
        }
        // continue
        else {
            // calculate time
            Process *p = &processes[shortest_job_index];
            /*
            response, time required by a process from asking to be served
            until there's the first response to request
            */
            p->responseTime = currentTime - p->arrivalTime;
            // remain and current time
            p->remainingTime--;
            currentTime++;
            // if remaining time runs out
            if (p->remainingTime == 0) {
                p->isCompleted = 1;
                // turn arround time & waitting time
                p->turnaroundTime = currentTime - p->arrivalTime;
                p->waitingTime = p->turnaroundTime - p->burstTime;
                // iteration
                completed++;
                last_completion_time = currentTime;
            }
            // log process status
            printf("%d\tP%d\n", currentTime, p->pid);
        }
    }
    printf("\n");
    // Calculate
    float avgWaitingTime = 0.0;
    float avgTurnaroundTime = 0.0;
    float avgResponseTime = 0.0;
    for (int i = 0; i < n; i++) {
        avgWaitingTime += processes[i].waitingTime;
        avgTurnaroundTime += processes[i].turnaroundTime;
        avgResponseTime += processes[i].responseTime;
    }
    avgWaitingTime /= n;
    avgTurnaroundTime /= n;
    avgResponseTime /= n;
    // Throughput
    float throughput = (float)n / last_completion_time;
    // Output
    printProcessSJFP(processes, n);
    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
    printf("Average Response Time: %.2f\n", avgResponseTime);
    printf("Throughput: %.2f\n", throughput);
}

/* Procedure to print output all of the processes*/
void printProcessSJFP(Process processes[], int n) {
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tResponse Time\n");
    for (int i = 0; i < n; i++) {
        // process sequence
        Process p = processes[i];
        // output
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p.pid, p.arrivalTime, p.burstTime, p.waitingTime, p.turnaroundTime, p.responseTime);
    }
}