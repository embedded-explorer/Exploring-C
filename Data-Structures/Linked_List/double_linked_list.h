
//----------------------------------------------------------------------
// Doubly Linked List Example
//----------------------------------------------------------------------

#define SUCCESS 1
#define FAILURE 0

// Structure definition of node
typedef struct _node_ Node;
struct _node_{
    int data;  // Data
	Node *prev_ptr; // Previous Node Pointer
    Node *next_ptr; // Next Node pointer
};

// Structure definition of list
typedef struct _list_ List;
struct _list_{
	int count;  // Count of elements
    Node *head; // Head
	Node *tail; // Tail
};

// Function to create and initialize list
List *initialize_list();

// Function to insert data at beginning
int insert_at_beginning(List *my_list, int data);

// Function to insert data at end
int insert_at_end(List *my_list, int data);

// Function to delete data at beginning
int delete_at_beginning(List *my_list);

// Function to delete data at end
int delete_at_end(List *my_list);

// Function to deallocate list
List *deallocate_list(List *my_list);