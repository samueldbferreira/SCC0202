typedef struct node Node_t;
typedef struct stack Stack_t;

Stack_t* createStack();

int size(Stack_t* s);

int push(int x, Stack_t* s);

int pop(int* x, Stack_t* s);

int top(int* x, Stack_t* s);

void destroyStack(Stack_t* s);
