typedef struct node Node_t;
typedef struct deque Deque_t;

Deque_t* createDeque();

int size(Deque_t* d);

int insertStart(int x, Deque_t* d);

int insertEnd(int x, Deque_t* d);

int deleteStart(int* x, Deque_t* d);

int deleteEnd(int* x, Deque_t* d);

int first(int* x, Deque_t* d);

int last(int* x, Deque_t* d);

void printDeque(Deque_t* d);

void destroyDeque(Deque_t* d);
