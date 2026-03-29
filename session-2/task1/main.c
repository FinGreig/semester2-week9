
#include <stdio.h>
#include <stdlib.h>

#include "node_structures.h"
#include "node.h"
#include "list_structures.h"
#include "list.h"

int main( void ) {

    // create an empty list
    List *list = createList();

    // add some nodes
    addNode(list,(Node *)NULL,1); // add at head - special case - pass NULL

    // display the list
    traverseI(list->head);

    // add and delete more nodes with addNode() and removeNode()
    addNode(list,list->head->next,35);
    addNode(list,list->head->next->next,8);
    addNode(list,list->head->next,5);
    traverseI(list->head);

    Node* deleted = removeNode(list,list->head->next); //should remove 5
    traverseI(list->head);

    // deallocate deleted nodes - test with valgrind to check this
    freeNode(deleted);

    // free list memory
    freeNodes( list->head );
    free(list);

    return 0;
}
