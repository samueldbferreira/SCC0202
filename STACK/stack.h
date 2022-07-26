typedef struct {
    int size;
    int* items;
} Stack_t;

Stack_t* createStack();

int push(int x, Stack_t* s);

int isEmpty(Stack_t* s);

int pop(int* x, Stack_t* s);

int top(int* x, Stack_t* s);

void destroyStack(Stack_t* s);
