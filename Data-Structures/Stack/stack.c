/*
//----------------------------------------------------------------------
// Stack - Array Implementation (Dynamic Array)
//----------------------------------------------------------------------
#include <stdlib.h>
#include "stack.h"

// Stack initialization function
Stack *stack_initialize(int size){
	Stack *my_stack;
	
	my_stack = (Stack *)malloc(sizeof(Stack));
	my_stack->data = (int *)malloc(sizeof(int)* size);
	my_stack->size = size;
	my_stack->top = -1;
	
	return my_stack;
}

// Push Function, returns status
int stack_push(Stack *my_stack, int data){
	
	if(my_stack == NULL)
		return FAILURE;
	
	// Insert element only if stack is not full
	if(my_stack->top + 1 < my_stack->size){
		my_stack->top++;
		*(my_stack->data + my_stack->top) = data;
		return SUCCESS;
	}
	
	return FAILURE;
}

// Pop Function, returns data
int stack_pop(Stack *my_stack){
	int data;
	
	if(my_stack == NULL)
		return FAILURE;
	
	// Remove data only if stack is not empty
	if(my_stack->top != -1){
		data = *(my_stack->data + my_stack->top);
		my_stack->top--;
		return data;
	}
	
	return FAILURE;
}

// Peek Function, returns data
int stack_peek(Stack *my_stack){
	
	if(my_stack == NULL)
		return FAILURE;
	
	// Return data only if stack is not empty
	if(my_stack->top != -1){
		return *(my_stack->data + my_stack->top);
	}
	
	return FAILURE;
}

// Deallocate Function, returns NULL pointer
Stack *stack_deallocate(Stack *my_stack){
	free(my_stack->data);
	free(my_stack);
	return NULL;
}
*/

//----------------------------------------------------------------------
// Stack - Linked List Implementation
//----------------------------------------------------------------------
#include <stdlib.h>
#include "stack.h"

// Stack initialization function
Stack *stack_initialize(){
	Stack *my_stack;
	
	// Allocate memory for stack
	my_stack = (Stack *)malloc(sizeof(Stack));
	
	if(my_stack == NULL)
		return NULL; // Memory allocation failed

	my_stack->head = NULL;
	
	return my_stack;
}

// Function to create new node
Node *create_node(int data){
	Node *new_node;
	
	new_node = (Node *)malloc(sizeof(Node));
	
	if(new_node == NULL)
		return NULL; // Memory allocation failed
	
	new_node->data = data;
	new_node->ptr  = NULL;
	
	return new_node;
}

// Push Function, returns status
int stack_push(Stack *my_stack, int data){
	Node *new_node;
	
	new_node = create_node(data);
	
	if(new_node == NULL)
		return FAILURE; // Insertion Failed
	
	// Insert at beginning
	new_node->ptr = my_stack->head;
	my_stack->head = new_node;
	
	return SUCCESS;
}

// Pop Function, returns data
int stack_pop(Stack *my_stack){
	Node *temp;
	int data;
	
	if(my_stack->head == NULL)
		return FAILURE;
	
	// Delete at beginning
	temp = my_stack->head;
	my_stack->head = temp->ptr;
	data = temp->data;
	free(temp);
	
	return data;
}

// Peek Function, returns data
int stack_peek(Stack *my_stack){
	
	if(my_stack->head == NULL)
		return FAILURE;
	
	return my_stack->head->data;
}

// Deallocate Function, returns NULL pointer
Stack *stack_deallocate(Stack *my_stack){
	Node *temp;
	
	while(my_stack->head != NULL){
		temp = my_stack->head;
		my_stack->head = temp->ptr;
		free(temp);
	}
	
	free(my_stack);
	
	return NULL;
}