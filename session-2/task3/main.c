
#include <stdio.h>
#include <stdlib.h>

#include "tree_node.h"
#include "tree_structure.h"
#include "tree.h"

int main( void ) {
    Tree *tree = makeTree();
    Node *p;
    
    // create a tree
    tree->root = makeNode(makeData(1));
    p = tree->root;
    p->child[0] = makeNode(makeData(2));
    p->child[1] = makeNode(makeData(3));
    p = tree->root->child[0];
    p->child[0] = makeNode(makeData(4));
    p->child[1] = makeNode(makeData(5));
    p = tree->root->child[1];
    p->child[1] = makeNode(makeData(6));
    tree->size = 6;

    // traverse to print node data
    printf("Pre-order\n");
    traversePre( tree->root );

    printf("Post-order\n");
    traversePost( tree->root );

    printf("In-order\n");
    traverseIn( tree->root );

    // free memory
    deallocateTree( tree->root );
    free(tree);

    return 0;
}