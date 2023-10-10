
//----------------------------------------------------------------------
// Linked List Example
//----------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

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

    return my_list; // Return array list pointer
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
	new_node->ptr  = NULL;
	
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
		new_node->ptr = my_list->head; // New node pointer points to node at head
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
		my_list->tail->ptr = new_node; // Pointer of node at tail points to new node
		my_list->tail = new_node; // node at tail is updated
	}
	
	my_list->count++;
	
	return SUCCESS;
}

//--------------------------------------------------
// Function to insert data in between, after given element
// @param  : List pointer
// @param  : int element
// @param  : int data
// @return : int status
//--------------------------------------------------
int insert_in_between(List *my_list, int element, int data){
	
	Node *new_node; // Pointer for new node
	Node *temp;

	// If list is empty, no point in searching element
	if(my_list->count == 0)
		return FAILURE;
	
	new_node = create_node(data);
	
	if(new_node == NULL)
		return FAILURE; // Insertion Failed
	
	// Iterate through list until element is found
	for(temp = my_list->head;
	    temp != NULL && temp->data != element;
		temp = temp->ptr);
	
	// Element not found
	if(temp == NULL)
		return FAILURE;
	
	// Add the new node to list
	new_node->ptr = temp->ptr;
	
	// Elemnt is found in tail node
	if(temp == my_list->tail)
		my_list->tail = new_node;
	
	temp->ptr = new_node;
	my_list->count ++;

	return SUCCESS;
}

//--------------------------------------------------
// Function to insert data after given position
// @param  : List pointer
// @param  : int position
// @param  : int data
// @return : int status
//--------------------------------------------------
int insert_after_position(List *my_list, int position, int data){
	
	Node *new_node; // Pointer for new node
	Node *temp;
	int i;

	// If list is empty or position is out of range
	if(my_list->count == 0 || position > my_list->count)
		return FAILURE;
	
	new_node = create_node(data);
	
	if(new_node == NULL)
		return FAILURE; // Insertion Failed
	
	// Iterate through list upto given postion
	for(temp = my_list->head, i = 0;
	    temp != NULL && i < position;
		temp = temp->ptr, i++);
	
	// Position out of index
	if(temp == NULL)
		return FAILURE;
	
    new_node->ptr = temp->ptr;
	
	// Adding after last position
	if(position == my_list->count - 1)
		my_list->tail = new_node;
	
    temp->ptr = new_node;
	
	my_list->count ++;

	return SUCCESS;
}

//--------------------------------------------------
// Function to search given element within list
// @param  : List pointer
// @param  : int element
// @return : int status
//--------------------------------------------------
int search_list(List *my_list, int element){
	Node* temp;
	
	// If list is empty, no point in searching element
	if(my_list->count == 0)
		return FAILURE;
	
	// Iterate through list until element is found
	for(temp = my_list->head;
	    temp != NULL && temp->data != element; 
		temp = temp->ptr);
	
	// Element not found
    if(temp == NULL)
		return FAILURE;
	
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
	else
		my_list->head = my_list->head->ptr;
	
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
	
	temp = my_list->head;
	// If list has only 1 element then update head and tail to NULL
	if(my_list->count == 1)
		my_list->head = my_list->tail = NULL;
	else
		for(;temp->ptr != my_list->tail; temp = temp->ptr);
	
	free(temp->ptr);
	my_list->tail = temp;
	my_list->tail->ptr = NULL;
	
	my_list->count --;
	
	return SUCCESS;
}

//--------------------------------------------------
// Function to delete an element
// @param  : List pointer
// @param  : Element
// @return : int status
//--------------------------------------------------
int delete_element(List *my_list, int element){
	Node *prev;
	Node *temp;
	
	// If list is empty
	if(my_list->count == 0 || my_list == NULL)
		return FAILURE;
	
	prev = NULL;
	temp = my_list->head;
	
	// Iterate through list until element is found
	while(temp != NULL && temp->data != element){
		prev = temp;
		temp = temp->ptr;
	}
	
	// Element not found
	if(temp == NULL)
		return FAILURE;
	
	// If element to be deleted is at head
	if(prev == NULL){
		my_list->head = temp->ptr;
		if(my_list->count == 1){
		// If it was only element
		    my_list->tail = NULL;
		}
	}
	else{
		prev->ptr = temp->ptr;
		// If element to be deleted is at tail
		if(temp == my_list->tail){
			my_list->tail = prev;
		}
	}
	
	free(temp);
	
	my_list->count --;
	
	return SUCCESS;
}

//--------------------------------------------------
// Function to delete node at given position
// @param  : List pointer
// @param  : Position
// @return : int status
//--------------------------------------------------
int delete_at_position(List *my_list, int position){
	Node *prev;
	Node *temp;
	int i;
	
	// If list is empty or position out of index
	if(my_list->count == 0 || position >= my_list->count)
		return FAILURE;
	
	prev = NULL;
	temp = my_list->head;
	
	// When position is head
	if(position == 0){
		my_list->head = temp->ptr;
		// If that is only node update tail pointer
		if(my_list->count == 1){
			my_list->tail = NULL;
		}
	}
	else{
		// Traverse until given position
		for(i = 0; i < position; i++){
			prev = temp;
			temp = temp->ptr;
		}
		
		prev->ptr = temp->ptr;
		
		// If position is of last node i.e. tail
		if(temp == my_list->tail){
			my_list->tail = prev;
		}
	}

	free(temp);
	
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
		my_list->head = temp->ptr;
		free(temp);
	}
	
	free(my_list);
	
	return NULL;
}

//--------------------------------------------------
// Function to reset given list
// @param  : List pointer
// @return : List pointer
//--------------------------------------------------
List *reset_list(List *my_list){
	my_list->head = my_list->tail = NULL;
	my_list->count = 0;
}

//--------------------------------------------------
// Function to split given list at given Index
// @param  : List pointer
// @param  : Index
// @return : List pointer
//--------------------------------------------------
List *split_list(List *my_list, int index){
	List *new_list;
	Node *temp;
	int i;
	
	// Check for validity of split index
	if(index < 0 || index >= my_list->count)
		return NULL;
	
	new_list = initialize_list();
	
	// When index is 0 entire list is copied and given list is made NULL
	if(index == 0){
		new_list->head = my_list->head;
		new_list->tail = my_list->tail;
		new_list->count = my_list->count;
		
		my_list = reset_list(my_list);
		return new_list;
	}
	
	// Traverse upto given index
	for(i=0, temp = my_list->head;
     	i<index && temp != NULL;
		i++, temp = temp->ptr);
		
	new_list->head = temp->ptr;
	new_list->tail = my_list->tail;
	new_list->count = my_list->count - index;
	
	my_list->tail = temp;
	my_list->tail->ptr = NULL;
	my_list->count = index;
	
	retun new_list;
}