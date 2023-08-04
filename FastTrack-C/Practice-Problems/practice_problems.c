// 1.
char upper_to_lower(char ch){
    if(ch >= 'A' && ch <= 'Z')
        return ch + 32; // A = 65, a = 97
    else
        return '!'; // Invalid input received
}

// 2.
float area_of_circle(float radius){
    return 3.14 * radius * radius; // Pi * r^2
}

// 3.
int char_between_char(char ch_1, char ch_2){
    if(ch_1 > ch_2)
        return ch_1 - ch_2 - 1;
    else
        return ch_2 - ch_1 - 1;
}

// 4.
float celsius_to_fahrenheit(float temperature){
    return temperature * 1.8 + 32; // Multiply by 1.8 (or 9/5) and add 32
}

// 5.
unsigned int odd_or_even(int num){
    return num % 2; // Return 1 if odd, 0 if even
}

// 6.
int check_leap_year(int year){
    // Must be exactly divisible by 4
    // Century years must also be divisible by 400
    // Return 1 if its leap year else return 0
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

// 7.
int pow_of_2(int raise){
    return 1 << raise;
}

// 8.
int char_or_int(char ch){
    if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        return 0;
    else if(ch >= '0' && ch <= '9')
        return 1;
    else
        return -1;
}

// 9.
unsigned int add_rand(unsigned int x, unsigned int y){
    return x + y;
}

// 10.
unsigned int sum_of_digits(unsigned int num){
    unsigned int sum = 0;

    while(num > 0){
        sum += num % 10; // 5, 4, 3, 2, 1
        num = num / 10; // 1234, 123, 12, 1
    }

    return sum;
}

// 11.
unsigned int reverse_of_num(unsigned int num){
    unsigned int rev = 0;

    while(num > 0){
        rev = (rev * 10) + (num % 10);
        num = num / 10;
    }

    return rev;
}

// 12.
unsigned int count_digit(unsigned int num, unsigned int digit){
    unsigned int rem = 0;
    unsigned int count = 0;

    while(num > 0){
        rem = num % 10;
        num = num / 10;
        if(digit == rem){
            count++;
        }
    }

    return count;
}

// 13.
unsigned int check_palindrome(unsigned int num){
    unsigned int rev = 0;
    unsigned int temp = num;

    while(temp > 0){
        rev = (rev * 10) + (temp % 10);
        temp = temp / 10;
    }

    return rev == num; // Return 1 if palindrome, 0 if not a palindrome
}

// 14.
// Function to check if given number is prime or not
// Return 1 if number is prime else return 0
unsigned int is_prime(unsigned int num){
    if(num < 2){
        return 0;
    }

    for(int k=2; k<= num/2; k++){
        if(num % k == 0){
        // i is completely divisible by k
            return 0;
        }
    }

    return 1;
}

/*
// 15.
unsigned int sum_of_series(unsigned int num){
    unsigned int count = 1, sum = 0;

    for(int i=1; i<=num; i++){
        printf("%d ", count);
        if(i < num){
            printf("+ ");
        }
        sum = sum + count; // Calculate sum
        count = (count*10)+1; // 1, 11, 111, 1111
    }
    printf("= %d", sum);
    return 0;
}
*/

// 16.
unsigned int check_if_armstrong(unsigned int num){
    unsigned long int sum_of_cubes = 0;
    unsigned int rem, temp = num;

    while(temp > 0){
        rem = temp % 10;
        temp = temp / 10;
        sum_of_cubes += rem * rem * rem;
    }

    // Return 1 if number is Armstrong number
    return (num == sum_of_cubes);
}

// 17.
unsigned int check_if_amicable(unsigned int num_1, unsigned int num_2){
    unsigned int sum_1 = 0, sum_2 = 0;

    for(int i=1; i<= num_1/2; i++){
        if(num_1%i == 0){
            sum_1 = sum_1 + i;
        }
    }

    for(int j=1; j<= num_2/2; j++){
        if(num_2%j == 0){
            sum_2 = sum_2 + j;
        }
    }

    if((num_1 == sum_2) && (num_2 == sum_1)){
        return 1;
    }
    else{
        return 0;
    }
}

// 18.
unsigned int menu_driven_calculator(unsigned int num_1, unsigned int num_2, char operation){
    switch(operation){
    case '+':
        return num_1 + num_2;
        break;
    case '-':
        return num_1 - num_2;
        break;
    case '*':
        return num_1 * num_2;
        break;
    default :
        return -1;
        break;
    }
}

// 19.
float volume_of_cube(float length){
    return length * length * length;
}

float volume_of_cuboid(float length, float breadth, float height){
    return length * breadth * height;
}

float volume_of_sphere(float radius){
    return 4.188* radius * radius * radius; // 4/3 * Pi * r^3
}

float volume_of_cylinder(float radius, float height){
    return 3.14 * radius * radius * height;
}

float volume_of_cone(float radius, float height){
    return (3.14 * radius * radius * height)/3;
}

// 20.
float electricity_bill(float units_consumed){
    float rem, amount = 0;

    if(units_consumed > 300){
        rem = units_consumed - 300;
        units_consumed = 300;
        amount += rem * 10;
    }
    if(units_consumed > 200){
        rem = units_consumed - 200;
        units_consumed = 200;
        amount += rem * 7;
    }
    if(units_consumed >= 0){
        amount += units_consumed * 5;
    }

    return amount;
}

// 21.
unsigned int bin_2_dec(unsigned long int num){
    unsigned int rem, dec = 0, pow = 1; // 2^0 = 1

    while(num > 0){
        rem = num % 10; // Get the LSB Digit
        num = num/10;   // Neglect the LSB Digit
        dec += rem * pow;
        pow = pow * 2;  // 2^1 = 2, 2^2 = 4, 2^3 = 8 ...
    }

    return dec;
}

unsigned long int dec_2_bin(unsigned int num){
    unsigned int rem, bin = 0;
    while(num > 0){
        rem = num % 2;
        num = num / 2;
        bin = bin*10 + rem;
    }

    // Actual Binary number is reverse of the result
    return reverse_of_num(bin);
}

// 22.


// 23.
void print_pattern_1(int n){
    for(int i=0; i<n; i++){
        for(int j=n; j>i; j--){
            printf("*");
        }
        printf("\n");
    }
}

// 24.

// 27.
int factorial(int num){
    if(num == 1)
        return 1;
    else
        return num * factorial(num-1);
}

// 33.
void swap_by_ref(int *ptr_1, int *ptr_2){
    int temp = *ptr_1;
    *ptr_1 = *ptr_2;
    *ptr_2 = temp;
}
