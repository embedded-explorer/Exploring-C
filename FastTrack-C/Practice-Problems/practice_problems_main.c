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
    unsigned int shape;
    float dimension_1, dimension_2, dimension_3;

    printf("Select the Shape\n");
    printf("1 : Cube\n");
    printf("2 : Cuboid\n");
    printf("3 : Sphere\n");
    printf("4 : Cylinder\n");
    printf("5 : Cone\n");
    scanf("%d", &shape);

    switch(shape){
    case 1:
        printf("Enter the Length: ");
        scanf("%f", &dimension_1);
        printf("Volume of Cube: %f", volume_of_cube(dimension_1));
        break;
    case 2:
        printf("Enter the Length: ");
        scanf("%f", &dimension_1);
        printf("Enter the Breadth: ");
        scanf("%f", &dimension_2);
        printf("Enter the Height: ");
        scanf("%f", &dimension_3);
        printf("Volume of Cuboid: %f", volume_of_cuboid(dimension_1, dimension_2, dimension_3));
        break;
    case 3:
        printf("Enter the Radius: ");
        scanf("%f", &dimension_1);
        printf("Volume of Sphere: %f", volume_of_sphere(dimension_1));
        break;
    case 4:
        printf("Enter the Radius: ");
        scanf("%f", &dimension_1);
        printf("Enter the Height: ");
        scanf("%f", &dimension_2);
        printf("Volume of Cylinder: %f", volume_of_cylinder(dimension_1, dimension_2));
        break;
    case 5:
        printf("Enter the Radius: ");
        scanf("%f", &dimension_1);
        printf("Enter the Height: ");
        scanf("%f", &dimension_2);
        printf("Volume of Cone: %f", volume_of_cone(dimension_1, dimension_2));
        break;
    default:
        printf("\nInvalid Option Selected");
    }
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
// 22. Pending
    unsigned int num;
    printf("Enter the Number of Elements Required: ");
    scanf("%d", &num);
*/

/*
// 23. Pending
    unsigned int num;
    printf("Enter the Number of Elements Required: ");
    scanf("%d", &num);
    print_pattern_1(num);
*/

/*
// 27.
    assert(factorial(5) == 120);
    assert(factorial(8) == 40320);
*/

/*
// 33.
    int x = 10, y = 25;
    swap_by_ref(&x, &y);
    assert(x == 25 && y == 10);
    swap_by_ref(&x, &y);
    assert(x == 10 && y == 25);
*/

    return 0;
}
