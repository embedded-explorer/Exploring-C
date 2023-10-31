/*
//----------------------------------------------------------------------
// 1.
// Hash table of size 10 to store integer values - open hashing
//----------------------------------------------------------------------

#define SUCCESS 1
#define FAILURE 0

#define TABLE_SIZE 10

// Structure definition of node
typedef struct _node_ Node;
struct _node_{
    int data;  // Data
    Node *ptr; // Next node pointer
};

// Structure definition of Hash Table
typedef struct _hash_table_ Hash_Table;
struct _hash_table_{
	Node* table[TABLE_SIZE];
};

// Function to create and initialize table
Hash_Table *initialize_table();

// Function to insert a value
int insert_value(Hash_Table *table, int value);

// Function to search a value
int search_value(Hash_Table *table, int value);

// Function to delete a value
int delete_value(Hash_Table *table, int value);

// Function to print table
void print_table(Hash_Table* table);
*/

/*
//----------------------------------------------------------------------
// 2.
// Double Pointer Implementation using Linked List - open hashing
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

// Function to initialize hash table
List **initialize_ht(int size);

// Function to search entry within hash table
int search_ht(List **my_table, int data, int size);

// Function to insert unique element in sorted order to hash table
int insert_ht(List **my_table, int data, int size);

// Function to delete element
int delete_ht(List **my_table, int data, int size);

// Function to print hash table
void print(List** my_table, int size);
*/

//----------------------------------------------------------------------
// 3.
// Insert Names in alphabetical order
//----------------------------------------------------------------------

#define SUCCESS 1
#define FAILURE 0
#define NAME_SIZE 20

// Structure definition of node
typedef struct _node_ Node;
struct _node_{
    char name[NAME_SIZE];  // Data
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

// Function to initialize hash table
List **initialize_ht(int size);

// Function to search entry within hash table
int search_ht(List **my_table, char *name, int size);

// Function to insert
int insert_ht(List **my_table, char *name, int size);

// Function to delete element
int delete_ht(List **my_table, char *name, int size);

// Function to print hash table
void print(List** my_table, int size);