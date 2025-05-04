#include <iostream>
#include <string>
#include <stdexcept>  // For exception handling

using namespace std;

// Function for input
double getInput(const string& prompt) {
    double value;
    cout << prompt;
    cin >> value;
    return value;
}

// Function for printing the array
void printArray(double arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << i + 1 << ". " << arr[i] << endl;
    }
}

int main() {
    double a = getInput("Enter a: ");
    double b = getInput("Enter b: ");

    double arr[4] = {0.0, 0.0, 0.0, 0.0};
    int index;

    int length = sizeof(arr) / sizeof(arr[0]);

    cout << "Enter array index: ";
    cin >> index;

    try {
        if (b == 0) {
            throw runtime_error("Division by zero!");
        }

        if (index < 0 || index >= length) {
            throw out_of_range("Index out of bounds!");
        }

        double divide = a / b;
        cout << a << " / " << b << " = " << divide << endl;

        arr[index] = divide;
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

    cout << "\nArray contents: \n";
    printArray(arr, length);

    return 0;
}

