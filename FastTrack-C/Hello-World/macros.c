#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Object Like Macros
#define SIZE 25
#define MIN 5
#define MAX 9

// Function Like Macros
#define MAX_ELEMENT(X, Y) X>Y ? X : Y
#define SQUARE(X) X*X

int main(){
    // Text will be replaced as it is, be careful while passing arguments
    printf("Result = %d\n", SQUARE(3+4)); // 3+4*3+4

    printf("Max Value is %d\n", MAX_ELEMENT(MIN, MAX));
    assert(SQUARE(5) == 25);

    assert(SIZE == 25);

// Conditional Macros
#ifdef SIZE
#undef SIZE
#define SIZE 20
    assert(SIZE == 20);
#endif // SIZE

    return 0;
}
