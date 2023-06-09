#include "RoundRobin.h"

void kelebihan()
{
    printf("+================================================================+\n");
    printf("|                   KELEBIHAN Round Robin                        |\n");
    printf("+================================================================+\n");
    printf("| 1. Tidak menghadapi masalah starvation atau convoy effect.     |\n");
    printf("| 2. Adil: Karena giliran antar proses sudah diatur oleh         |\n");
    printf("|    Quantum Time.                                               |\n");
    printf("| 3. Tidak bergantung pada Burst Time sehingga mudah             |\n");
    printf("|    diimplementasikan pada sistem                               |\n");
    printf("+================================================================+\n\n");
}

void kekurangan()
{
    printf("+================================================================+\n");
    printf("|                   KEKURANGAN Round Robin                       |\n");
    printf("+================================================================+\n");
    printf("| 1. Response time dan waiting time yang lebih besar :           |\n");
    printf("|    Hal tersebut disebabkan oleh pemberian jatah waktu          |\n");
    printf("|    yang tetap untuk semua proses.                              |\n");
    printf("| 2. Throughput rendah : Dikarenakan pemberian jatah waktu       |\n");
    printf("|    yang tetap, throughput rata-rata lebih rendah dari          |\n");
    printf("|    algoritma penjadwalan lain.                                 |\n");
    printf("| 3. Tidak memprioritaskan proses yang lebih penting             |\n");
    printf("| 4. Memakan banyak waktu bila Quantum Timenya kecil.            |\n");
    printf("| 5. Sulit menemukan Quantum Time yang tepat.                    |\n");
    printf("|    diimplementasikan pada sistem                               |\n");
    printf("+================================================================+\n\n");
}

void RoundRobin()
{
    // Variabel
    /*
    i = iterator
    NOP = Number of Process
    Sum = jumlah burst time
    Count = untuk menyatakan kondisi proses, bila burst time sudah habis maka count menjadi 1, bila belum count = 0
    y = untuk assign nop
    quant = Quantum Time
    wt = waiting time
    tat = turnaround time
    at = arrival time
    bt = burst time
    temp = temporary array
    avg_wt = average waiting time
    avg_tat = average turnarount time*/
    int i, NOP, sum = 0, count = 0, y, quant, wt = 0, tat = 0, at[10], bt[10], temp[10];
    float avg_wt, avg_tat;
    process proses;
    // kelebihan
    Sleep(800);
    kelebihan();
    // kekurangan
    Sleep(800);
    kekurangan();

    // mulai input
    printf("Masukkan Jumlah Proses : ");
    scanf("%d", &NOP);
    y = NOP; // Assign the number of process to variable y

    // Use for loop to enter the details of the process like Arrival time and the Burst Time
    for (i = 0; i < NOP; i++)
    {
        printf("Masukkan Arrival Time dan Burst Time tiap proses [%d]\n", i + 1);
        printf("Arrival time : "); // Accept arrival time
        scanf("%d", &at[i]);
        printf("Burst time   : "); // Accept the Burst time
        scanf("%d", &bt[i]);
        temp[i] = bt[i]; // menyimpan burst time ke temp
    }
    // Input time quantum
    printf("Masukkan Quantum Time : ");
    scanf("%d", &quant);
    // Display process No, burst time, Turn Around Time dan waiting time
    printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");
    for (sum = 0, i = 0; y != 0;)
    {
        // kondisi bila burst time (temp) <= quantum time dan burst time (temp) > 0, maka dia akan langsung di 0-kan
        // lalu count akan menjadi 1 yang menandakan proses bisa diprint
        if (temp[i] <= quant && temp[i] > 0)
        {
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        }
        // bila burst time(temp) > 0, maka proses dilakukan dengan mengurangi burst time
        // dengan quantum time
        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - quant;
            sum = sum + quant;
        }
        // print proses dan menghitung waiting time dan turnaround time, jika burst time = 0 dan count = 1
        if (temp[i] == 0 && count == 1)
        {
            y--; // decrement the process no.
            Sleep(800);
            printf("\nProcess No[%d] \t\t %d \t\t\t %d \t\t\t %d", i + 1, bt[i], sum - at[i], sum - at[i] - bt[i]);
            Sleep(800);
            wt = wt + sum - at[i] - bt[i];
            tat = tat + sum - at[i];
            count = 0;
        }
        // jika i = banyak proses - 1 maka i menjadi 0
        if (i == NOP - 1)
        {
            i = 0;
        }
        // jika arrival time[ke i + 1] <= jumlah burst time, maka i++
        else if (at[i + 1] <= sum)
        {
            i++;
        }
        // selain itu i = 0
        else
        {
            i = 0;
        }
    }
    // represents the average waiting time and Turn Around time
    avg_wt = wt / NOP;
    avg_tat = tat / NOP;
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("Average Turn Around Time: %.2f \n", avg_wt);
    printf("Average Waiting Time: %.2f \n", avg_tat);
    printf("-------------------------------------------------\n");
    printf("Pencet Tombol apapun untuk kembali ke Menu \n");
    getch();
}