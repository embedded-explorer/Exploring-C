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