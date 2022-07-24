#include <stdio.h>

int num_digits(long n){
    int digits = 0;
    while (n != 0){
        n = n / 10;
        digits++;
    }
    return digits;
}

int get_digit(long n, int pos){
    for (int i = 0; i < pos; i++){
        n /= 10;
    }
    return n % 10;
}

int check_valid(long n, int d){
    int digit_sum = 0;
    for (int i = 1; i <= d; i += 2){
        int dd = get_digit(n, i) * 2;

        int first_digit = dd / 10;
        int second_digit = dd % 10;
        digit_sum += first_digit + second_digit;
        // digit_sum = digit_sum + (first_digit + second_digit);

        // digit_sum += (dd / 10) + (dd % 10);
    }
    for (int i = 0; i <= d; i += 2){
        digit_sum += get_digit(n, i);
    }
    return (digit_sum % 10 == 0);
}

int main() 
{
    long n;
    printf("Credit Card Number: ");
    scanf("%ld", &n);

    int d = num_digits(n);

    int is_valid = check_valid(n, d);

    if (!is_valid){
        printf("INVALID\n");
    }
    
    else if (d == 15 && get_digit(n++, 14) == 3 && (
            get_digit(n, 13) == 4 ||
            get_digit(n, 13) == 7            
        )){

        printf("AMEX\n");
    }
    else if ((d == 13 && get_digit(n, 12) == 4) || (d == 16 && get_digit(n, 15) == 4)){
        printf("VISA\n");
    }
    else if (d == 16 && get_digit(n, 15) == 5 && (
            get_digit(n, 14) == 1 || 
            get_digit(n, 14) == 2 || 
            get_digit(n, 14) == 3 || 
            get_digit(n, 14) == 4 || 
            get_digit(n, 14) == 5
        )){

        printf("MASTERCARD\n");
    }

    else {
        printf("INVALID\n");
    }

}