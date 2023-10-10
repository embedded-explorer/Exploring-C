#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "linked_list.h"

int main(){


//----------------------------------------------------------------------
// Linked List Example
//----------------------------------------------------------------------
    List *test_list;
    
	// Test initialization function
    test_list = initialize_list();
	assert(test_list != NULL);
	assert(test_list->count == 0);
    assert(test_list->head == NULL && test_list->tail == NULL);
    
	// Test insert data at beginning
	assert(insert_at_beginning(test_list, 10) == SUCCESS);
	assert(test_list->count == 1);
	assert(test_list->head->data == 10);
	assert(test_list->tail->data == 10);
	
	// Test insert data at end
	assert(insert_at_end(test_list, 20) == SUCCESS);
	assert(test_list->count == 2);
	assert(test_list->head->data == 10);
	assert(test_list->head->ptr->data == 20);
	assert(test_list->tail->data == 20);
	
	// Test insert in between, after the element
	// 1. non existing element
	assert(insert_in_between(test_list, 30, 40) == FAILURE);
	assert(test_list->count == 2);
	// 2. In between
	assert(insert_in_between(test_list, 10, 15) == SUCCESS);
	assert(test_list->count == 3);
	assert(test_list->head->data == 10);
	assert(test_list->head->ptr->data == 15);
	assert(test_list->head->ptr->ptr->data == 20);
	assert(test_list->tail->data == 20);
	// 3. At tail
	assert(insert_in_between(test_list, 20, 25) == SUCCESS);
	assert(test_list->count == 4);
	assert(test_list->head->data == 10);
	assert(test_list->head->ptr->data == 15);
	assert(test_list->head->ptr->ptr->data == 20);
	assert(test_list->head->ptr->ptr->ptr->data == 25);
	assert(test_list->tail->data == 25);
	
	// Test insert after given position
	// 1. Invalid positions
	assert(insert_after_position(test_list, 5, 8) == FAILURE);
	// 2. after position 0
	assert(insert_after_position(test_list, 0, 12) == SUCCESS);
	assert(test_list->count == 5);
	assert(test_list->head->data == 10);
	assert(test_list->head->ptr->data == 12);
	assert(test_list->tail->data == 25);
	// 3. at last position
	assert(insert_after_position(test_list, 4, 30) == SUCCESS);
	assert(test_list->count == 6);
	assert(test_list->head->data == 10);
	assert(test_list->tail->data == 30);
	// 4. In between, after position 3
	assert(insert_after_position(test_list, 3, 22) == SUCCESS);
	assert(test_list->count == 7);
	assert(test_list->head->data == 10);
	assert(test_list->head->ptr->data == 12);
	assert(test_list->head->ptr->ptr->data == 15);
	assert(test_list->head->ptr->ptr->ptr->data == 20);
	assert(test_list->head->ptr->ptr->ptr->ptr->data == 22);
	assert(test_list->head->ptr->ptr->ptr->ptr->ptr->data == 25);
	assert(test_list->head->ptr->ptr->ptr->ptr->ptr->ptr->data == 30);
	assert(test_list->tail->data == 30);
	
	// Test search list
	assert(search_list(test_list, 10) == SUCCESS);
	assert(search_list(test_list, 12) == SUCCESS);
	assert(search_list(test_list, 15) == SUCCESS);
	assert(search_list(test_list, 20) == SUCCESS);
	assert(search_list(test_list, 22) == SUCCESS);
	assert(search_list(test_list, 25) == SUCCESS);
	assert(search_list(test_list, 30) == SUCCESS);
	assert(search_list(test_list, 35) == FAILURE);
	
	// Test delete at beginning
	assert(delete_at_beginning(test_list) == SUCCESS);
	assert(test_list->count == 6);
	assert(test_list->head->data == 12);
	
	// Test delete at end
	assert(delete_at_end(test_list) == SUCCESS);
	assert(test_list->count == 5);
	assert(test_list->head->data == 12);
	assert(test_list->tail->data == 25);
	
	// Test delete an element
	// 1. delete element at head
	assert(delete_element(test_list, 12) == SUCCESS);
	assert(test_list->count == 4);
	assert(test_list->head->data == 15);
	// 2. delete element at tail
	assert(delete_element(test_list, 25) == SUCCESS);
	assert(test_list->count == 3);
	assert(test_list->tail->data == 22);
	// 3. delete element in between
	assert(delete_element(test_list, 20) == SUCCESS);
	assert(test_list->count == 2);
	assert(test_list->head->data == 15);
	assert(test_list->tail->data == 22);
	
	insert_at_beginning(test_list, 10);
	// Test delete node at given position
    // 1. delete in between
	assert(delete_at_position(test_list, 1) == SUCCESS);
	assert(test_list->count == 2);
	assert(test_list->head->data == 10);
	assert(test_list->tail->data == 22);
	// 2. delete at first position
	assert(delete_at_position(test_list, 0) == SUCCESS);
	assert(test_list->count == 1);
	assert(test_list->head->data == 22);
	assert(test_list->tail->data == 22);
	// 3. delete at last position
	assert(delete_at_position(test_list, 0) == SUCCESS);
	assert(test_list->count == 0);
	assert(test_list->head == NULL);
	assert(test_list->tail == NULL);
	
	// Test deallocate function
	test_list = deallocate_list(test_list);
	assert(test_list == NULL);
	
    return 0;
}