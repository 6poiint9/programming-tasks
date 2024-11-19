#include <stdio.h>

// Function to evaluate conditions and flip values of a and b
void func(int input, int *a, int *b) {
    if (input % 2 != 0 && input % 3 == 0 && input % 5 == 0) {
        *a = !(*a);  // Flip the value of a
        if (*a == 0) {
            *b = !(*b);  // Set b to opposite value of a only if a is now 0
        }
    }
}

int main() {
    int input;
    int a = 0;  // Initialize a to false (0)
    int b = 0;  // Initialize b to false (0)

    // Input prompt
    printf("Enter an integer: ");
    scanf("%d", &input);

    // Call func to process a and b based on input
    func(input, &a, &b);

    // Print results
    printf("a = %d, b = %d\n", a, b);

    return 0;
}

