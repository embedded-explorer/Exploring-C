
//----------------------------------------------------------------------
// Problem 1.
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "problems.h"

//--------------------------------------------------
// Function to initialize array
// @param  : int array size
// @return : App_List pointer
//--------------------------------------------------
App_List *initialise_array(int size){
    
    App_List *my_arr; // variable of type array list
    
	// Allocate memory for application list
    my_arr = (App_List *)malloc(sizeof(App_List));
    
	// Return NULL if memory allocation fails
    if(my_arr == NULL)
    	return NULL;

    my_arr->c_size = 0; // current size is made zero
    my_arr->t_size = size;
	// Allocate memory for array of applications
    my_arr->app_ptr = (Application *)malloc(sizeof(Application)*size);

    return my_arr;
}

//--------------------------------------------------
// Function to apply for course
// @param  : App_List pointer
// @param  : Application, applicant details
// @return : int Status
//--------------------------------------------------
int apply_for_course(App_List *my_arr, Application applicant){
	
	// Check whether App list has space
	if(my_arr->c_size == my_arr->t_size)
		return FAILURE; // Application list is full
    
	// Add applicant details to application list
	*(my_arr->app_ptr + my_arr->c_size) = applicant;
    (my_arr->app_ptr + my_arr->c_size)->is_admitted = 0; // Force to 0
	my_arr->c_size++;

	return SUCCESS; // Applicant added successfully
}

//--------------------------------------------------
// Function to allocate seats
// @param  : App_List pointer
// @return : void
//--------------------------------------------------
void allocate_seats(App_List *my_arr){
	int i, j;
	int min_rank_idx;
	int merit_count = 0;
	int nri_count = 0;
	int mgmt_count = 0;
	
	// Allocate seats in nri category
	for(i=0; i<my_arr->c_size; i++){
		// Check if category is nri
		if((my_arr->app_ptr + i)->category == nri){
			(my_arr->app_ptr + i)->is_admitted = 1;
			nri_count++;
			// Break when nri seats are full
			if(nri_count == NRI_SEATS)
				break;
		}
	}
	
	// Allocate seats in management category
	for(i=0; i<my_arr->c_size; i++){
		// Check if category is management
		if((my_arr->app_ptr + i)->category == management){
			(my_arr->app_ptr + i)->is_admitted = 1;
			mgmt_count++;
			// Break when management seats are full
			if(mgmt_count == MGMT_SEATS)
				break;
		}
	}
	
	// Allocate seats in merit category until they are filled
	while(merit_count < MERIT_SEATS){
		
		// Set first non admitted index as minimum index
		for(i=0; i<my_arr->c_size; i++){
			if(!(my_arr->app_ptr + i)->is_admitted){
				min_rank_idx = i;
				break;
			}
		}
		
		// Iterate through list to find least rank
		for(j=0; j<my_arr->c_size; j++){
			// Check if category is merit
		    if((my_arr->app_ptr + j)->category == merit){
				// If seat is not allocated
				if(!(my_arr->app_ptr + j)->is_admitted){
					// Find applicant with lowest rank
					if((my_arr->app_ptr + j)->rank < \
					   (my_arr->app_ptr + min_rank_idx)->rank){
						min_rank_idx = j;
					}
				}
			}
		}
		
		// Allocate seat
		(my_arr->app_ptr + min_rank_idx)->is_admitted = 1;
		merit_count++;
	}
}

//--------------------------------------------------
// Function to display application list
// @param  : App_List pointer
// @return : void
//--------------------------------------------------
void display_app_list(App_List *my_arr){
	char *category_name[] = {"merit", "management", "nri"};
	int i;
	
	// Display list of admitted applicants
	for(i=0; i<my_arr->c_size; i++){
		if((my_arr->app_ptr + i)->is_admitted)
		    printf("Rank : %2d\t Category : %10s\t Name : %s\n", \
		            (my_arr->app_ptr + i)->rank, \
			        category_name[(my_arr->app_ptr + i)->category], \
			        (my_arr->app_ptr + i)->name);
	}
}

//--------------------------------------------------
// Function to deallocate memory of application list
// @param  : App_List pointer
// @return : NULL Pointer
//--------------------------------------------------
App_List *deallocate(App_List *my_arr){
	free(my_arr->app_ptr);
	free(my_arr);
	
	return NULL;
}