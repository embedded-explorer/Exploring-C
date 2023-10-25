//----------------------------------------------------------------------
// Sorting
//----------------------------------------------------------------------
#include <stdio.h>
#include "sorting.h"

// Function to print array
void print_array(int arr[], int arr_size){
    for(int i=0; i<arr_size; i++){
        printf("%d ", arr[i]);
    }
}

// Bubble Sort
void bubble_sort(int arr[], int arr_size){
    int temp;
	int i, j;

    for(i=0; i<arr_size; i++){
        for(j=0; j<(arr_size-i-1); j++){
            if(arr[j] > arr[j+1]){
			// If element is greater than next element then swap
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Selection Sort
void selection_sort(int arr[], int arr_size){
	int idx_of_min, temp;
	int i, j;
	
	for(i=0; i<arr_size; i++){
		
		// Finding Minimum Element Index
		idx_of_min = i;
		for(j=i; j<arr_size; j++){
			if(arr[idx_of_min] > arr[j]){
			// If minimum element is present
			    idx_of_min = j;
			}
		}
		
		// Swap Element at Index with minimum element
		temp = arr[i];
		arr[i] = arr[idx_of_min];
		arr[idx_of_min] = temp;
	}
}

// Insertion Sort
void insertion_sort(int arr[], int arr_size){
	int i, j;
	int key;
	
	for(i=1; i<arr_size; i++){
		key = arr[i]; // Select Key Element
		
		// Shift sorted list to make space for key element
		for(j=i-1; (j>=0)&&(arr[j]>key); j--){
			arr[j+1] = arr[j];
		}
		// Insert key element in proper position in sorted list
		arr[j+1] = key;
	}
}

// Merge Sort
void merge(int arr[], int low, int mid, int high){
	int i; // Index for left list
	int j; // Index for right list
	int k; // Index for empty list
	
	int temp[high+1]; // Temporary Array
	
	i = low;
	j = mid + 1;
	k = low;
	
	// Copy elements until one of list gets empty
	while((i <= mid) && (j <= high)){
		if(arr[i] <= arr[j]){
		// If left is smaller copy left element
			temp[k++] = arr[i++];
		}
		else{
		// If right is smaller copy right element
			temp[k++] = arr[j++];
		}
	}
	
	if(i > mid){
	// All elements from left are copied, copy from right
	    while(j <= high){
		    temp[k++] = arr[j++];
		}
	}
	else{
	// If remaining in left, copy from left
		while(i <= mid){
			temp[k++] = arr[i++];
		}
	}
	
	// Copy elements from new list to original list
	for(k=low; k<=high; k++){
		arr[k] = temp[k];
	}
}

void merge_sort(int arr[], int low, int high){
	int mid;

	// Iteratively call merge_sort
	if(low < high){
		mid = (low + high)/2;
		merge_sort(arr, low, mid);
		merge_sort(arr, mid+1, high);
		merge(arr, low, mid, high);
	}
}

// Quick Sort
int partition(int arr[], int low, int high){
	int i, j;
	int pivot;
	int temp;
	
	i = low;
	j = high;
	pivot = arr[low]; // Select first element as pivot
	
	while(i < j){
		do{
			i++;
		// Increment i until element greater than pivot is found
		}while(arr[i] <= pivot);
		
		while(arr[j] > pivot){
		// Decrement j until element lesser than pivot is found
			j--;
		}
		
		// Swap elements
		if(i < j){
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		
	}
	
	// Insert pivot at proper position by swapping
	temp = arr[low];
	arr[low] = arr[j];
	arr[j] = temp;

	return j; // Return index of pivot
}

void quick_sort(int arr[], int low, int high){
	int pivot_idx;
	
	if(low < high){
		pivot_idx = partition(arr, low, high);
		quick_sort(arr, low, pivot_idx-1);
		quick_sort(arr, pivot_idx+1, high);
	}
}

// Heap Sort
void heapify(int arr[], int root, int size){
	int j;
	int temp;
	j = 2*root+1; // Left Child
	
	while(j < size){
	// If left child is present
		if(j+1 < size){
		// If right child is present
		    if(arr[j+1] > arr[j]){
			// If right child is greater than left child
			    j++; // Swap right child with root
			}
		}
		
		if(arr[root] >= arr[j]){
		// If root is greater than child
		    return; // Already max heap
		}
		
		// Swap parent with greater child
		temp = arr[root];
		arr[root] = arr[j];
		arr[j] = temp;

	    root = j; // Move the root
		j = 2*root+1; // Move the left child
	}
}

void build_heap(int arr[], int size){
	int i;
	// beyond size/2-1 are leaf nodes which are max heap themselves
	// call heapify to create max heap from leaf-1 level to root
	for(i=size/2-1; i>=0; i--)
		heapify(arr, i, size);
}

void heap_sort(int arr[], int size){
	int temp;
	
	// Convert given array into max heap
	build_heap(arr, size);
	
	// Delete node if heap size is greater than 1
	while(size > 1){
		// Delete root and swap with last element in heap
		temp = arr[size];
		arr[size] = arr[0];
		arr[0] = temp;
		
		// Rearrange the max heap
		heapify(arr, 0, size-1);
		size--;
	}
}