
//----------------------------------------------------------------------
// Linked List Operations
//----------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include "list_operations.h"

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
// Function to print given list
// @param  : List pointer
//--------------------------------------------------
void print_list(List *my_list){
	Node *temp;

	for(temp = my_list->head; temp != NULL; temp = temp->ptr)
		printf("%d ", temp->data);

	printf("\n");

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
	
	return my_list;
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
	
	return new_list;
}

//--------------------------------------------------
// Function to merge two sorted lists in sorted order
// @param  : List A
// @param  : List B
// @return : List C
//--------------------------------------------------
List *merge_sorted_lists(List *list_a, List *list_b){
	List *list_c;
	Node *temp_a, *temp_b;
    
	// Allocate memory for new list
	list_c = initialize_list();
    
    temp_a = list_a->head;
    temp_b = list_b->head;
    
	// Add elements to new list until one of list gets empty
    while(temp_a != NULL && temp_b != NULL){
        if(temp_a->data <= temp_b->data){
		// Add data from list a if its lesser than data in list b
        	if(!search_list(list_c, temp_a->data))
			// Avoid adding if data is already present in list c
                insert_at_end(list_c, temp_a->data);
        	temp_a = temp_a->ptr; // Move to next node in list a
        }
        else{
		// Add data from list b if its lesser
        	if(!search_list(list_c, temp_b->data))
        	    insert_at_end(list_c, temp_b->data);
        	temp_b = temp_b->ptr;
        }
    }
    
	// Add remaining elements in list a
    while(temp_a != NULL){
		if(!search_list(list_c, temp_a->data))
    	    insert_at_end(list_c, temp_a->data);
        temp_a = temp_a->ptr;
    }
    
	// Add remaining elements in list b
    while(temp_b != NULL){
		if(!search_list(list_c, temp_b->data))
    	    insert_at_end(list_c, temp_b->data);
        temp_b = temp_b->ptr;
    }

    return list_c;
}