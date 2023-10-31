/*
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
*/

/*
//----------------------------------------------------------------------
// 2.
//----------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include "hash_table.h"

// Function to create and initialize list
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

// Function to initialize hash table
List **initialize_ht(int size){
	List **my_table;
	int i;
	
	// Allocate memory for double pointer
	my_table = (List **)malloc(sizeof(List *)*size);
	
	// Allocate memory for lists
	for(i=0; i<size; i++)
		my_table[i] = initialize_list();
	
	return my_table;
}

// Function to create node
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

// Hash Function
int hash(int data, int size){
	return data%size;
}

// Function to search given element within list
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

// Function to insert unique element in sorted order
int insert_uniuqe_sorted(List *my_list, int element){
	Node *new_node;
	Node *temp;
	
	// Not unique element
	if(search_list(my_list, element))
		return FAILURE;
	
	new_node = create_node(element);
	
	if(my_list->head == NULL){
	// Inserting First Element
	    my_list->head = new_node;
		my_list->tail = new_node;
	}
	else{
	// Inserting elements
	    if(element < my_list->head->data){
		// If data is minimum insert at beginning
		    new_node->ptr = my_list->head;
			my_list->head = new_node;
		}
		else if(element >= my_list->tail->data){
		// If data is maximum insert at end
		    my_list->tail->ptr = new_node;
			my_list->tail = new_node;
		}
		else{
		// Insert data at proper position
		    for(temp = my_list->head; 
			    temp->ptr != NULL && (element >= temp->ptr->data);
				temp = temp->ptr);
				
			new_node->ptr = temp->ptr;
			temp->ptr = new_node;
		}
	}
	
	my_list->count ++;
	return SUCCESS;
}

// Function to insert unique element in sorted order to hash table
int insert_ht(List **my_table, int data, int size){
	int index;
	List *my_list;
	
    index = hash(data, size);
	my_list = my_table[index];

	return insert_uniuqe_sorted(my_list, data);
}

// Function to print hash table
void print(List** my_table, int size){
	int i;
	Node *temp;
	
	for(i = 0; i<size; i++){
		printf("Index[%d]: ", i);
		
		temp = my_table[i]->head;
		while(temp != NULL){
			printf("%d -> ", temp->data);
			temp = temp->ptr;
		}
		printf("NULL\n");
	}
}

// Function to delete element in list
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

// Function to delete data
int delete_ht(List **my_table, int data, int size){
	int index;
	List *my_list;
	
	index = hash(data, size);
	my_list = my_table[index];
	
	return delete_element(my_list, data);
}

// Function to search entry within hash table
int search_ht(List **my_table, int data, int size){
	int index;
	List *my_list;
	
	index = hash(data, size);
	my_list = my_table[index];
	
	return search_list(my_list, data);
}
*/

//----------------------------------------------------------------------
// 3.
//----------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash_table.h"

// Function to create and initialize list
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

// Function to initialize hash table
List **initialize_ht(int size){
	List **my_table;
	int i;
	
	// Allocate memory for double pointer
	my_table = (List **)malloc(sizeof(List *)*size);
	
	// Allocate memory for lists
	for(i=0; i<size; i++)
		my_table[i] = initialize_list();
	
	return my_table;
}

// Function to create node
Node *create_node(char *name){
	
	Node *new_node; // Pointer for new node
	
	// Allocate memory for node
	new_node = (Node *)malloc(sizeof(Node));
	
	if(new_node == NULL)
		return NULL; // Memory allocation failed
	
	strcpy(new_node->name, name);
	new_node->ptr  = NULL;
	
	return new_node;
}

// Hash Function
int hash(char *name, int size){
	char ch;
	
	ch = name[0];
	
	return (toupper(ch) - 'A')%size;
}

// Function to search given element within list
int search_list(List *my_list, char *name){
	Node* temp;
	
	// If list is empty, no point in searching element
	if(my_list->count == 0)
		return FAILURE;
	
	// Iterate through list until element is found
	for(temp = my_list->head;
	    temp != NULL; 
		temp = temp->ptr){
			
	    if(strcmp(temp->name, name))
			return SUCCESS;
	}
	
	return FAILURE;
	
}

// Function to insert element to list
int insert_list(List *my_list, char *name){
	Node *new_node;
	
	new_node = create_node(name);
	
	if(my_list->head == NULL){
	// Inserting First Element
	    my_list->head = new_node;
		my_list->tail = new_node;
	}
	else{
	// Inserting elements
		new_node->ptr = my_list->head;
		my_list->head = new_node;
	}
	
	my_list->count ++;
	return SUCCESS;
}

// Function to insert
int insert_ht(List **my_table, char *name, int size){
	int index;
	List *my_list;
	
    index = hash(name, size);
	my_list = my_table[index];

	return insert_list(my_list, name);
}

// Function to print hash table
void print(List** my_table, int size){
	int i;
	Node *temp;
	
	for(i = 0; i<size; i++){
		printf("Index[%d]: ", i);
		
		temp = my_table[i]->head;
		while(temp != NULL){
			printf("%s -> ", temp->name);
			temp = temp->ptr;
		}
		printf("NULL\n");
	}
}

// Function to delete element in list
int delete_element(List *my_list, char *name){
	Node *prev;
	Node *temp;
	
	// If list is empty
	if(my_list->count == 0 || my_list == NULL)
		return FAILURE;
	
	prev = NULL;
	temp = my_list->head;
	
	// Iterate through list until element is found
	while(temp != NULL && strcmp(temp->name, name)){
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

// Function to delete data
int delete_ht(List **my_table, char *name, int size){
	int index;
	List *my_list;
	
	index = hash(name, size);
	my_list = my_table[index];
	
	return delete_element(my_list, name);
}

// Function to search entry within hash table
int search_ht(List **my_table, char *name, int size){
	int index;
	List *my_list;
	
	index = hash(name, size);
	my_list = my_table[index];
	
	return search_list(my_list, name);
}