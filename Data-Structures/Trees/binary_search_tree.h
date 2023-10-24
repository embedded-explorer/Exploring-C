//----------------------------------------------------------------------
// Binary Search Tree
//----------------------------------------------------------------------
#define SUCCESS 1
#define FAILURE 0

// Structure definition for Binary Tree
typedef struct _bstree_ BSTree;
struct _bstree_{
	int data;
	BSTree *lchild;
	BSTree *rchild;
};

// Function to insert node
BSTree *create_bstree(BSTree *root, int element);

// Function to search node
BSTree *search_bstree(BSTree *root, int element);

// Function to delete node
BSTree *delete_bstree(BSTree *root, int element);

// Function to print binary search tree in ascending
void print_bstree_ascending(BSTree *root);

// Function to print binary search tree in descending
void print_bstree_descending(BSTree *root);

// Function to deallocate binary tree
BSTree *deallocate_bstree(BSTree *root);