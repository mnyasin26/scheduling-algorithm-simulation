#include "table.h"

void printTable(char **colname, process prosesses[]){

    int n_col = sizeof(colname) / sizeof(colname[0]);
    int* max_col_len = (int*)calloc(n_col, sizeof(int));

    for(int i = 0; i < n_col; i++){
        /**
         * @brief 
         * not dynamic table for now, too lazy
         */
        max_col_len[i] = strlen(colname[i]);
    }

    printTableLine(max_col_len, n_col);
    for(int i = 0; i < n_col; i++){
        printf("| ");
        printf("");
    }


}

void printTableForProcesses(process *processes, int n_processes){
    char arr[4][15] = {"Prossess ID", "Burst Time", "Arrival Time", "Waiting Time"};
    int max_col_len[4] = {strlen(arr[0]), strlen(arr[1]), strlen(arr[2]), strlen(arr[3])};
    int n_col = (int) sizeof(max_col_len) / sizeof(max_col_len[0]);

    printTableLine(max_col_len, n_col);
    for(int i = 0 ; i < 4; i++){
        printf("| ");
        printf("%s ", arr[i]);
    }
    printf("|\n");
    printTableLine(max_col_len, n_col);

    for(int i = 0; i < n_processes; i++){
        char temp[5];
        itoa(processes[i].process_id, temp, 5);
        printf("| ");
        printf("%s", temp);
        for(int j = 0 ; j < max_col_len[0] - strlen(temp) + 1; j++){
            printf(" ");
        }

        itoa(processes[i].burst_time, temp, 5);
        printf("| ");
        printf("%s", temp);
        for(int j = 0 ; j < max_col_len[1] - strlen(temp) + 1; j++){
            printf(" ");
        }

        itoa(processes[i].arrival_time, temp, 5);
        printf("| ");
        printf("%s", temp);
        for(int j = 0 ; j < max_col_len[2] - strlen(temp) + 1; j++){
            printf(" ");
        }

        itoa(processes[i].waiting_time, temp, 5);
        printf("| ");
        printf("%s", temp);
        for(int j = 0 ; j < max_col_len[3] - strlen(temp) + 1; j++){
            printf(" ");
        }
        printf("|\n");
    }
    printTableLine(max_col_len, n_col);

}

void printTableLine(int *max_col_len, int n_col){

    for(int i = 0 ; i < n_col; i++){
        printf("+");
        for(int j = 0 ; j < max_col_len[i] + 2; j++){
            printf("-");
        }
    }
    printf("+\n");
}
