
#include <stdio.h>
#include <stdlib.h>

#include "list_structures.h"
#include "list.h"

/*
 * create a Data item for the List
 */
Data *createData(int val ) {
  Data *new = malloc(sizeof(Data));
  new->value = val;
  return new;
}

/*
 * allocate and initialise a List data structure 
 */
List *createList( void ) {
    List *new = malloc(sizeof(List));
    new->blockSize = 10;
    new->size = new->blockSize;
    new->data = calloc(new->size,sizeof(Data *));  // allocate an initial block for List storage
    new->length = 0;
    return new;
}

/*
 * reallocate dynamic array data if we have reached list->size
 */
void enlargeList( List *list ) {
    list->size += list->blockSize;
    list->data = realloc(list->data,list->size); // allocate a further 'block' to the List to increase size
    return;
}

/*
 * insert a Data item onto the List 
 */
void insert( List *list, Data *new, int loc ) {
    
    if( list->length+1 == list->size ) // reallocate if we have reached max size
        enlargeList( list );

    if( loc>list->length || loc<0 ) // check for invalid loc
        return;

    // shuffle list up to create a gap at index loc
    for( int k=list->length; k>loc; --k )
        list->data[k] = list->data[k-1];

    list->data[loc] = new;   // insert the data at loc
    list->length++;          // increase the list length

    return;
}

/*
 * remove the front Data item from the List
 */
Data *delete( List *list, int loc ) {

    // check for empty List
    if (list->data[0] == NULL) {
        return NULL;
    }

    // check for invalid loc
    if (loc < 0 || loc > list->length - 1) {
        return NULL;
    }

    // extract Data item
    Data* data = list->data[loc];
    
    // shuffle list down to remove the gap
    for (int i=loc; i<list->length; i++) {
        list->data[i] = list->data[i+1];
    }

    // decrease list length
    list->length--;

    return data;
}

/*
 * display List data - traverse list from front to back
 */
void displayList ( List *list ) {
    printf("List length %d\n",list->length);
    for( int k=0; k<list->length; ++k )
        printf(" %d",list->data[k]->value);
    printf("\n");
    return;
}

/*
 * free dynamic array data
 */
void freeList( List *list ) {
    for( int k=0; k<list->size; ++k )
        free( list->data[k] ); // free List Data item
    free( list->data );        // free List Data array
    return;
}
