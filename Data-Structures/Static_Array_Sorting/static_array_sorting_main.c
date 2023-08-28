#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "static_array_sorting.h"

int main(){

//----------------------------------------------------------------------
// Static Array List Example
//----------------------------------------------------------------------
    Array test_arr;
    
	// Test initialization function
    test_arr = initialise_array(10);
    assert(test_arr.c_size == 10 && test_arr.t_size == 10);
	display_array(test_arr);
	
	// Test bubble sort - Uncomment to test
	//test_arr = bubble_sort(test_arr);
	//display_array(test_arr);
	
	// Test selection sort - Uncomment to test
	//test_arr = selection_sort(test_arr);
	//display_array(test_arr);
	
	// Test insertion sort - Uncomment to test
	test_arr = insertion_sort(test_arr);
	display_array(test_arr);

    return 0;
}