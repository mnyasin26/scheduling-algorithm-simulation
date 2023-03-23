#include "table.h"

void createTable(char **col_names, int n_col, table *T){
    T->colnames = col_names;
    T->n_col = n_col;
    T->max_col_len = (int*)calloc(T->n_col, sizeof(int));

    for(int i = 0 ; i < T->n_col; i++){
        T->max_col_len[i] = strlen(col_names[i]);
    }

    T->firstRow = NULL;
    T->lastRow = NULL;

}

void addRow(char **values, table *T){
    row *new = (row*) malloc (sizeof(row));
    new->row_value = values;
    new->nextRow = NULL;
    if(T->firstRow == NULL){
        T->firstRow = new;
        T->lastRow = new;
    }
    else{
        T->lastRow->nextRow = new;
        T->lastRow = new;
    }
    new = NULL;
}

void delRow(table *T){
    
    if (T->firstRow != NULL){

        row *del = T->lastRow;

        if(T->firstRow == del){
            T->firstRow = T->lastRow = NULL;
        }
        else{
            row* ptr = T->firstRow;
            while(ptr->nextRow != del){
                ptr = ptr->nextRow;
            }
            ptr->nextRow = NULL;
            T->lastRow = ptr;
            free(ptr);
        }

        free(del);
    }
}

void delAllRow(table *T){

    while(T->firstRow != NULL){
        delRow(T);
    }
}

void updateMaxColLen(table *T){

    for(int i = 0 ; i < T->n_col; i++){
        row* ptr = T->firstRow;
        while(ptr != NULL){
            if(T->max_col_len[i] < strlen(ptr->row_value[i])){
                T->max_col_len[i] = strlen(ptr->row_value[i]);
            }
            ptr = ptr->nextRow;
        }
    }
}

void printTable(table *T){
    
    if(T->firstRow != NULL){
        updateMaxColLen(T);
        printTableLine(T->max_col_len, T->n_col);
        for(int i = 0 ; i < T->n_col; i++){
            printf("| %s ", T->colnames[i]);
            for(int j = 0 ; j < T->max_col_len[i] - strlen(T->colnames[i]); j++){
                printf(" ");
            }
        }
        printf("|\n");
        printTableLine(T->max_col_len, T->n_col);

        row *ptr = T->firstRow;
        while(ptr != NULL){
            for(int i = 0; i < T->n_col; i++){
                printf("| %s ",ptr->row_value[i]);
                for(int j = 0 ; j < T->max_col_len[i] - strlen(ptr->row_value[i]); j++){
                    printf(" ");
                }
            }
            printf("|\n");
            ptr = ptr->nextRow;
        }
        free(ptr);
        printTableLine(T->max_col_len, T->n_col);
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
