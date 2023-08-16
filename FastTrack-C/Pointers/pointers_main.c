#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "pointers.h"

int main(){
/*
// Create a dynamic array and insert elements into it, return the array address
    int *test_arr;
    test_arr = insert_in_dynamic_array(10);
    assert(*(test_arr) == 1);
    assert(*(test_arr+4) == 5);
    assert(*(test_arr+9) == 10);
*/

/*
// Create a dynamic 2D array and insert elements into it, return the array address
    int *test_arr;
    test_arr = insert_in_two_dimesion_array(4,5);
    assert(*(test_arr) == 0);   // First row first column
    assert(*(test_arr+4) == 4); // First row last column
    assert(*(test_arr+5) == 1); // second row first column
    display(test_arr, 4, 5);
*/

/*
// create a dynamic 2D array, return double pointer storing array address
    int **test_arr;
    test_arr = insert_double_pointer(4,5);
    display_double_ptr(test_arr, 4, 5);
    printf("\n\nDouble Pointer, Base Address of Row Pointer List:\t%p", test_arr);
    printf("\nList of Row Pointers:\t");
    for(int i=0; i<4; i++){
        printf("%p\t", *test_arr+i);
    }
    printf("\n1st Row:\t");
    for(int i=0; i<5; i++){
        printf("%d\t", (*(*test_arr+0)+i));
    }
    printf("\n2nd Row:\t");
    for(int i=0; i<5; i++){
        printf("%d\t", (*(*test_arr+1)+i));
    }
    printf("\n3rd Row:\t");
    for(int i=0; i<5; i++){
        printf("%d\t", (*(*test_arr+2)+i));
    }
    printf("\n4th Row:\t");
    for(int i=0; i<5; i++){
        printf("%d\t", (*(*test_arr+3)+i));
    }
*/

    Earray *test;
    Employee data = {1001, "Joel", 30000};
    test = initialize_employee(5);
    assert(insert_employee_data(test, data));
    assert(test->arr->emp_id == 1001);

    data.emp_id = 1002;
    data.emp_salary = 25000;
    strcpy(data.emp_name, "Siya");
    assert(insert_employee_data(test, data));
    assert((test->arr + 1)->emp_id == 1002);
    assert(search_by_name(test, "Siyan") == 0);

    return 0;
}

/*
#include<assert.h>
#include<stdlib.h>

#include "array.h"

void test_merge_array();

int main()
{
    Array *test_ptr, *arr_one, *arr_two;

    test_ptr = initialize_array(5);
    arr_one = initialize_array(10);
    arr_two = initialize_array(15);

    assert(test_ptr != NULL);
    assert(test_ptr->c_size == 0 && test_ptr->t_size == 5);
    assert(test_ptr->arr != NULL);

    assert(insert_data(test_ptr, 10) == SUCCESS);
    assert(insert_data(test_ptr, 30) == SUCCESS);
    assert(insert_data(test_ptr, 40) == SUCCESS);
    assert(insert_data(test_ptr, 20) == SUCCESS);
    assert(insert_data(test_ptr, 60) == SUCCESS);

    assert(test_ptr->c_size == 5);
    assert(insert_data(test_ptr, 100) == FULL);

    assert(search(test_ptr, 60) == FOUND);
    assert(search(test_ptr, 20) == FOUND);
    assert(search(test_ptr, 40) == FOUND);

    assert(search(test_ptr, 100) == FAIL);

    test_ptr = deallocate(test_ptr);
    assert(test_ptr == NULL);


    //testing for merge array
    test_merge_array();

    return 0;
}


void test_merge_array()
{
    Array *arr_one, *arr_two;

    arr_one = initialize_array(10);
    arr_two = initialize_array(15);

    assert(insert_data(arr_one, 10));
    assert(insert_data(arr_one, 30));
    assert(insert_data(arr_one, 20));
    assert(insert_data(arr_one, 50));
    assert(insert_data(arr_one, 20));
    assert(insert_data(arr_one, 60));
    assert(insert_data(arr_one, 10));

    assert(arr_one->c_size == 7);


    assert(insert_data(arr_two, 90));
    assert(insert_data(arr_two, 90));
    assert(insert_data(arr_two, 90));
    assert(insert_data(arr_two, 90));
    assert(insert_data(arr_two, 30));
    assert(insert_data(arr_two, 90));
    assert(insert_data(arr_two, 50));
    assert(insert_data(arr_two, 90));
    assert(insert_data(arr_two, 10));
    assert(insert_data(arr_two, 80));

    assert(arr_two->c_size == 10);

    arr_two = merge_array(arr_one, arr_two);

    assert(arr_one->c_size == 17);
    assert(arr_one->t_size == 17);
    assert(arr_two == NULL);

    deallocate(arr_one);


}

#include <assert.h>
#include <stdlib.h>
#include "pointer.h"

int main()
{
    int *test, *dummy, **arr;
    Maxmin res;

    test = insert_dynamic_array(10);
    dummy = insert_dynamic_array(20);

    assert(*(test+7) == 8);
    res = max_min(test, 10, res);

    assert(res.max == 10);
    assert(res.min == 1);

    test = create_two_dimension_single_ptr(4,5);
    display(test,4,5);

    arr = insert_two_dimension_array(4,6);
    display_two_dimension(arr, 4,6);

    return 0;
}

*/
