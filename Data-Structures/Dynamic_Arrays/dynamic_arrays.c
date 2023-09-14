
//----------------------------------------------------------------------
// Dynamic Array List Example
//----------------------------------------------------------------------

#include <stdlib.h>
#include "dynamic_arrays.h"

//--------------------------------------------------
// Function to initialize array
// @param  : int array size
// @return : Array List pointer
//--------------------------------------------------
Array *initialise_array(int size){

    Array *my_arr; // array list pointer

	// Allocate memory for array list
	my_arr = (Array *)malloc(sizeof(Array));

	if(my_arr == NULL)
		return NULL; // Memory allocation failed

    my_arr->c_size = 0; // current size is made zero
    my_arr->t_size = size;

	// Allocate memory for array
	my_arr->array = (int *)malloc(sizeof(int)*size);

	if(my_arr->array == NULL)
		return NULL; // Memory allocation failed

    return my_arr; // Return array list pointer
}

//--------------------------------------------------
// Function to insert data into array
// @param  : Array List pointer
// @param  : int data
// @return : int status
//--------------------------------------------------
int insert_data(Array *my_arr, int data){

    // Check if array is already full
    if(my_arr->c_size == my_arr->t_size)
        return FAILURE; // Failed to insert data

    *(my_arr->array + my_arr->c_size) = data; // Insert data
    my_arr->c_size++; // Increment current size

    return SUCCESS; // Data inserted successfully
}

//--------------------------------------------------
// Function to search given element within array
// using linear search
// @param  : Array List
// @param  : int data
// @return : status
//--------------------------------------------------
int search(Array *my_arr, int element){
    int i;

    for(i=0; i<my_arr->c_size; i++)
        if(*(my_arr->array + i) == element)
			return SUCCESS; // Element is found

    return FAILURE; // Element is not found
}

//--------------------------------------------------
// Function to deallocate array list
// @param  : App_List pointer
// @return : NULL Pointer
//--------------------------------------------------
Array *deallocate(Array *my_arr){
	free(my_arr->array);
	free(my_arr);

	return NULL;
}
