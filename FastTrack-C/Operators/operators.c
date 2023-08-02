// Arithmetic Operators
int add(int x, int y){
    return x + y;
}

int subtract(int x, int y){
    return x - y;
}

int multiply(int x, int y){
    return x * y;
}

int divide(int x, int y){
    if(y == 0)
        return -1;
    else
        return x / y;
}

int mod(int x, int y){
    return x % y;
}

// Relational Operators
int is_greater(int x, int y){
    return x > y;
}

int is_equal(int x, int y){
    return x == y;
}

int is_lesser(int x, int y){
    return x < y;
}

// Bitwise operators
int left_shift(int num, int pos){
    return num << pos;
}

// Increment and Decrement Operators
int post_increment(int num){
    return num++; // Returns num then increments it
}

int pre_increment(int num){
    return ++num; // Increments num and returns it
}
