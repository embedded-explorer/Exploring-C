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

    return 0;
}
