#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int main()
{
/*
//----------------------------------------------------------------------
// Stack - Array Implementation (Dynamic Array)
//----------------------------------------------------------------------
    #define STACK_SIZE 10
	Stack *my_stack;
	int i;
	
	// Test initialization function
	my_stack = stack_initialize(STACK_SIZE);
	assert(my_stack != NULL);
	assert(my_stack->data != NULL);
	assert(my_stack->size == STACK_SIZE);
	
	// Test push function
	for(i=0; i<STACK_SIZE; i++){
		assert(stack_push(my_stack, i*10 + 10)); // insert 10 to 100
	}
	
	// Insert data to full stack
	assert(stack_push(my_stack, 110) == FAILURE);
	
	// Test peek function to check data on stack top
	assert(stack_peek(my_stack) == 100);
	assert(stack_peek(my_stack) == 100);
	assert(stack_peek(my_stack) == 100);
	
	// Test pop function
	for(i=100; i>=STACK_SIZE; i=i-10){
		assert(stack_pop(my_stack) == i);
	}
	
	// Deallocate memory
	my_stack = stack_deallocate(my_stack);
*/

//----------------------------------------------------------------------
// Stack - Linked List Implementation
//----------------------------------------------------------------------
	Stack *my_stack;
	int i;
	
	// Test initialization function
	my_stack = stack_initialize();
	assert(my_stack != NULL);
	assert(my_stack->head == NULL);
	
	// Test push function
	for(i=0; i<10; i++){
		assert(stack_push(my_stack, i*10 + 10)); // insert 10 to 100
	}
	
	// Test peek function to check data on stack top
	assert(stack_peek(my_stack) == 100);
	assert(stack_peek(my_stack) == 100);
	assert(stack_peek(my_stack) == 100);
	
	// Test pop function
	for(i=100; i>=10; i=i-10){
		assert(stack_pop(my_stack) == i);
	}
	
	// Deallocate memory
	my_stack = stack_deallocate(my_stack);
	
    return 0;
}