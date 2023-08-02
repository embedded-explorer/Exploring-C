#include <assert.h> // pre-defined header file searched in pre-designated directory
#include "operators.h" // User defined header file searched locally

// Assertions can be used to check expected results
// Assertions work for int and char but not for float due to precision
int main(){
    // Arithmetic Operators
    assert(add(3, 4) == 7);
    assert(subtract(4, 3) == 1);
    assert(multiply(3, 2) == 6);
    assert(divide(30, 6) == 5);
    assert(divide(10, 0) == -1);
    assert(mod(30, 7) == 2);
    assert(mod(-4, 3) == -1);
    assert(add(5, 5) == multiply(2, 5));

    // Relational Operators
    assert(is_greater(5, 10) == 0);
    assert(is_equal(5, 5) == 1);
    assert(is_lesser(5, 10) == 1);

    // Bitwise Operators
    assert(left_shift(4, 2) == 16);

    // Increment and Decrement Operators
    assert(post_increment(5) == 5);
    assert(pre_increment(5) == 6);

    return 0;


}
