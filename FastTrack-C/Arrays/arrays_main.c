#include <stdio.h>
#include <assert.h>
#include "arrays.h"

int main(){
/*
    // Find sum of elements of array
    #define SIZE 10
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    assert(sum_of_elements_array(arr, SIZE) == 55);
*/

/*
    // Find product of elements of array
    #define SIZE 10
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    assert(product_of_elements_array(arr, SIZE) == 3628800);
*/

/*
    // Reverse the given array
    #define SIZE 10
    int arr_1[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int reverse_arr_1[SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    reverse_array(arr_1, SIZE);
    for(int i=0; i<SIZE; i++){
        assert(arr_1[i] == reverse_arr_1[i]);
    }

    #ifdef SIZE
    #undef SIZE
    #define SIZE 7
    #endif
    int arr_2[SIZE] = {14, 35, 22, 47, 89, 64, 75};
    int reverse_arr_2[SIZE] = {75, 64, 89, 47, 22, 35, 14};
    reverse_array(arr_2, SIZE);
    for(int i=0; i<SIZE; i++){
        assert(arr_2[i] == reverse_arr_2[i]);
    }
*/

/*
    // Rotate the array towards right specified amount of times
    #define SIZE 5
    int arr[SIZE] = {1, 2, 3, 4, 5};
    print_int_array(arr, SIZE); // Display Before Rotating

    rotate_array(arr, SIZE, 2); // Rotate By 2
    print_int_array(arr, SIZE);
*/

/*
    // Find the number of occurrences of given element
    #define SIZE 8
    int arr[SIZE] = {2, 3, 4, 0, 3, 3, 5, 2};
    assert(frequency_of_element(arr, SIZE, 2) == 2);
    assert(frequency_of_element(arr, SIZE, 0) == 1);
*/

/*
    // Check if given element is present within array
    #define SIZE 12
    int arr[12] = {1,2,4,5,6,8,9,5,3,2,16,8};
    assert(search_array(arr, SIZE, 3) == 1);
    assert(search_array(arr, SIZE, 8) == 1);
    assert(search_array(arr, SIZE, 10) == 0);
    assert(search_array(arr, SIZE, 6) == 1);
*/

/*
    // Return index position of the element if found
    #define SIZE 12
    int arr[12] = {1,2,4,5,6,8,9,5,3,2,16,8};
    assert(return_index_of_element(arr, SIZE, 3) == 8);
    assert(return_index_of_element(arr, SIZE, 8) == 5);
    assert(return_index_of_element(arr, SIZE, 10) == -1);
    assert(return_index_of_element(arr, SIZE, 6) == 4);
*/

/*
    // Function to return maximum and minimum elements within array
    #define SIZE 12
    int arr[12] = {1,2,4,5,6,8,9,5,3,2,16,8};
    int max, min;
    assert(max_min_array(arr, SIZE, &max, &min)); // Returns 1 on Success
    assert(max == 16);
    assert(min == 1);
*/

    // Find Intersection of two arrays
    #define A_SIZE  8
    #define B_SIZE  10
    #define C_SIZE  10
    int arr_a[A_SIZE] = {1,2,4,4,2,5,4,1};
    int arr_b[B_SIZE] = {1,2,1,2,3,7,4,8,9,2};
    int arr_c[C_SIZE] = {0};
    int c_size;

    c_size = intersection_set(arr_a, A_SIZE, arr_b, B_SIZE, arr_c, C_SIZE);
    print_int_array(arr_a, A_SIZE);
    print_int_array(arr_b, B_SIZE);
    print_int_array(arr_c, c_size);

    return 0;
}
