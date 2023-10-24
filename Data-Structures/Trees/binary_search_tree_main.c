//----------------------------------------------------------------------
// Binary Search Tree
//----------------------------------------------------------------------
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "binary_search_tree.h"

int main(){
    int arr[7] = {15, 3, 6, 8, 10, 20, 12};
    BSTree *root;
	root = NULL;
	
	// Test insert function
	for(int i=0; i<7; i++){
	    root = create_bstree(root, arr[i]);
	}
	
	// Test print function
	printf("\nAscending\n");
	print_bstree_ascending(root);
	printf("\n");
	printf("Descending\n");
	print_bstree_descending(root);
	printf("\n");
	
	// Test search function
	printf("\nTesting Search Function\n");
	root = search_bstree(root, 8);
	root = search_bstree(root, 14);
	root = search_bstree(root, 12);
	
	print_bstree_ascending(root);
	printf("\n");
	
	// Test delete function
	printf("\nTesting Delete Function\n");
	root = delete_bstree(root, 3);
	print_bstree_ascending(root);
	printf("\n");
	
	root = delete_bstree(root, 15);
	print_bstree_ascending(root);
	printf("\n");
	
    return 0;
}