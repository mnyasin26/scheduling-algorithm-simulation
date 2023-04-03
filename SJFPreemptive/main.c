#include "header.h"

#define MAX_PROCESS 100

int main() {
    system("cls");

    // Initialize
    int n;
    int opt = 0;
    do {
        printf("===============================\n");
        printf("SHORTEST JOB FIRST - PREEMPTIVE\n");
        printf("===============================\n");
        printf(" --- Choose: ---\n");
        printf(" 1. Kelebihan\n");
        printf(" 2. Kekurangan\n");
        printf(" 3. Simulasi\n");
        printf(" 4. Exit\n");
        printf("Option: ");
        scanf("%d", &opt);
        switch(opt) {
            case 1:
                system("cls");
                minplus_FJFPreemptive(0);
                break;
            case 2:
                system("cls");
                minplus_FJFPreemptive(1);
                break;
            /* SIMULATION SJF-PREEMPTIVE*/
            case 3:
                system("cls");
                // Input
                printf("Enter the number of processes: ");
                scanf("%d", &n);
                // Initialization
                Process processes[MAX_PROCESS];
                initProcess(processes, n);
                // Simulation (execution)
                executeProcess(processes, n);      
                break;
            case 4:
                exit(0);
            default:
                system("cls");
                printf("Invalid option!\n");
        }
    } while (opt != 4);

    return 0;
}