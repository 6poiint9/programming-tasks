#include <stdio.h>
// Recursive function to check if a number is prime
int isPrimeHelper(int num, int divisor);
int prime(int num);

int main() {
    int num;
    scanf("%d", &num);
    int res = prime(num);
    // Ausgabe
    printf("%d\n", res);  
    return 0;
}

// Wrapper function for checking if a number is prime
int prime(int num) {
    if (num <= 1) {  // Numbers less than or equal to 1 are not prime
        return 0;
    }
    return isPrimeHelper(num, num / 2);  // Start checking divisors from num/2
}

// Recursive helper function
int isPrimeHelper(int num, int divisor) {
    if (divisor == 1) {  // Base case: no divisors found, number is prime
        return 1;
    }
    if (num % divisor == 0) {  // If num is divisible by divisor, it's not prime
        return 0;
    }
    return isPrimeHelper(num, divisor - 1);  // Check next smaller divisor
}

