#include "table.h"

void createTable(char **col_names, int n_col, table *T){
    T->n_col = n_col;

    T->colnames = malloc(T->n_col * sizeof(char*));
    for(int i = 0; i < T->n_col; i++){
        T->colnames[i] = malloc((strlen(col_names[i]) + 1) * sizeof(char));
        strcpy(T->colnames[i], col_names[i]);
    }


    T->max_col_len = (int*)calloc(T->n_col, sizeof(int));

    for(int i = 0 ; i < T->n_col; i++){
        T->max_col_len[i] = strlen(col_names[i]);
    }

    T->firstRow = NULL;
    T->lastRow = NULL;

}

void addRow(char **values, table *T){
    row *new = (row*) malloc (sizeof(row));
    new->row_value = malloc(T->n_col * sizeof(char*));
    for(int i = 0 ; i < T->n_col; i++){
        new->row_value[i] = malloc((strlen(values[i]) + 1) * sizeof(char));
        strcpy(new->row_value[i], values[i]);
    }

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

void resetTable(char **col_names, int n_col, table *T){
    delAllRow(T);
    T->colnames = col_names;
    T->n_col = n_col;
    T->max_col_len = (int*)calloc(T->n_col, sizeof(int));

    for(int i = 0 ; i < T->n_col; i++){
        T->max_col_len[i] = strlen(col_names[i]);
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

void createProsessTable(list L, table *T){
    char col_names[4][20] = {"Prossess ID", "Burst Time", "Arrival Time", "Waiting Time"};
    int n_col = 4;
    char* ptr_col_names[4];
    for(int i = 0 ; i < 4; i++){
        ptr_col_names[i] = col_names[i];
    }
    createTable(ptr_col_names, n_col, T);

    element* ptr = L.first;
    while(ptr != NULL){
        char temp[5];
        char val[4][5];
        char* ptr_val[4];

        itoa(ptr->container.process_id, temp, 5);
        strcpy(val[0], temp);

        itoa(ptr->container.burst_time, temp, 5);
        strcpy(val[1], temp);

        itoa(ptr->container.arrival_time, temp, 5);
        strcpy(val[2], temp);

        itoa(ptr->container.waiting_time, temp, 5);
        strcpy(val[3], temp);

        for(int i = 0; i < 4; i++) ptr_val[i] = val[i];
        addRow(ptr_val, T);
        ptr = ptr->next;
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

void printTableForProcesses(list L){
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
