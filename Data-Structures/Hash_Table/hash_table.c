
//----------------------------------------------------------------------
// 1.
//----------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include "hash_table.h"

//--------------------------------------------------
// Function to create and initialize table
// @return : Hash_Table* Table pointer
//--------------------------------------------------
Hash_Table *initialize_table(){

    Hash_Table *table;
	int i;

	// Allocate memory for table
	table = (Hash_Table *)malloc(sizeof(Hash_Table));

	if(table == NULL)
		return NULL; // Memory allocation failed

    for(i=0; i<TABLE_SIZE; i++)
		table->table[i] = NULL;

    return table; // Return table pointer
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
// Hash Function
// @param  : int value
// @return : int key
//--------------------------------------------------
int hash(int value){
	return value % TABLE_SIZE;
}

//--------------------------------------------------
// Function to insert a value
// @param  : Table pointer
// @param  : int value
// @return : int status
//--------------------------------------------------
int insert_value(Hash_Table *table, int value){
	int key;
	Node *new_node;
	Node *temp;
	
	new_node = create_node(value);
	if(new_node == NULL)
		return FAILURE; // Insertion Failed
	
	// Call hash function
	key = hash(value);
	
	// If list at key is empty
	if(table->table[key] == NULL){
	// Store new node pointer at key
		table->table[key] = new_node;
	}
	else{
		// Iterate to end of list
		for(temp = table->table[key]; temp->ptr != NULL; temp = temp->ptr);
		temp->ptr = new_node;
	}
	
	return SUCCESS;
}

//--------------------------------------------------
// Function to search a value
// @param  : Table pointer
// @param  : int value
// @return : int status
//--------------------------------------------------
int search_value(Hash_Table *table, int value){
	int key;
	Node *temp;
	
	// Call hash function
	key = hash(value);
	
	for(temp = table->table[key]; temp != NULL; temp = temp->ptr){
		if(temp->data == value){
			return SUCCESS;
		}
	}
	
	return FAILURE;
}

//--------------------------------------------------
// Function to delete a value
// @param  : Table pointer
// @param  : int value
// @return : int status
//--------------------------------------------------
int delete_value(Hash_Table *table, int value){
	int key;
	Node *prev;
	Node *temp;
	
	key = hash(value);
	prev = NULL;
	temp = table->table[key];
	
	// Iterate through list until value is found
	while(temp != NULL && temp->data != value){
		prev = temp;
		temp = temp->ptr;
	}
	
	// Value not present
	if(temp == NULL)
		return FAILURE;
	
	if(prev == NULL){
	// If value is at key position
	    table->table[key] = temp->ptr;
	}
	else{
		prev->ptr = temp->ptr;
	}
	free(temp);
	
	return SUCCESS;
}

//--------------------------------------------------
// Function to print table
// @param  : Table pointer
//--------------------------------------------------
void print_table(Hash_Table* table){
	Node *temp;
	
	for(int i=0; i<TABLE_SIZE; i++){
		printf("%d: ", i);
		for(temp = table->table[i]; temp != NULL; temp = temp->ptr)
			printf("%d -> ", temp->data);
		printf("NULL\n");
	}
}