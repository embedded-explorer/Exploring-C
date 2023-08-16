#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
        *(arr+i) =(int *) malloc(sizeof(int) * col);

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

// Function to initialize dynamic array of structure
Earray * initialize_employee(int size){
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
        return FAIL;

    if(my_arr->arr == NULL)
        return 0;

    for(i=0; i<my_arr->c_size; i++){
        if(strcmp((my_arr->arr + i)->emp_name, element) == 0)
            return 1;
    }

    return 0;
}

// Dynamic Array List Merge
// Initialize structure array
Array * initialize_array(int size){
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

/*


Array * deallocate(Array *my_arr)
{
    free(my_arr->arr);
    free(my_arr);

    return NULL;
}


int search(Array *my_arr, int element)
{
    int i;

    if(my_arr == NULL) return FAIL;
    if(my_arr->arr == NULL) return FAIL;

    for(i=0; i<my_arr->c_size; i++)
    {
        if(*(my_arr->arr + i) == element) return FOUND;
    }

    return FAIL;
}

//Assumption : Both array A and B have elements
Array * merge_array(Array *arr_a, Array *arr_b)
{
    int updated_c_size_a, i, j;

    if(arr_a == NULL) return arr_b; // arrays does not exist

    if(arr_b == NULL) return arr_b;

    updated_c_size_a = arr_a->c_size + arr_b->c_size;

    if(updated_c_size_a > arr_a->t_size) {
        arr_a->arr = realloc(arr_a->arr, (updated_c_size_a) * sizeof(int));
        arr_a->t_size = updated_c_size_a;
    }

    for(i=0; i < arr_b->c_size; i++)
        assert(insert_data(arr_a, *(arr_b->arr + i)) == SUCCESS);

    arr_b = deallocate(arr_b);


    return arr_b;
}

// Pointers
#include<stdlib.h>
#include<stdio.h>
#include "pointer.h"

int * insert_dynamic_array(int size)
{
    int *arr, i;
    arr = (int *)malloc(sizeof(int) * size);

    for(i=0; i<size; i++)
        *(arr+i) = i+1;

    return arr;
}
Maxmin max_min(int *arr, int size,Maxmin res)
{
    int i;
    res.max = res.min = *arr;

    for(i=1; i<size; i++)
    {
        if(res.max < *(arr+i)) res.max = *(arr+i);
        if(res.min > *(arr+i)) res.min = *(arr+i);
    }
    return res;
}

int * create_two_dimension_single_ptr(int row, int col)
{
    int *arr, i, j;

    arr = (int *)malloc(sizeof(int) * row *col);

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            *(arr+(i*col)+j) = i+j;
        }
    }
    return arr;
}

void display(int *arr, int row, int col)
{
       int i, j;

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%d ",*(arr+(i*col)+j));
        }
        printf("\n");
    }

}


int ** create_two_dimension_double_ptr(int row, int col)
{
    int **arr, i;

    arr = (int **)malloc(sizeof(int *) * row);

    for(i=0; i<row;i++)
        *(arr+i) = (int *) malloc(sizeof(int) * col);

    return arr;

}

int ** insert_two_dimension_array(int row, int col)
{
    int **arr;
    int i, j;

    arr = create_two_dimension_double_ptr(row, col);

    for(i=0; i<row;i++)
        for(j=0;j<col;j++)
            *(*(arr+i) +j) = i+j;

    return arr;
}

void display_two_dimension(int **arr, int row, int col)
{
    int i, j;

    for(i=0; i<row;i++){
        for(j=0;j<col;j++){
            printf("%d ",*(*(arr+i) +j));
        }
        printf("\n");
    }
}
*/
