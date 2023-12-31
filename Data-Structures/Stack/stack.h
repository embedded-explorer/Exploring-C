/*
//----------------------------------------------------------------------
// Stack - Array Implementation (Dynamic Array)
//----------------------------------------------------------------------

#define SUCCESS 1
#define FAILURE 0

typedef struct _stack_ Stack;
struct _stack_ {
	int *data; // Actual content
    int size; // Requested stack size
	int top; // Stack top
};

// Stack initialization function
Stack *stack_initialize(int size);

// Push Function, returns status
int stack_push(Stack *my_stack, int data);

// Pop Function, returns data
int stack_pop(Stack *my_stack);

// Peek Function, returns data
int stack_peek(Stack *my_stack);

// Deallocate Function, returns NULL pointer
Stack *stack_deallocate(Stack *my_stack);
*/

//----------------------------------------------------------------------
// Stack - Linked List Implementation
//----------------------------------------------------------------------

#define SUCCESS 1
#define FAILURE 0

// Structure definition of node
typedef struct _node_ Node;
struct _node_{
    int data;  // Data
    Node *ptr; // Next node pointer
};

// Structure definition of stack
typedef struct _stack_ Stack;
struct _stack_{
    Node *head; // Head
};

// Stack initialization function
Stack *stack_initialize();

// Push Function, returns status
int stack_push(Stack *my_stack, int data);

// Pop Function, returns data
int stack_pop(Stack *my_stack);

// Peek Function, returns data
int stack_peek(Stack *my_stack);

// Deallocate Function, returns NULL pointer
Stack *stack_deallocate(Stack *my_stack);
