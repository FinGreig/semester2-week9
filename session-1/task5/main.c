
#include <stdio.h>
#include <stdlib.h>

#include "queue_structures.h"
#include "queue.h"

int main( void ) {

    Queue *queue = createQueue();

    // code to test join, leave and display functions
    Data *data1 = createData(5);
    join(queue,data1);
    Data *data2 = createData(2);
    join(queue,data2);
    Data *data3 = createData(8);
    join(queue,data3);
    Data *data4 = createData(7);
    join(queue,data4);
    Data *data5 = createData(1);
    join(queue,data5);
    Data *data6 = createData(3);
    join(queue,data6);
    Data *data7 = createData(9);
    join(queue,data7);
    displayQueue(queue);

    Data *dataleaving = leave(queue);
    displayQueue(queue);

    // free queue dynamic memory
    freeQueue( queue );
    free( queue );
    
    return 0;
}
