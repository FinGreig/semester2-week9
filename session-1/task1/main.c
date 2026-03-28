
#include <stdio.h>
#include <stdlib.h>

#include "node_structures.h"
#include "node.h"

int main( void ) {

    // create some nodes
    Node *first = createNode(createData(1));
    Node *second = createNode(createData(2));
    Node *third = createNode(createData(3));

    // link the nodes
    first->next = second;
    second->next = third;
    
    // print the data by following links
    traverseI( first );

    traverseW( first );

    traverseR( first );

    //prepend node
    Node *newNode = createNode(createData(4));
    newNode->next = first;

    traverseR( newNode );

    //insert node in middle
    Node *new2 = createNode(createData(5));
    new2->next = second->next;
    second->next = new2;

    traverseR( newNode );

    //delete node
    first->next = second->next;
    freeNode(second);

    traverseR( newNode );

    // free all node memory (using traversal)
    freeNodes( first );

    return 0;
}
