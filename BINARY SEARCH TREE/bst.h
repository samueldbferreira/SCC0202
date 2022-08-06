typedef struct node Node_t;
typedef struct tree Tree_t;

Tree_t* createTree();

int isEmpty(Tree_t* t);

int insert(int x, Tree_t* t);

int maxValue(int* x, Tree_t* t);

int minValue(int* x, Tree_t* t);

int inTree(int x, Tree_t* t);

int delete(int x, Tree_t* t);

void printTree(Tree_t* t);

void destroyTree(Tree_t* t);
