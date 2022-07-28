typedef struct node Node_t;
typedef struct list List_t;

List_t* createList();

int size(List_t* l);

int insert(int x, List_t* l);

int delete(int x, List_t* l);

int inList(int x, List_t* l);

void printList(List_t* l);

void destroyList(List_t* l);
