
typedef struct _data {
    int value;
} Data;

typedef struct _queue {
    int blockSize;          // default block-size
    int size;               // currently allocated size
    struct _data **data;    // queue array of Data*
    
    // define indices for queue back, front and length
    int front;
    int back;
    int length;
} Queue;
