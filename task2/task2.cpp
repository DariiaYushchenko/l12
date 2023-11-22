#include <iostream>

int main() {

    const int maxSize = 10;
    int array[maxSize];

    int size;

    std::cout << "Enter the size of the array (maximum " << maxSize << "): ";
    std::cin >> size;

    if (size > maxSize || size < 3) {
        std::cerr << "Invalid array size. Please enter a size between 3 and " << maxSize << "." << std::endl;
        return 1;
    }


    std::cout << "Enter " << size << " elements separated by spaces: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> array[i];
    }

    for (int i = 1; i < size - 1; ++i) {
        array[i] = (array[i - 1] + array[i + 1]) / 2;
    }

    std::cout << "Modified array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
