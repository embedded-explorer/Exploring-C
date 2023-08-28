
//----------------------------------------------------------------------
// Static Array List Example
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "static_array_sorting.h"

//--------------------------------------------------
// Function to initialize array with random data
// @param  : int array size
// @return : Array List
//--------------------------------------------------
Array initialise_array(int size){
    
    Array my_arr; // variable of type array list
	int i;
	
    my_arr.c_size = 0; // current size is made zero
    my_arr.t_size = size > 0 && size <= MAX_SIZE ? size : MAX_SIZE;
	
	// Insert random data
	for(i=0; i<my_arr.t_size; i++)
		my_arr.array[my_arr.c_size++] = rand() % 33;

    return my_arr; // Return array list
}

//--------------------------------------------------
// Function to display array
// @param  : Array List
// @return : void
//--------------------------------------------------
void display_array(Array my_arr){
    
	int i;
	
	for(i=0; i<my_arr.c_size; i++)
		printf("%d ", my_arr.array[i]);
    
	printf("\n");
}

//--------------------------------------------------
// Function to sort using bubble sort
// @param  : Array List
// @return : Array List
//--------------------------------------------------
Array bubble_sort(Array my_arr){
	int i, j;
	int temp;
	
	for(i=0; i<my_arr.c_size; i++){
		for(j=0; j<(my_arr.c_size-i-1); j++){
			if(my_arr.array[j] > my_arr.array[j+1]){
				// Perform swapping
				temp = my_arr.array[j];
				my_arr.array[j] = my_arr.array[j+1];
				my_arr.array[j+1] = temp;
			}
		}
	}
	
	return my_arr; // Return sorted array
}

//--------------------------------------------------
// Function to sort using selection sort
// @param  : Array List
// @return : Array List
//--------------------------------------------------
Array selection_sort(Array my_arr){
	int i, j;
	int index_of_min, temp;

	for(i=0; i<my_arr.c_size; i++){
		index_of_min = i; // Assume i as index of smallest element
		
		for(j=i; j<my_arr.c_size; j++){
			if(my_arr.array[index_of_min] > my_arr.array[j]){
				index_of_min = j;
			}
		}
		
		// Perform swapping
		temp = my_arr.array[i];
		my_arr.array[i] = my_arr.array[index_of_min];
		my_arr.array[index_of_min] = temp;
	}
	
	return my_arr; // Return sorted array
}

//--------------------------------------------------
// Function to sort using insertion sort
// @param  : Array List
// @return : Array List
//--------------------------------------------------
Array insertion_sort(Array my_arr){
	
	int i, j;
	int key;
	
	for(i=1; i<my_arr.c_size; i++){
		key = my_arr.array[i]; // Next element is taken as key
		j = i-1;
		
		// Shift elements greater than key to right
		while((j>=0) && (my_arr.array[j] > key)){
			my_arr.array[j+1] = my_arr.array[j];
			j = j-1;
		}
		
		my_arr.array[j+1] = key;
	}
	
	return my_arr; // Return sorted array
}