
//----------------------------------------------------------------------
// Doubly Linked List Example
//----------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include "double_linked_list.h"

//--------------------------------------------------
// Function to create and initialize list
// @return : List pointer
//--------------------------------------------------
List *initialize_list(){

    List *my_list;

	// Allocate memory for list
	my_list = (List *)malloc(sizeof(List));

	if(my_list == NULL)
		return NULL; // Memory allocation failed

    my_list->head = NULL;
	my_list->tail = NULL;
	my_list->count = 0;

    return my_list; // Return list pointer
}

//--------------------------------------------------
// Function to create node
// @param  : int data
// @return : Node pointer
//--------------------------------------------------
Node *create_node(int data){
	
	Node *new_node; // Pointer for new node
	
	// Allocate memory for node
	new_node = (Node *)malloc(sizeof(Node));
	
	if(new_node == NULL)
		return NULL; // Memory allocation failed
	
	new_node->data = data;
	new_node->prev_ptr  = NULL;
	new_node->next_ptr  = NULL;
	
	return new_node;
}

//--------------------------------------------------
// Function to insert data at beginning
// @param  : List pointer
// @param  : int data
// @return : int status
//--------------------------------------------------
int insert_at_beginning(List *my_list, int data){
	
	Node *new_node; // Pointer for new node
	
	new_node = create_node(data);
	
	if(new_node == NULL)
		return FAILURE; // Insertion Failed
	
	// If list is empty
	if(my_list->count == 0){
	// Both head and tail poit to same node
		my_list->head = new_node;
		my_list->tail = new_node;
	}
	else{
		my_list->head->prev_ptr = new_node;
		new_node->next_ptr = my_list->head;
		my_list->head = new_node; // Head points to new node
	}
	
	my_list->count++;
	
	return SUCCESS;
}

//--------------------------------------------------
// Function to insert data at end
// @param  : List pointer
// @param  : int data
// @return : int status
//--------------------------------------------------
int insert_at_end(List *my_list, int data){
	
	Node *new_node; // Pointer for new node
	
	new_node = create_node(data);
	
	if(new_node == NULL)
		return FAILURE; // Insertion Failed
	
	// If list is empty
	if(my_list->count == 0){
	// Both head and tail poit to same node
		my_list->head = new_node;
		my_list->tail = new_node;
	}
	else{
		new_node->prev_ptr = my_list->tail;
		my_list->tail->next_ptr = new_node; // Pointer of node at tail points to new node
		my_list->tail = new_node; // node at tail is updated
	}
	
	my_list->count++;
	
	return SUCCESS;
}

//--------------------------------------------------
// Function to delete data at beginning
// @param  : List pointer
// @return : int status
//--------------------------------------------------
int delete_at_beginning(List *my_list){
	Node* temp;
	
	// If list is empty
	if(my_list->count == 0)
		return FAILURE;
	
	temp = my_list->head;
	// If list has only 1 element then update head and tail to NULL
	if(my_list->count == 1)
		my_list->head = my_list->tail = NULL;
	else{
		my_list->head = my_list->head->next_ptr;
		my_list->head->prev_ptr = NULL;
	}
	
	free(temp);
	my_list->count --;
	
	return SUCCESS;
}

//--------------------------------------------------
// Function to delete data at end
// @param  : List pointer
// @return : int status
//--------------------------------------------------
int delete_at_end(List *my_list){
	Node* temp;
	
	// If list is empty
	if(my_list->count == 0)
		return FAILURE;
	
	temp = my_list->tail;
	// If list has only 1 element then update head and tail to NULL
	if(my_list->count == 1)
		my_list->head = my_list->tail = NULL;
	else{
		my_list->tail = temp->prev_ptr;
        my_list->tail->next_ptr = NULL;		
	}
	
	my_list->count --;
	
	return SUCCESS;
}

//--------------------------------------------------
// Function to deallocate list
// @param  : List pointer
// @return : List pointer
//--------------------------------------------------
List *deallocate_list(List *my_list){
	Node *temp;
	
	while(my_list->head != NULL){
		temp = my_list->head;
		my_list->head = temp->next_ptr;
	}
	
	free(my_list);
	
	return NULL;
}