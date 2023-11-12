
//----------------------------------------------------------------------
// 1. Adjacency List
//----------------------------------------------------------------------

#define SUCCESS 1
#define FAILURE 0

#define MAX 5

// Structure definition of node
typedef struct _node_ Node;
struct _node_{
    int node_id;  // Data
    Node *node_ptr; // Next node pointer
};

// Structure definition of list
typedef struct _list_ List;
struct _list_{
	int count;  // Count of elements
    Node *head; // Head
	Node *tail; // Tail
};

// Structure definition of Queue
typedef struct _queue_ Queue;
struct _queue_{
    Node *head;
	Node *tail;
};

// Function to create and initialize list
List *initialize_list();

// Function to insert data at end
int insert_at_end(List *my_list, int data);

// Function to create adjacency list
void create_adjacency_list(List* graph[], int size);

// Function to print adjacency list
void print(List* graph[], int size);

// Function to traverse graph using DFS
void dfs(List* graph[], int vertex, int visited[]);

// Function to traverse graph using BFS
void bfs(List* graph[], int vertex, int visited[]);