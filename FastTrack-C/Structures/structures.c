#include <string.h>
#include <stdio.h>
#include "structures.h"

/*
// Example for structure
// Function to insert student data
Student insert_student_data(int reg_no, char stud_name[], char course_name[], float cgpa){
    Student stud; // local variable of type student

    stud.reg_no = reg_no;
    // stud.student_name = stud_name; // String cannot be directly copied
    strcpy(stud.student_name, stud_name);
    strcpy(stud.course_name, course_name);
    stud.cgpa = cgpa;

    return stud; // return student variable
}

// Function to display student information
void display_student_info(Student stud){
    printf(" \
           Registration Number : %d \n \
           Student Name        : %s \n \
           Course Name         : %s \n \
           CGPA                : %0.2f\n ", \
           stud.reg_no, stud.student_name, stud.course_name, stud.cgpa);
}

// Function to insert student data into student information array
void insert_student_details_in_array(Student stud[], int size ){
    int i;
    for(i=0; i< size; i++){
        stud[i].reg_no = 10001;
        strcpy(stud[i].student_name, "Anonymous");
        strcpy(stud[i].course_name, "MSIS");
        stud[i].cgpa = 9.1;
    }
}

// Function to display student information array
void display_student_info_array(Student stud[], int size){
    int i;
    for(i=0; i< size; i++){
        printf(" \
               Registration Number : %d \n \
               Student Name        : %s \n \
               Course Name         : %s \n \
               CGPA                : %0.2f\n ", \
               stud[i].reg_no, stud[i].student_name,stud[i].course_name, stud[i].cgpa);
    }
}
*/

/*
// Example for structure within structure
// Function to insert student data into student information array
int insert_data(Student stud[], int size){
    int i;

    for(i=0; i<size; i++){
        if(i%2 == 0){
            stud[i].reg_no = 1001;
            strcpy(stud[i].name, "XYZ");
            strcpy(stud[i].course, "ABC");
            stud[i].first_internals.mark1 = 99;
            stud[i].first_internals.mark2 = 95;
            stud[i].first_internals.mark3 = 79;
            stud[i].second_internals.mark1 = 80;
            stud[i].second_internals.mark2 = 90;
            stud[i].second_internals.mark3 = 95;
            stud[i].cgpa = 9.1;
        }
        else{
            stud[i].reg_no = 1002;
            strcpy(stud[i].name, "Jai");
            strcpy(stud[i].course, "VLSI");
            stud[i].first_internals.mark1 = 100;
            stud[i].first_internals.mark2 = 99;
            stud[i].first_internals.mark3 = 79;
            stud[i].second_internals.mark1 = 89;
            stud[i].second_internals.mark2 = 97;
            stud[i].second_internals.mark3 = 94;
            stud[i].cgpa = 9.2;
        }
    }
    return 1; // Return success
}

// Function to search for given register number within student information array
int search_reg_no(Student stud[], int size, int reg_no){
    int i;

    for(i=0; i<size;i++){
        if(stud[i].reg_no == reg_no)
            return 1; // Return success
    }
    return 0; // Return Failure
}

// Function to search for given name within student information array
int search_by_name(Student stud[], int size, char name[]){
    int i;

    for(i=0; i<size;i++){
        if(strcmp(stud[i].name, name) == 0)
            return 1; // Return success
    }
    return 0; // Return Failure
}

// Function to display student information array
void display(Student stud[], int size){
    int i;
    for(i=0;i<size;i++)
        printf("\n Reg No: %d, Name: %s, First Internal mark1: %f", \
               stud[i].reg_no, stud[i].name, stud[i].first_internals.mark1);
}
*/


// Example application for structure
// Insert data into pixel array
int insert_data(Pixel pixel[], int size){
    int i;

    for(i=0; i<size; i++){
        printf("Enter the Record: %d\n", i+1);
        scanf("%d %d %d %f %s %d %d",\
              &pixel[i].r, &pixel[i].g, &pixel[i].b,\
              &pixel[i].opacity, pixel[i].pixel_color, &pixel[i].pnt.x, &pixel[i].pnt.y);
    }
    return i;
}

// Search for given R value within pixel array
int search(Pixel pixel[], int size, int r_value){
    int i;

    for(i=0; i < size; i++){
        if(pixel[i].r == r_value)
            return 1;
    }
    return 0;
}

// Search for given color within pixel array
int search_pix_name(Pixel pixel[], int size, char pix_name[]){
    int i;

    for(i=0; i < size;i++){
        if(strcmp(pix_name, pixel[i].pixel_color) == 0)
            return 1;
    }
    return 0;
}

// Display the pixel array
void display(Pixel pixel[], int size){
    int i;

    for(i=0; i<MAX_SIZE; i++){
        printf("\n %d %d %d %f %s %d %d ",\
              pixel[i].r, pixel[i].g, pixel[i].b,\
              pixel[i].opacity, pixel[i].pixel_color, pixel[i].pnt.x, pixel[i].pnt.y);
    }
}

// Compare two pixels
int compare_pixel(Pixel pixel_1, Pixel pixel_2){

    if(!memcmp(&pixel_1, &pixel_2, sizeof(Pixel)))
        return 1;
    return 0;

}
