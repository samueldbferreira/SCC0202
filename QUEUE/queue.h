typedef struct node Node_t;
typedef struct queue Queue_t;

Queue_t* createQueue();

int isEmpty(Queue_t* q);

int enqueue(int x, Queue_t* q);

int dequeue(int* x, Queue_t* q);

void destroyQueue(Queue_t* q);
