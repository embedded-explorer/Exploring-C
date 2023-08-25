#include <stdio.h>
#include <stdlib.h>

// Function to print integer array
int print_int_array(int arr[], int arr_size){
    for(int i=0; i<arr_size; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
    return 1; // Operation Successful
}

// Find sum of elements of array
int sum_of_elements_array(int arr[], int arr_size){
    int i, sum=0;

    if(arr_size == 0) return 0;

    for(i=0; i<arr_size; i++){
        sum += arr[i];
    }

    return sum;
}

// Find product of elements of array
int product_of_elements_array(int arr[], int arr_size){
    int i, product=arr[0];

    if(arr_size == 0) return 0;

    for(i=1; i<arr_size; i++){
        product *= arr[i];
    }

    return product;
}

// Reverse the given array
// Input -> arr[] = {1,2,3,4,5,6,6}
// Output-> arr[] = {6,6,5,4,3,2,1}
int reverse_array(int arr[], int arr_size){
    int i, j, temp;

    if(arr_size == 0) return 0;

    for(i=0, j=arr_size-1; i < j; i++, j--){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    return 1; // On Successful Reversal
}

// Rotate the array towards right specified amount of times
// Input arr[] = {1,2,3,4,5}
// Output Shift 1 Time = {5,1,2,3,4}
// Output Shift 2 Time = {4,5,1,2,3}
// Output Shift 3 Time = {3,4,5,1,2}
// Output Shift 4 Time = {2,3,4,5,1}
// Output Shift 5 Time = {1,2,3,4,5}
int rotate_array(int arr[], int arr_size, int shift_amount){
    int i, j, temp;

    if(shift_amount > arr_size) return 0;

    for(i=0; i<shift_amount; i++){
        temp = arr[arr_size-1]; // Store Last Element Before Shifting Right
        for(j = arr_size - 2; j >= 0; j--){
            arr[j+1] = arr[j];
        }
        arr[0] = temp;
    }

    return 1; // Shift Successful
}

// Find the number of occurrences of given element
int frequency_of_element(int arr[], int arr_size, int element){
    int count=0;
    for(int i=0; i<arr_size; i++){
        if(arr[i] == element)
            count ++;
    }
    return count;
}

// Check if given element is present within array
int search_array(int arr[], int arr_size, int element){
    for(int i=0; i<arr_size; i++){
        if(arr[i] == element)
            return 1; // Element Found
    }
    return 0; // Element Not Found
}

// Return index position of the element if found
int return_index_of_element(int arr[], int arr_size, int element){
    for(int i=0; i<arr_size; i++){
        if(arr[i] == element)
            return i; // Index of element
    }

    return -1; // Element Not Found
}

// Function to return maximum and minimum elements within array
int max_min_array(int arr[], int arr_size,int *max, int *min){

    if(arr_size == 0) return 0; // Array is empty

    // First Element is considered as max and min initially
    *max = *min = arr[0];

    for(int i=1; i<arr_size; i++){
        if(*max < arr[i])
        // Max element is less than indexed element chose new max element
            *max = arr[i];
        if(*min > arr[i])
        // Min element is greater than indexed element chose new min element
            *min = arr[i];
    }

    return 1; // Return Success
}

// Find Intersection of two arrays
// For example:
// A[] = {1,2,3,4,2,5,4,1}
// B[] = {1,2,1,2,3,7,4,8,9,2}
// C[] = {1,2,3,4}

// Direct Implementation
int intersection_array(int arr_a[], int size_a, int arr_b[], int size_b, int arr_c[], int size_c){
    int count=0;
    int already_added = 0;

    for(int i=0; i< size_a; i++){
    // For each element in array A
        for(int j=0; j< size_b; j++){
        // Check if element exists in array B
            if(arr_a[i] == arr_b[j]){
            // If element exists in array B
                already_added = 0;
                for(int k=0; k< count; k++){
                // check if its already added to array C
                    if(arr_a[i] == arr_c[k]){
                    // Flag is made high and skip addition
                        already_added = 1;
                        break;
                    }
                }
                if(!already_added){
                    arr_c[count++] = arr_a[i];
                }
            }
        }
    }
    return count; // Return size of array c
}

// Implementation by reusing search function
int intersection_set(int arr_a[], int size_a, int arr_b[], int size_b, int arr_c[], int size_c){
    int i=0, count=0;

    for(i=0; i< size_a; i++){
    // Iterate through each element of array A
        if(search_array(arr_b, size_b, arr_a[i]) && (!search_array(arr_c, size_c, arr_a[i]))){
        // If that element is found in array B and not found in array C add that to array C
            arr_c[count++] = arr_a[i];
        }
    }
    return count; // Return size of array c
}

// Insert data in to 2D Array
void insert_data(int row, int col, int arr[row][col]){
    int i, j;

    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            arr[i][j] = rand()%50;
        }
    }
}

// Print data of 2D Array
void display_data(int row, int col, int arr[row][col]){
    int i, j;

    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            printf(" %d ",arr[i][j]);
        }
        printf("\n");
    }
}

// Get Maximum Column sum of 2D Array
int return_max_sum_col(int row, int col, int arr[row][col], int *max){
    int i, j, sum, col_no;
    *max = -1;

    if(row <= 0 || col <=0)
        return -1; // Operation Unsuccessful

    for(i=0; i<row; i++){
        sum = 0;
        for(j=0; j<col; j++){
            sum += arr[j][i];
        }

        if(*max < sum){
            *max = sum;
            col_no = i;
        }
    }
    return col_no;
}
