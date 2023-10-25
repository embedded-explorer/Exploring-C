//----------------------------------------------------------------------
// Sorting
//----------------------------------------------------------------------
#include <assert.h>
#include <stdio.h>
#include "sorting.h"

int main(){
	
	/*
	#define SIZE 5
    int arr[SIZE] = {64, 25, 12, 22, 11};
	// Bubble Sort
	printf("\nBefore Sorting:");
	print_array(arr, SIZE);
	bubble_sort(arr, SIZE);
	printf("\nAfter Sorting:");
	print_array(arr, SIZE);
	*/
	
	/*
	#define SIZE 5
    int arr[SIZE] = {64, 25, 12, 22, 11};
	// Selection Sort
	printf("\nBefore Sorting:");
	print_array(arr, SIZE);
	selection_sort(arr, SIZE);
	printf("\nAfter Sorting:");
	print_array(arr, SIZE);
	*/
	
	/*
	#define SIZE 5
    int arr[SIZE] = {64, 25, 12, 22, 11};
	// Insertion Sort
	printf("\nBefore Sorting:");
	print_array(arr, SIZE);
	insertion_sort(arr, SIZE);
	printf("\nAfter Sorting:");
	print_array(arr, SIZE);
	*/
	
	/*
	#define SIZE 8
    int arr[SIZE] = {38, 27, 43, 98, 3, 9, 82, 10};
	// Merge Sort
	printf("\nBefore Sorting:");
	print_array(arr, SIZE);
	merge_sort(arr, 0, SIZE-1);
	printf("\nAfter Sorting:");
	print_array(arr, SIZE);
	*/
	
	/*
	#define SIZE 8
    int arr[SIZE] = {10, 16, 8, 12, 15, 6, 3, 9};
	// Quick Sort
	printf("\nBefore Sorting:");
	print_array(arr, SIZE);
	quick_sort(arr, 0, SIZE-1);
	printf("\nAfter Sorting:");
	print_array(arr, SIZE);
	*/
	
	#define SIZE 7
    int arr[SIZE] = {10, 16, 8, 12, 15, 6, 3};
	// Heap Sort
	printf("\nBefore Sorting:");
	print_array(arr, SIZE);
	heap_sort(arr, SIZE-1);
	printf("\nAfter Sorting:");
	print_array(arr, SIZE);
	
	return 0;
}