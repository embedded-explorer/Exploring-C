#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "pointers.h"

// Create a dynamic array and insert elements into it, return the array address
int * insert_in_dynamic_array(int size){
    int *arr, i;

    arr = (int *)malloc(sizeof(int) * size);

    for(i=0; i<size;i++)
        *(arr+i) = i+1;

    return arr;
}

// Create a dynamic 2D array and insert elements into it, return the array address
int *insert_in_two_dimesion_array(int row, int col){
    int *arr, i, j;

    arr = (int *)malloc(sizeof(int) * row * col);

    for(i=0; i<row; i++)
        for(j=0; j<col; j++)
            *(arr+(i*col) + j) = i+j;

    return arr;
}

void display(int *arr, int row, int col){
    int i, j;

    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            printf("%d ", *(arr+(i*col) + j));
        }
        printf("\n");
    }
}

// create a dynamic 2D array, return double pointer storing array address
// Create 2D array using double pointer
int ** create_matrix(int row, int col){
    int **arr, i;

    // Allocate memory for an array of row pointers
    arr = (int **)malloc(sizeof(int *) * row);

    // Allocate memory for each row
    for(i=0; i<row; i++)
        *(arr+i) = (int *)malloc(sizeof(int) * col);

    // Return the double pointer to the matrix
    return arr;
}

int ** insert_double_pointer(int row, int col){
    int **arr, i, j;

    // Create 2D array and store the double pointer
    arr = create_matrix(row, col);

    for(i=0; i<row; i++)
        for(j=0; j<col; j++)
            *(*(arr+i)+j) = i+j;

    return arr;
}

// Function to display dynamic 2D array using double pointers
void display_double_ptr(int **arr, int row, int col){
    int i,j;

    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
          printf("%d ", *(*(arr+i)+j));
        }
        printf("\n");
    }
}

/*
// Function to initialize dynamic array of structure
Earray *initialize_employee(int size){
    Earray *my_arr;

    my_arr = (Earray *)malloc(sizeof(Earray));

    if(NULL == my_arr)
        return NULL; // memory allocation FAILED

    (*my_arr).c_size = 0;
    my_arr->t_size = size;
    my_arr->arr = (Employee *)malloc(sizeof(Employee) * size);

    return my_arr;
}

// Function to insert employee data into employee array
int insert_employee_data(Earray *my_arr, Employee data){
    if(my_arr->c_size == my_arr->t_size)
        return -1; // Array is full

    // Use pointer arithmetic to index the array
    *(my_arr->arr + my_arr->c_size) = data;
    my_arr->c_size++;

    return 1; // Return insertion success
}

// Function to search employee by name
int search_by_name(Earray *my_arr, char *element){
    int i;

    if(my_arr == NULL)
        return 0;

    if(my_arr->arr == NULL)
        return 0;

    for(i=0; i<my_arr->c_size; i++){
        if(strcmp((my_arr->arr + i)->emp_name, element) == 0)
            return 1;
    }

    return 0;
}
*/


// Dynamic Array List Merge
// Initialize structure array
Array *initialize_array(int size){
    Array *my_arr;

    // Dynamically allocate memory for structure array
    my_arr = (Array *)malloc(sizeof(Array));

    if(NULL == my_arr)
        return NULL; // memory allocation Failure

    my_arr->c_size = 0;
    my_arr->t_size = size;
    // Dynamically allocate memory for array within structure array
    my_arr->arr = (int *)malloc(sizeof(int) * size);

    return my_arr;
}

// Insert data into array within structure array
int insert_data(Array *my_arr, int data){
    if(my_arr->c_size == my_arr->t_size)
        return FAILURE; // Insertion Failure

    *(my_arr->arr + my_arr->c_size) = data;
    my_arr->c_size++;

    return SUCCESS; // Insertion Success
}

// Search element within array
int search(Array *my_arr, int element){
    int i;

    if(my_arr == NULL)
		return FAILURE; // Check if pointer has address
	
    if(my_arr->arr == NULL)
		return FAILURE; // Check if pointer has address

    for(i=0; i<my_arr->c_size; i++){
        if(*(my_arr->arr + i) == element)
			return SUCCESS;
    }

    return FAILURE;
}

// Deallocate memory allocated for array
Array *deallocate(Array *my_arr){
    free(my_arr->arr);
    free(my_arr);

    return NULL;
}

// Merage arrays
// Assumption : Both array A and B have elements
// Merge array b with array a and deallocate array b and return NULL
Array *merge_array(Array *arr_a, Array *arr_b){
    int updated_c_size_a, i;
    
	// if array a does not exist
    if(arr_a == NULL)
		return arr_b; // return array b
    
	// if array b does not exist
    if(arr_b == NULL) 
		return arr_a; // return array a

    updated_c_size_a = arr_a->c_size + arr_b->c_size;

    if(updated_c_size_a > arr_a->t_size){
        arr_a->arr = realloc(arr_a->arr, (updated_c_size_a) * sizeof(int));
        arr_a->t_size = updated_c_size_a;
    }

    for(i=0; i< arr_b->c_size; i++)
        assert(insert_data(arr_a, *(arr_b->arr + i)) == SUCCESS);
    
	// Deallocate array b
    arr_b = deallocate(arr_b);

    return arr_b;
}

// Split array
Array *split_array(Array *my_arr, int split_index){
	Array *new_array;
	int new_t_size;
    
	// Return NULL if input array is not present
	if(my_arr == NULL)
		return NULL;
	
	// Return NULL if requested split index is greater than c_size
	if(split_index >= my_arr->c_size)
		return NULL;
		
	// allocate memory for new array
	new_t_size = my_arr->c_size - split_index;
	new_array = initialize_array(new_t_size);
	
	// copy elements of array to new array
	// Instead of copyig elements copy address of indexed element
	new_array->arr = my_arr->arr + split_index;
	new_array->c_size = new_t_size;
	my_arr->c_size = split_index;
	
	return new_array;
}