#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "structures.h"

int main(){
/*
// Example for structure
    #define MAX_SIZE 5
    Student stud_data;
    Student stud[MAX_SIZE];

    stud_data = insert_student_data(1001, "Abhay", "Cyber Security", 8.8);

    assert(stud_data.reg_no == 1001);
    assert(strcmp(stud_data.student_name, "Abhay") == 0);

    display_student_info(stud_data);

    insert_student_details_in_array(stud, MAX_SIZE);
    display_student_info_array(stud, MAX_SIZE);
*/

/*
// Example for structure within structure
    Student stud[MAX_SIZE]; // Declare student array

    assert(insert_data(stud, MAX_SIZE) == 1);
    assert(stud[0].reg_no == 1001);
    assert(stud[1].reg_no == 1002);
    display(stud, MAX_SIZE);

    assert(search_reg_no(stud, MAX_SIZE,1001) == 1);
    assert(search_reg_no(stud,MAX_SIZE, 1004) == 0);

    assert(search_by_name(stud, MAX_SIZE, "XYZ") == 1);
    assert(search_by_name(stud, MAX_SIZE, "ABC") == 0);
*/


// Example for structure
    Pixel arr[MAX_SIZE];
    Pixel pix_1 = {255, 0, 0, 0.4, "Red", {3, 4}};
    Pixel pix_2 = {255, 0, 0, 0.4, "Red", {3, 4}};

    assert(insert_data(arr, MAX_SIZE) == MAX_SIZE);
    assert(search(arr, MAX_SIZE, 255) == 1);
    assert(search_pix_name(arr, MAX_SIZE, "Red") == 1);
    display(arr, MAX_SIZE);
    assert(compare_pixel(pix_1, pix_2)); // Passes if run independently

    return 0;
}
