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
 * @param col_names arrays of string index : an array that contains the index of each strings
 * example: char string[1][5] = {"1"}; char* index[1]; index[0] = string[0];
 * @param n_col number of elements inside the array of indexes/string;
 * @param T the address of the table;
 */
void createTable(char **col_names, int n_col, table *T);

/**
 * @brief Insert a row to the table
 * 
 * @param values arrays of string index : an array that contains the index of each strings
 * example: char string[1][5] = {"1"}; char* index[1]; index[0] = string[0];
 * @attention elements inisde the array must be equal to the amount of collumns!
 * @param T the address of the table
 */
void addRow(char **values, table *T);

/**
 * @brief Delte the latest row
 * 
 * @param T the address of the table
 */
void delRow(table *T);

/**
 * @brief delete all row from the table
 * 
 * 
 * @param T the address of the table
 */
void delAllRow(table *T);

/**
 * @brief Function to update the longest string
 * in each collumn.
 * @attention better treat it just like a private method
 * 
 * @param T the address of the table
 */
void updateMaxColLen(table *T);

/**
 * @brief printing the table itself
 * 
 * @param T the address of the table
 */
void printTable(table *T);

void printTableForProcesses(process *Processes, int n_processes);

/**
 * @brief printing the seperator line of the table
 * @attention treat it just like a private method
 * 
 * @param max_col_len array of int: containing the max len of each col
 * @param n_col int, the amount of column
 */
void printTableLine(int *max_col_len, int n_col);


