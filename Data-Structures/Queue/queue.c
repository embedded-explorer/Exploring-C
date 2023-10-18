/*
//----------------------------------------------------------------------
// Queue - Array Implementation (Dynamic Array)
//----------------------------------------------------------------------
#include <stdlib.h>
#include "queue.h"

// Queue initialization function
Queue *queue_initialize(int size){
	Queue *my_queue;

	// Allocate memory for queue
	my_queue = (Queue *)malloc(sizeof(Queue));

	if(my_queue == NULL)
		return NULL; // Memory allocation failed

	// Initialize
	my_queue->count = 0;
	my_queue->size = size;
	my_queue->head = 0;
	my_queue->tail = 0;
	my_queue->data = (int *)malloc(sizeof(int)*size);

	return my_queue;
}

// Insert Function, returns status
int enqueue(Queue *my_queue, int data){

	if(my_queue == NULL)
		return FAILURE;

	// Add data only if queue is not full
	if(my_queue->count < my_queue->size){
		*(my_queue->data + my_queue->tail) = data;
		// Circular Tail Pointer
		my_queue->tail = (my_queue->tail + 1) % my_queue->size;
		my_queue->count ++;
		return SUCCESS;
	}

	return FAILURE;
}

// Remove Function, returns data
int dequeue(Queue *my_queue){
	int data;

	if(my_queue == NULL)
		return FAILURE;

	// Remove data only if queue is not empty
	if(my_queue->count > 0){
		data = *(my_queue->data + my_queue->head);
		// Circular Head Pointer
		my_queue->head = (my_queue->head + 1) % my_queue->size;
		my_queue->count --;
		return data;
	}

	return FAILURE;
}

// Deallocate Function, returns NULL pointer
Queue *queue_deallocate(Queue *my_queue){
	free(my_queue->data);
	free(my_queue);
	return NULL;
}
*/

//----------------------------------------------------------------------
// Queue - Linked List Implementation
//----------------------------------------------------------------------
#include <stdlib.h>
#include "queue.h"

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
Node *create_node(int data){
	Node *new_node;

	new_node = (Node *)malloc(sizeof(Node));

	if(new_node == NULL)
		return NULL; // Memory allocation failed

	new_node->data = data;
	new_node->ptr  = NULL;

	return new_node;
}

// Insert Function, returns status
int enqueue(Queue *my_queue, int data){
	Node *new_node;
    new_node = create_node(data);
	
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
int dequeue(Queue *my_queue){
	Node *temp;
	int data;

	// Remove data only if queue is not empty
	if(my_queue->head == NULL)
		return FAILURE;

	// Remove from beginning
	temp = my_queue->head;
	my_queue->head = temp->ptr;
	data = temp->data;
	free(temp);

	if(my_queue->head == NULL){
		my_queue->tail = NULL;
	}

	return data;
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
