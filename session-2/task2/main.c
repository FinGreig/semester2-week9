
#include <stdio.h>
#include <stdlib.h>

#include "list_structures.h"
#include "list.h"

int main( void ) {

    List *list = createList();

    // insert() - add some data to the list
    insert( list, createData(1), 0 ); // add with value 1 at index 0
    displayList( list );

    // further insert operations here, use displayList() to verify
    insert(list,createData(4),1);
    displayList(list);
    insert(list,createData(5),1);
    displayList(list);
    insert(list,createData(6),0);
    displayList(list);

    Data* deleted = delete(list,1);
    displayList(list);

    //free deleted nodes
    free(deleted);

    // free list dynamic memory
    freeList( list );
    free( list );
    
    return 0;
}
