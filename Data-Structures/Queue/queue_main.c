#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

int main(){
/*
//----------------------------------------------------------------------
// Queue - Array Implementation (Dynamic Array)
//----------------------------------------------------------------------
    #define QUEUE_SIZE 5
	Queue *test_queue;
	int i;

	// Test initialization function
	test_queue = queue_initialize(QUEUE_SIZE);
	assert(test_queue != NULL);
	assert(test_queue->data != NULL);
	assert(test_queue->count == 0);
	assert(test_queue->size == QUEUE_SIZE);
	assert(test_queue->head == 0);
	assert(test_queue->tail == 0);


	// Test Insert function
	for(i=0; i<5; i++){
		assert(enqueue(test_queue, i*10 + 10) == SUCCESS); // insert 10 to 50
		assert(test_queue->count == i+1);
	    assert(test_queue->head == 0);
	    assert(test_queue->tail == (i+1) % 5);
	}
	assert(test_queue->count == 5);
	assert(test_queue->head == 0);
	assert(test_queue->tail == 0);

	// Insert to full queue
	assert(enqueue(test_queue, 60) == FAILURE);
	assert(test_queue->count == 5);
	assert(test_queue->head == 0);
	assert(test_queue->tail == 0);

	// Test Remove function
	assert(dequeue(test_queue) == 10);
	assert(dequeue(test_queue) == 20);
	assert(test_queue->count == 3);
	assert(test_queue->head == 2);
	assert(test_queue->tail == 0);

	// Add and Remove elements
	assert(enqueue(test_queue, 60) == SUCCESS);
	assert(enqueue(test_queue, 70) == SUCCESS);
	assert(test_queue->count == 5);
	assert(test_queue->head == 2);
	assert(test_queue->tail == 2);

	assert(dequeue(test_queue) == 30);
	assert(dequeue(test_queue) == 40);
	assert(dequeue(test_queue) == 50);
	assert(dequeue(test_queue) == 60);
	assert(test_queue->count == 1);
	assert(test_queue->head == 1);
	assert(test_queue->tail == 2);

	// Deallocate memory
	test_queue = queue_deallocate(test_queue);
	assert(test_queue == NULL);
*/

//----------------------------------------------------------------------
// Queue - Linked List Implementation
//----------------------------------------------------------------------
	Queue *test_queue;
	int i;

	// Test initialization function
	test_queue = queue_initialize();
	assert(test_queue != NULL);
	assert(test_queue->head == NULL);
	assert(test_queue->tail == NULL);

	// Test Insert function
	for(i=1; i<6; i++){
		assert(enqueue(test_queue, i*10) == SUCCESS); // insert 10 to 50
		assert(test_queue->tail->data == i*10);
	}
	assert(test_queue->head->data == 10);
	assert(test_queue->tail->data == 50);

	// Test Remove function
	for(i=1; i<6; i++){
		assert(dequeue(test_queue) == i*10);
	}
	assert(test_queue->head == NULL);
	assert(test_queue->tail == NULL);
	
	// Add and Remove
	assert(enqueue(test_queue, 70) == SUCCESS);
	assert(test_queue->tail->data == 70);
	assert(test_queue->head->data == 70);
	
	assert(dequeue(test_queue) == 70);
    assert(test_queue->head == NULL);
	assert(test_queue->tail == NULL);
	
	// Deallocate memory
	test_queue = queue_deallocate(test_queue);
	assert(test_queue == NULL);

    return 0;
}
