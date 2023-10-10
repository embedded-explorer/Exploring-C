
//----------------------------------------------------------------------
// Linked List Example
//----------------------------------------------------------------------

#define SUCCESS 1
#define FAILURE 0

// Structure definition of node
typedef struct _node_ Node;
struct _node_{
    int data;  // Data
    Node *ptr; // Next node pointer
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

// Function to insert data in between, after given element
int insert_in_between(List *my_list, int element, int data);

// Function to insert data in between, after given position
int insert_after_position(List *my_list, int position, int data);

// Function to search given element within list using linear search
int search_list(List *my_list, int element);

// Function to delete data at beginning
int delete_at_beginning(List *my_list);

// Function to delete data at end
int delete_at_end(List *my_list);

// Function to delete an element
int delete_element(List *my_list, int element);

// Function to delete node at given position
int delete_at_position(List *my_list, int position);

// Function to deallocate list
List *deallocate_list(List *my_list);

// Function to split given list at given Index
List *split_list(List *my_list, int index);

// Function to merge two lists
int merge_list(List *list_1, List *list_2);

// Function to find intersection of two lists
List *intersection_list(List *list_1, List *list_2);