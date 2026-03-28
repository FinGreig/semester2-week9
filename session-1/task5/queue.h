
Data *createData( int val );
Queue *createQueue( void );
void enlargeQueue( Queue *queue );

void displayQueue( Queue *queue );
void freeQueue( Queue *queue );
void shiftQueue( Queue *queue );

void join( Queue *queue, Data *data );
Data *leave( Queue *queue );
