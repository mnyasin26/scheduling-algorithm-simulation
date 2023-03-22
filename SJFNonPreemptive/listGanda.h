#include "header.h"
#include <malloc.h>
#include "SJFNonPreemptive.h"

#define listVar int burst_time, int arrival_time

#define data1 burst_time
#define data2 arrival_time



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


/**
 * @brief add element to the front
 * 
 * @param L 
 */
void addFirst(listVar, list *L);

/**
 * @brief add element before a certain element
 * 
 * @param before 
 * @param L 
 */
void addAfter (listVar, element* before, list *L);

/**
 * @brief add element after a certain element
 * 
 * @param after 
 * @param L 
 */
void addBefore (listVar, element* after, list *L);

/**
 * @brief add element to the end of the list
 * 
 * @param L 
 */
void addLast (listVar, list *L);

/**
 * @brief add element into the
 * correct position based on the
 * burst time
 * 
 * @param method = 0 for ascending, 1 for descending
 * @param L 
 */
void addSortByBurstTime(listVar, int method, list *L);

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


/**
 * @brief print all element in the list
 * 
 * @param L 
 */
void printElement (list L);

/**
 * @brief print all element in the list
 * from the back
 * 
 * @param L 
 */
void printElementRev(list L);