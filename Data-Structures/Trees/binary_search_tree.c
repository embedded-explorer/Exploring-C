//----------------------------------------------------------------------
// Binary Search Tree
//----------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include "binary_search_tree.h"

//--------------------------------------------------
// Function to insert node
// @param  : BSTree* Root Node
// @param  : int element
// @return : BTree*, Root Node
//--------------------------------------------------
BSTree *create_bstree(BSTree *root, int element){
	
	if(root == NULL){
	// Inserting Element
		root = (BSTree *)malloc(sizeof(BSTree));
		root->data = element;
		root->lchild = NULL;
		root->rchild = NULL;
	}
	else if(root->data == element){
	// Element is already present
	    printf("Element Already Exists\n");
	}
	else if(root->data > element){
	// Insert at left (when element is smaller than data)
	    root->lchild = create_bstree(root->lchild, element);
	}
	else if(root->data < element){
    // Insert at right (when element is greater than data)
	    root->rchild = create_bstree(root->rchild, element);
	}
	
	return root;
}

//--------------------------------------------------
// Function to search node
// @param  : BSTree* Root Node
// @param  : int element
// @return : BTree*, Root Node
//--------------------------------------------------
BSTree *search_bstree(BSTree *root, int element){
	if(root == NULL){
		printf("Element Not Found\n");
	}
	else if(root->data == element){
		printf("Element Found\n");
	}
	else if(root->data > element){
	// If element is lesser than root search left
		root->lchild = search_bstree(root->lchild, element);
	}
	else if(root->data < element){
	// If element is greater than root search right
		root->rchild = search_bstree(root->rchild, element);
	}
	
	return root;
}

//--------------------------------------------------
// Function to find minimum element in subtree
// @param  : BSTree* Root Node
// @return : BTree*, Root Node
//--------------------------------------------------
BSTree *find_min(BSTree *root){
	if(root == NULL)
		return root;
	else if(root->lchild == NULL)
		return root;
	else
		return(find_min(root->lchild));
}

//--------------------------------------------------
// Function to delete node
// @param  : BSTree* Root Node
// @param  : int element
// @return : BTree*, Root Node
//--------------------------------------------------
BSTree *delete_bstree(BSTree *root, int element){
	BSTree *temp;
	
	if(root == NULL){
		printf("Element Not Found\n");
	}
	else if(root->data > element){
	// If element is lesser than root delete from left
		root->lchild = delete_bstree(root->lchild, element);
	}
	else if(root->data < element){
	// If element is greater than root delete from right
		root->rchild = delete_bstree(root->rchild, element);
	}
	else if(root->lchild && root->rchild){
	// If element is found and if it has both left and right child
	    temp = find_min(root->rchild);
		root->data = temp->data;
		root->rchild = delete_bstree(root->rchild, root->data);
	}
	else{
	// If element is found and if it has only left or right child
	    temp = root;
		if(root->lchild == NULL)
			root = root->rchild;
		else if(root->rchild == NULL)
			root = root->lchild;
		
		free(temp);
	}
	
	return root;
}

//--------------------------------------------------
// Function to print binary search tree in ascending
// @param  : BSTree* Root Node
//--------------------------------------------------
void print_bstree_ascending(BSTree *root){
	if(root){
		print_bstree_ascending(root->lchild);
		printf("%d ", root->data);
		print_bstree_ascending(root->rchild);
	}
}

//--------------------------------------------------
// Function to print binary search tree in descending
// @param  : BSTree* Root Node
//--------------------------------------------------
void print_bstree_descending(BSTree *root){
	if(root){
		print_bstree_descending(root->rchild);
		printf("%d ", root->data);
		print_bstree_descending(root->lchild);
	}
}