
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

//----------------------------------------------------------------------
// 2.
// Hash table to store Names in alphabetical order - open hashing
//----------------------------------------------------------------------
