#pragma once

#include "header.h"
#include <malloc.h>

typedef struct rw *rowAddress;
typedef struct rw{
    char **row_value;
    rowAddress nextRow;
}row;

typedef struct{
    int n_col;
    int *max_col_len;
    char **colnames;
    rowAddress firstRow;
    rowAddress lastRow;
}table;

/**
 * @brief Create a Table object
 * 
 * @param col_names array of strings: contains collumns' name
 * @param T the address of the table
 */
void createTable(char **col_names, int n_col, table *T);

void addRow(char **values, table *T);

void delRow(table *T);

void delAllRow(table *T);

void updateMaxColLen(table *T);

void printTable(table *T);

void printTableForProcesses(process *Processes, int n_processes);

void printTableLine(int *max_col_len, int n_col);


