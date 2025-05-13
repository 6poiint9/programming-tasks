/*
Bubble-sort algorithmus mit array
als eingabeparameter. 
-> Array als eingabeparameter 
*/

#include <iostream>
#include <array>
#include <string>
using namespace std;

const size_t length = 10; // array size

template <typename T, size_t N>
// Template funktion -> array als rügkgabe
// -> call by value 
std::array<T, N> sort(std::array<T, N> arr) {
    for (size_t i = 0; i < N - 1; i++) {
        for (size_t j = 0; j < N - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}

int main() {
    array<int, length> int_container = {10, 2, 7, 5, 8, 3, 4, 1, 9, 6};
    array<int, length> sorted_int_container = sort(int_container);

    for (size_t i = 0; i < sorted_int_container.size(); i++) {
        cout << i << ": " << sorted_int_container[i] << endl;
    }

    array<char, length> char_container = {'j', 'm', 'e', 't', 'k', 'o', 'p', 's', 'a', 'f'};
    array<char, length> sorted_char_container = sort(char_container);

    for (size_t i = 0; i < sorted_char_container.size(); i++) {
        cout << i << ": " << sorted_char_container[i] << endl;
    }
    // compare() lexigrafisch
    array<string, length> string_container = {
        "Im", "Sommer", "ist", "es", "meistens", "heiß", "und", "es", "regnet", "wenig."
    };
    array<string, length> sorted_string_container = sort(string_container);

    for (size_t i = 0; i < sorted_string_container.size(); i++) {
        cout << i << ": " << sorted_string_container[i] << endl;
    }

    return 0;
}

