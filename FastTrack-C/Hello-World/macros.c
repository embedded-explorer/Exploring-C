#include <stdio.h>

#define CAL(X) X*X

int main(){
    // Text will be replaced as it is operation will not occur
    printf("Result = %d\n", CAL(3+4)); // 3+4*3+4
    return 0;
}
