//----------------------------------------------------------------------
// Binary Tree - Linked List Implementation
//----------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"

//--------------------------------------------------
// Function to create binary tree
// @return : BTree*, Root Node
//--------------------------------------------------
BTree *create_btree(){
	BTree *new_node;
	new_node = NULL;
	int data;
	
	// Enter Root Node
	printf("Enter Data: ");
	scanf("%d", &data);
	
	if(data != 999){
		// Allocate memory for new node
		new_node = (BTree *)malloc(sizeof(BTree));
		new_node->data = data;
		
		// Add Left Child
		printf("Enter Left Child of %d\n", data);
		new_node->lchild = create_btree();
		
		// Add Righ Child
		printf("Enter Right Child of %d\n", data);
		new_node->rchild = create_btree();
	}
	return new_node;
}

//--------------------------------------------------
// Inorder Traversal
// @return : BTree*, Root Node
//--------------------------------------------------
void inorder(BTree *root){
	if(root){
		inorder(root->lchild);
		printf("%d ", root->data);
		inorder(root->rchild);
	}
}

//--------------------------------------------------
// Preorder Traversal
// @return : BTree*, Root Node
//--------------------------------------------------
void preorder(BTree *root){
	if(root){
		printf("%d ", root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}

//--------------------------------------------------
// Postorder Traversal
// @return : BTree*, Root Node
//--------------------------------------------------
void postorder(BTree *root){
	if(root){
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%d ", root->data);
	}
}

//----------------------------------------------------------------------------
// Queue Implementation for Level Order Traversal
//----------------------------------------------------------------------------
// Queue initialization function
Queue *queue_initialize(){
	Queue *my_queue;

	// Allocate memory for queue
	my_queue = (Queue *)malloc(sizeof(Queue));

	if(my_queue == NULL)
		return NULL; // Memory allocation failed

	// Initialize
	my_queue->head = NULL;
	my_queue->tail = NULL;

	return my_queue;
}

// Function to create new node
Node *create_node(BTree *root){
	Node *new_node;

	new_node = (Node *)malloc(sizeof(Node));

	if(new_node == NULL)
		return NULL; // Memory allocation failed

	new_node->root = root;
	new_node->ptr  = NULL;

	return new_node;
}

// Insert Function, returns status
int enqueue(Queue *my_queue, BTree *root){
	Node *new_node;
    new_node = create_node(root);
	
	if(new_node == NULL)
		return FAILURE;

	// Insert at end
	if(my_queue->tail == NULL){
    // Inserting first node
		my_queue->tail = new_node;
		my_queue->head = new_node;
	}
	else{
		my_queue->tail->ptr = new_node;
	    my_queue->tail = new_node;
	}

	return SUCCESS;
}

// Remove Function, returns data
BTree *dequeue(Queue *my_queue){
	Node *temp;
	BTree *root;

	// Remove data only if queue is not empty
	if(my_queue->head == NULL)
		return FAILURE;

	// Remove from beginning
	temp = my_queue->head;
	my_queue->head = temp->ptr;
	root = temp->root;
	free(temp);
	
	if(my_queue->head == NULL){
		my_queue->tail = NULL;
	}
	
	return root;
}

// Deallocate Function, returns NULL pointer
Queue *queue_deallocate(Queue *my_queue){
	Node *temp;

	while(my_queue->head != NULL){
		temp = my_queue->head;
		my_queue->head = temp->ptr;
		free(temp);
	}

	free(my_queue);

	return NULL;
}
//----------------------------------------------------------------------------

//--------------------------------------------------
// Level Order Traversal
// @return : BTree*, Root Node
//--------------------------------------------------
void levelorder(BTree *root){
	Queue *queue;
	
	if(root == NULL)
		return;
	
	queue = queue_initialize();
	enqueue(queue, root);
	
	for(;;){
		root = dequeue(queue);
		if(root){
			printf("%d ", root->data);
			if(root->lchild)
				enqueue(queue, root->lchild);
			if(root->rchild)
				enqueue(queue, root->rchild);
		}
		else
			break;
	}
	
	queue = queue_deallocate(queue);
}