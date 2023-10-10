#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "list_operations.h"

int main(){
/*
//----------------------------------------------------------------------
// Function to split given list at given Index
//----------------------------------------------------------------------
    List *list_a, *list_b, *list_c;
    
	// Initialize List A
    list_a = initialize_list();
	assert(list_a != NULL);
	assert(list_a->count == 0);
    assert(list_a->head == NULL && list_a->tail == NULL);
    
	// Insert elements to list A
	assert(insert_at_end(list_a, 2) == SUCCESS);
	assert(insert_at_end(list_a, 3) == SUCCESS);
	assert(insert_at_end(list_a, 5) == SUCCESS);
	assert(insert_at_end(list_a, 7) == SUCCESS);
	assert(insert_at_end(list_a, 8) == SUCCESS);
    assert(insert_at_end(list_a, 10) == SUCCESS);
    assert(insert_at_end(list_a, 20) == SUCCESS);
    assert(list_a->count == 7);
    assert(list_a->head->data == 2);
    assert(list_a->tail->data == 20);
	
	// Test Split List Function
	// 1. Index greater than count
	list_b = split_list(list_a, 7);
	assert(list_b == NULL);
	// 2. Index is 0 entire list is copied
	list_b = split_list(list_a, 0);
	assert(list_a->head == NULL && list_a->tail == NULL);
	assert(list_a->count == 0);
	assert(list_b->count == 7);
    assert(list_b->head->data == 2);
    assert(list_b->tail->data == 20);
	// 3. Index is in between
	printf("List 1: ");
	print_list(list_b);
	list_c = split_list(list_b, 3);
	printf("List 1: ");
	print_list(list_b);
	printf("List 2: ");
	print_list(list_c);
	
	// Deallocate Memory
	list_a = deallocate_list(list_a);
    list_b = deallocate_list(list_b);
    list_c = deallocate_list(list_c);
*/


//----------------------------------------------------------------------
// Function to merge two sorted lists in sorted order
//----------------------------------------------------------------------
    List *list_a, *list_b, *list_c;
    
    // Initialize List A
	list_a = initialize_list();
	assert(list_a != NULL);
	assert(list_a->count == 0);
	assert(list_a->head == NULL && list_a->tail == NULL);

    // Initialize List B
    list_b = initialize_list();
	assert(list_b != NULL);
	assert(list_b->count == 0);
	assert(list_b->head == NULL && list_b->tail == NULL);

	// Insert elements to list A
	assert(insert_at_end(list_a, 2) == SUCCESS);
	assert(insert_at_end(list_a, 3) == SUCCESS);
	assert(insert_at_end(list_a, 5) == SUCCESS);
	assert(insert_at_end(list_a, 7) == SUCCESS);
	assert(insert_at_end(list_a, 8) == SUCCESS);
    assert(insert_at_end(list_a, 10) == SUCCESS);
    assert(insert_at_end(list_a, 20) == SUCCESS);
    assert(list_a->count == 7);
    assert(list_a->head->data == 2);
    assert(list_a->tail->data == 20);

    // Insert elements to list B
    assert(insert_at_end(list_b, 2) == SUCCESS);
	assert(insert_at_end(list_b, 6) == SUCCESS);
	assert(insert_at_end(list_b, 9) == SUCCESS);
	assert(insert_at_end(list_b, 15) == SUCCESS);
	assert(insert_at_end(list_b, 20) == SUCCESS);
    assert(list_b->count == 5);
    assert(list_b->head->data == 2);
    assert(list_b->tail->data == 20);

    // Test Function to merge two sorted lists in sorted order
	printf("List 1: ");
	print_list(list_a);
	printf("List 2: ");
	print_list(list_b);
    list_c = merge_sorted_lists(list_a, list_b);
	printf("List 3: ");
	print_list(list_c);

    return 0;
}