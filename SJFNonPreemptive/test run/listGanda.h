#pragma once

#include "header.h"
#include <malloc.h>

typedef struct elemnt *elementAddress;
typedef struct elemnt
{
    process container;
    elementAddress prev;
    elementAddress next;
}element;

typedef struct{
    element *first;
    element *tail;
}list;

/**
 * @brief Create a List object
 * which contains processes
 * 
 * @param L 
 * 
 */
void createList (list *L);

/**
 * @brief count the amount 
 * of element inside the list
 * 
 * @param L 
 * @return int 
 */
int countElement(list L);

int isEmpty(list L);


/**
 * @brief add element to the front
 * 
 * @param L 
 */
void addFirst(process proses, list *L);

/**
 * @brief add element before a certain element
 * 
 * @param before 
 * @param L 
 */
void addAfter (process proses, element* before, list *L);

/**
 * @brief add element after a certain element
 * 
 * @param after 
 * @param L 
 */
void addBefore (process proses, element* after, list *L);

/**
 * @brief add element to the end of the list
 * 
 * @param L 
 */
void addLast (process proses, list *L);

/**
 * @brief add element into the
 * correct position based on the
 * burst time
 * 
 * @param method = 0 for ascending, 1 for descending
 * @param L 
 */
void addSortByBurstTime(process proses, int method, list *L);

void addSortByArrivalTime(process proses, int methode, list *L);

/**
 * @brief delete the first element
 * 
 * @param L 
 */
void delFirst (list *L);

/**
 * @brief delete an element after a certain element
 * 
 * @param before 
 * @param L 
 */
void delAfter (element* before, list *L);

/**
 * @brief delete the last element 
 * 
 * @param L 
 */
void delLast (list *L);

/**
 * @brief delete all element
 * 
 * @param L 
 */
void delAll (list *L);

element* popFirst(list *L);

element* popAfter(element* before, list* L);

element* popBefore(element* after, list* L);

element* popLast(list *L);

element* popByArrivalTime(int arrival_time, list *L);

int getShortestBurstTime(list L);

void updateWaitingTimeForAllElement(int delta_waiting_time, list *L);