#include "header.h"

#define timeDelay 1800
int pilihan = 0;

// untuk membuat animasi bisa menggunakan 2 function system("cls") dan Sleep(ms seconds)

int main(){

    while(pilihan != 8){
        system("cls");
        printf("----------Simulasi Algoritma Penjadwalan----------");
        printf("\nOleh Kelompok 3 Kelas Ilkom C1 2021 UPI - Sistem Operasi 2023 Semester 4");
        printf("\n\n======= Menu =======");
        printf("\n1. FCFS");
        printf("\n2. SJF Preemptive");
        printf("\n3. SJF Non-Preemptive");
        printf("\n5. Round Robin");
        printf("\n6. Priority Scheduling Preemptive");
        printf("\n7. Priority Scheduling Non-Preemptive");
        printf("\n8. Exit");
        printf("\n\nInput pilihan menu: ");
        scanf("%d", &pilihan);
        if (pilihan == 8)
        {
            break;
        }
        system("cls");
        printf("Initializing\n");
        Sleep(timeDelay);
        system("cls");
        printf("Initializing .\n");
        Sleep(timeDelay);
        system("cls");
        printf("Initializing ..\n");
        Sleep(timeDelay);
        system("cls");
        printf("Initializing ...\n");
    
        switch (pilihan)
        {
        case 1:
            FCFS();
            break;

        case 2:
            SJFPreemptive();
            break;

        case 3:
            SJFNonPreemptive();
            break;

        case 4:
            RoundRobin();
            break;

        case 5:
            PrioSchedulingPreemptive();
            break;

        case 6:
            PrioSchedulingNonPreemptive();
            break;

        default:
            break;
        }
    }
    return 0;
}