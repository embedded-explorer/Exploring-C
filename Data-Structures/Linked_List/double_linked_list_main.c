#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "double_linked_list.h"

int main(){


//----------------------------------------------------------------------
// Doubly Linked List Example
//----------------------------------------------------------------------
    List *test_list;
    
	// Test initialization function
    test_list = initialize_list();
	assert(test_list != NULL);
	assert(test_list->count == 0);
    assert(test_list->head == NULL && test_list->tail == NULL);
    
	// Test insert data at beginning
	assert(insert_at_beginning(test_list, 10) == SUCCESS);
	assert(insert_at_beginning(test_list, 20) == SUCCESS);
	assert(test_list->count == 2);
	assert(test_list->head->data == 20);
	assert(test_list->tail->data == 10);
	assert(test_list->tail->prev_ptr->data == 20);
	assert(test_list->head->next_ptr->data == 10);
	assert(test_list->head->next_ptr->next_ptr == NULL);
	assert(test_list->head->prev_ptr == NULL);

	// Test insert data at end
	assert(insert_at_end(test_list, 30) == SUCCESS);
	assert(test_list->count == 3);
	assert(test_list->head->data == 20);
	assert(test_list->tail->data == 30);
	assert(test_list->tail->prev_ptr->data == 10);
	assert(test_list->tail->prev_ptr->prev_ptr->data == 20);
	
	// Test delete at beginning
	assert(delete_at_beginning(test_list) == SUCCESS);
	assert(test_list->count == 2);
	assert(test_list->head->data == 10);
	assert(test_list->head->prev_ptr == NULL);
	assert(test_list->head->next_ptr->data == 30);

	// Test delete at end
	assert(delete_at_end(test_list) == SUCCESS);
	assert(test_list->count == 1);
	assert(test_list->head->data == 10);
	assert(test_list->tail->data == 10);
	assert(test_list->tail->next_ptr == NULL);
	assert(test_list->tail->prev_ptr == NULL);
	
	// Test deallocate function
	test_list = deallocate_list(test_list);
	assert(test_list == NULL);
	
    return 0;
}