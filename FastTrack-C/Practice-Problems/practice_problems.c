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
