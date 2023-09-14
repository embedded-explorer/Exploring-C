#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "dynamic_arrays.h"

int main(){


//----------------------------------------------------------------------
// Dynamic Array List Example
//----------------------------------------------------------------------
    Array *test_arr;
    
	// Test initialization function
    test_arr = initialise_array(10);
	assert(test_arr != NULL);
	assert(test_arr->array != NULL);
    assert(test_arr->c_size == 0 && test_arr->t_size == 10);
    
	// Test insert data function
    assert(insert_data(test_arr, 10) == SUCCESS);
    assert(insert_data(test_arr, 90) == SUCCESS);
    assert(insert_data(test_arr, 80) == SUCCESS);
    assert(insert_data(test_arr, 70) == SUCCESS);
    assert(insert_data(test_arr, 30) == SUCCESS);
    assert(insert_data(test_arr, 20) == SUCCESS);
    assert(insert_data(test_arr, 50) == SUCCESS);
    assert(insert_data(test_arr, 60) == SUCCESS);
    assert(insert_data(test_arr, 40) == SUCCESS);
    assert(insert_data(test_arr, 20) == SUCCESS);
    assert(test_arr->c_size == test_arr->t_size);

    // Insert data to a filled array
    assert(insert_data(test_arr, 10) == FAILURE);
    assert(test_arr->c_size == test_arr->t_size);

	// Test search array function
    assert(search(test_arr, 30) == SUCCESS);
    assert(search(test_arr, 90) == SUCCESS);
    assert(search(test_arr, 20) == SUCCESS);
    assert(search(test_arr, 55) == FAILURE);

    // Test deallocate array function
	test_arr = deallocate(test_arr);
	assert(test_arr == NULL);
    return 0;
}