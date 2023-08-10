#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "practice_problems.h"

int main(){
/*
// 1.
    // printf("A = %d, Z = %d, a = %d, z = %d", 'A', 'Z', 'a', 'z');
    assert(upper_to_lower('A') == 'a'); // Assertion passes
    // assert(upper_to_lower('B') == 'a'); // Assertion fails
    assert(upper_to_lower('1') == '!'); // Assertion Returns !
    assert(upper_to_lower('Z') == 'z');
    assert(upper_to_lower('H') == 'h');
*/

/*
// 2.
    printf("Returned Value = %f, Calculated Value = %f\n", area_of_circle(5.2), 3.14*5.2*5.2);
    // Assertion will work fine only with int and char types
    assert(area_of_circle(5.2) == 3.14*5.2*5.2); // Precision causes problem
*/

/*
// 3.
    printf("%d", char_between_char('A', 'E'));
    assert(char_between_char('Z', 'A') == 24);
    assert(char_between_char('h', 'o') == 6);
*/

/*
// 4.
    printf("Returned Value = %f, Calculated Value = %f\n", celsius_to_fahrenheit(38.0), (38.0 * 1.8 + 32));
    assert(celsius_to_fahrenheit(38.0) == (38.0 * 1.8 + 32)); // Precision causes problem
*/

/*
// 5.
    assert(odd_or_even(37) == 1); // Number is odd
    assert(odd_or_even(24) == 0); // Number is even
    printf("Returned Value = %d, Calculated Value = %d\n", odd_or_even(-5), 1);
    assert(odd_or_even(-5) == 1); // Returns -1, needs to be fixed
    assert(odd_or_even(24) == 1); // Number is even assertion fails
*/

/*
// 6.
    assert(check_leap_year(2020) == 1); // Is a leap year
    assert(check_leap_year(2000) == 1); // Is a leap year
    assert(check_leap_year(1900) == 0); // Not a leap year
    assert(check_leap_year(2022) == 0); // Not a leap year
*/

/*
// 7.
    assert(pow_of_2(5) == 32);
    assert(pow_of_2(10) == 1024);
    assert(pow_of_2(1) == 2);
    assert(pow_of_2(0) == 1);
*/

/*
// 8.
    assert(char_or_int('5') == 1); // Integer
    assert(char_or_int('*') == -1); // Integer
    assert(char_or_int('M') == 0); // Integer
    assert(char_or_int('g') == 0); // Integer
*/

/*
// 9.
    unsigned int sum = 0;
    unsigned int x = rand();
    unsigned int y = rand();
    sum = x + y;
    assert(add_rand(x, y) == sum);
*/

/*
// 10.
    assert(sum_of_digits(12345) == 15);
    assert(sum_of_digits(752904) == 27);
    assert(sum_of_digits(3) == 3);
*/

/*
// 11.
    assert(reverse_of_num(5) == 5);
    assert(reverse_of_num(57903) == 30975);
    assert(reverse_of_num(500) == 005);
*/

/*
// 12.
    assert(count_digit(123212, 2) == 3);
    assert(count_digit(1, 1) == 1);
    assert(count_digit(3000007, 0) == 5);
*/

/*
// 13.
    assert(check_palindrome(12321) == 1);
    assert(check_palindrome(56788765) == 1);
    assert(check_palindrome(12322) == 0);
*/

/*
// 14.
    assert(is_prime(7) == 1);
    assert(is_prime(27) == 0);
    assert(is_prime(2) == 1);

    unsigned int num;
    unsigned int i, count=1;

    printf("Enter the Number of Prime Numbers Required: ");
    scanf("%d", &num);

    for(i=2; count <= num; i++){
        if(is_prime(i)){
            printf("%d\t", i);
            count++;
        }
    }
*/

/*
// 15.
    unsigned int num;
    printf("Enter the Number of Elements Required: ");
    scanf("%d", &num);
    sum_of_series(num);
*/

/*
// 16.
    assert(check_if_armstrong(153) == 1);
    assert(check_if_armstrong(25) == 0);
*/

/*
// 17.
    assert(check_if_amicable(220, 284) == 1);
    assert(check_if_amicable(284, 220) == 1);
    assert(check_if_amicable(10, 15) == 0);
*/

/*
// 18.
    assert(menu_driven_calculator(7, 3, '+') == 10);
    assert(menu_driven_calculator(7, 3, '-') == 4);
    assert(menu_driven_calculator(7, 3, '*') == 21);
    assert(menu_driven_calculator(17, 3, 't') == -1);
*/

/*
// 19.
    main_menu();
*/

/*
// 20.
    float units;
    printf("Enter Electricity Consumed in Units: ");
    scanf("%f", &units);
    printf("Electricity Bill in Rupees: %.2f", electricity_bill(units));
*/

/*
// 21.
    // Binary to Decimal Conversion
    assert(bin_2_dec(1011) == 11);
    assert(bin_2_dec(10110010) == 178);
    assert(bin_2_dec(1111) == 15);
    assert(bin_2_dec(00) == 0);
    assert(bin_2_dec(1) == 1);

    // Decimal to Binary Conversion
    assert(dec_2_bin(5) == 101);
    assert(dec_2_bin(0) == 0);
    assert(dec_2_bin(1) == 1);
    assert(dec_2_bin(11) == 1011);
    assert(dec_2_bin(47) == 101111);
*/

/*
// 22.
    #define SIZE 100
    int num;
    int arr[SIZE] = {0, 0, 1};
    printf("Enter the Number of Elements Required: ");
    scanf("%d", &num);
    generate_series(arr, num);
    for(int i=0; i<num; i++){
        printf("%d ", arr[i]);
    }
*/

/*
// 23.
    unsigned int num;
    printf("Enter the Number of Elements Required: ");
    scanf("%d", &num);
    print_pattern_1(num);
*/

/*
// 24.
    unsigned int num;
    printf("Enter the Number of Elements Required: ");
    scanf("%d", &num);
    print_pattern_2(num);
*/

/*
// 25.
    generate_series_2();
*/

/*
// 26.
    assert(power(2, 5) == 32);
    assert(power(5, 3) == 125);
    assert(power(2, 12) == 4096);
    assert(power(7, 4) == 2401);
*/

/*
// 27.
    assert(factorial(5) == 120);
    assert(factorial(8) == 40320);
*/

/*
// 28.
    printf("%f", series_evaluation(3, 3));
*/

/*
// 29.
    assert(CONCATENATE(56, 2) == 562);
    assert(CONCATENATE(45, 763) == 45763);
*/

/*
// 30.
    assert(SQUARE(7) == 49);
    assert(SQUARE(9) == 81);
*/

/*
// 31.
    main_menu_math_operations();
*/

/*
// 32.
    #define SIZE  5
    int arr[SIZE] = {34, 13, 65, 8, 9};
    print_int_array(arr, SIZE);
    ascending_sort(arr, SIZE);
    print_int_array(arr, SIZE);
    descending_sort(arr, SIZE);
    print_int_array(arr, SIZE);
*/

/*
// 33.
    int x = 10, y = 25;
    swap_by_ref(&x, &y);
    assert(x == 25 && y == 10);
    swap_by_ref(&x, &y);
    assert(x == 10 && y == 25);
*/

/*
// 34.
    #define SIZE 10
    int arr[SIZE] = {34, 13, 65, 8, 9, 26, 47, 2, 9, 17};
    int min, max;

    min_max_array(arr, SIZE, &min, &max);
    assert(min == 2);
    assert(max == 65);
*/

/*
// 35.
    #define SIZE_A 10
    #define SIZE_B 10
    #define SIZE_C 20
    int size_c;
    int arr_a[SIZE_A] = {34, 13, 65, 8, 9, 26, 47, 2, 9, 17};
    int arr_b[SIZE_B] = {43, 31, 56, 8, 9, 62, 74, 2, 9, 71};
    int arr_c[SIZE_C] = {0};

    printf("Array A:\t\t");
    print_int_array(arr_a, SIZE_A);
    printf("Array B:\t\t");
    print_int_array(arr_b, SIZE_B);

    size_c = set_union(arr_a, SIZE_A, arr_b, SIZE_B, arr_c, SIZE_C);
    assert(size_c == 15);
    printf("A Union B:\t\t");
    print_int_array(arr_c, size_c);

    size_c = set_intersection(arr_a, SIZE_A, arr_b, SIZE_B, arr_c, SIZE_C);
    assert(size_c == 3);
    printf("A Intersection B:\t");
    print_int_array(arr_c, size_c);

    size_c = set_difference(arr_a, SIZE_A, arr_b, SIZE_B, arr_c, SIZE_C);
    assert(size_c == 6);
    printf("A Minus B:\t\t");
    print_int_array(arr_c, size_c);

    size_c = set_difference(arr_b, SIZE_B, arr_a, SIZE_A, arr_c, SIZE_C);
    assert(size_c == 6);
    printf("B Minus A:\t\t");
    print_int_array(arr_c, size_c);
*/

    #define SIZE 10
    int arr[SIZE] = {0};
    int arr_size;

    for(int i=0; i<SIZE; i++){
        arr[i] = rand() % 10;
    }

    print_int_array(arr, SIZE);
    arr_size = remove_duplicate_in_array(arr, SIZE);
    print_int_array(arr, SIZE);
    printf("%d\n", arr_size);

    return 0;
}
