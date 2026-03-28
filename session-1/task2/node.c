
#include <stdio.h>
#include <stdlib.h>

#include "node_structures.h"
#include "node.h"

/*
 * create Data item
 */
Data *createData( int val ) {
    Data *new = malloc( sizeof(Data) );
    new->value = val;
    return new;
}

/*
 * create Node item
 */
Node *createNode( Data *data ) {
    Node *new = malloc( sizeof(Node) );
    new->data = data;
    new->next = NULL;
    return new;
}

/*
 * free a Node and the attached Data
 */
void freeNode( Node *node ) {
    if( node != NULL ) {
        free(node->data);         // free Data first
        free(node);               // then the Node
    }
    return;
}

/*
 * free all nodes in the linked structure
 */
void freeNodes( Node *node ) {
    while( node!=NULL ) {
        Node *next=node->next;
        freeNode(node);
        node=next;
    }
    return;
}

/*
 * iteration-based traversal 
 */
void traverseI( Node *start ) {  

    for( Node *node=start; node!=NULL; node=node->next ) {
        printf(" %d",node->data->value);
    }
    printf("\n");
    return;
}

/*
 * while-based traversal
 */
void traverseW( Node *node ) {  

    do {
        printf(" %d",node->data->value);
        node = node->next;
    } while (node != NULL);

    printf("\n");

    return;
}

/*
 * recursive traversal
 */
void traverseR( Node *node ) {

    if (node == NULL){
        printf("\n");
        return;

    }   else {

        printf(" %d",node->data->value);
        return traverseR( node -> next );
    }
    
}

