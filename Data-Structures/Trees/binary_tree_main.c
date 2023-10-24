//----------------------------------------------------------------------
// Binary Tree - Linked List Implementation
//----------------------------------------------------------------------
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "binary_tree.h"

int main(){

    BTree *root;
	root = NULL;
	
	root = create_btree();
	
	// Inorder
	printf("\nInorder Traversal: ");
	inorder(root);
	
	// Preorder
	printf("\nPreorder Traversal: ");
	preorder(root);
	
	// Postorder
	printf("\nPostorder Traversal: ");
	postorder(root);
	
	// Levelorder
	printf("\nLevelorder Traversal: ");
	levelorder(root);
	
    return 0;
}