
//----------------------------------------------------------------------
// Binary Tree - Linked List Implementation
//----------------------------------------------------------------------
#define SUCCESS 1
#define FAILURE 0

// Structure definition for Binary Tree
typedef struct _btree_ BTree;
struct _btree_{
	int data;
	BTree *lchild;
	BTree *rchild;
};

// Structure definition of Queue for level order traversal
// Structure definition of node
typedef struct _node_ Node;
struct _node_{
    BTree *root; // Data
    Node *ptr; // Next node pointer
};

// Structure definition of Queue
typedef struct _queue_ Queue;
struct _queue_{
    Node *head;
	Node *tail;
};

// Function to create binary tree
BTree *create_btree();

// Inorder Traversal
void inorder(BTree *root);

// Preorder Traversal
void preorder(BTree *root);

// Postorder Traversal
void postorder(BTree *root);

// Level Order Traversal
void levelorder(BTree *root);

// Function to deallocate binary tree
BTree *deallocate_btree(BTree *root);