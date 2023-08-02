#include <stdio.h>
#include <assert.h>
#include "storage_classes.h"

int main(){
    /*
    // Extern Keyword Example
    assert(global_variable == 37);
    increment();
    increment();
    assert(global_variable == 39);
    */

    assert(increment_int() == 0);
    assert(increment_int() == 0);
    assert(increment_int() == 0);
    assert(increment_static_int() == 0);
    assert(increment_static_int() == 1);
    assert(increment_static_int() == 2);

    return 0;
}
