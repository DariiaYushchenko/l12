#include <iostream>

int main() {
    const int size = 5;

    int array[size];

    std::cout << "Enter " << size << " elements separated by spaces: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> array[i];
    }

    int indexOfZero = -1;
    for (int i = 0; i < size; ++i) {
        if (array[i] == 0) {
            indexOfZero = i;
            break;
        }
    }

    if (indexOfZero != -1) {
        std::cout << "The index of the first zero element is: " << indexOfZero << std::endl;
    }
    else {
        std::cout << "The array does not contain any zero elements." << std::endl;
    }

    return 0;
}

