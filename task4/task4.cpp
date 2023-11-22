#include <iostream>
#include <limits>

int main() {
    const int maxSize = 10;
    int array[maxSize];

    int size;

    std::cout << "Enter the size of the array (maximum " << maxSize << "): ";
    std::cin >> size;

    if (size > maxSize || size <= 0) {
        std::cerr << "Invalid array size. Please enter a positive size less than or equal to " << maxSize << "." << std::endl;
        return 1;
    }

    std::cout << "Enter " << size << " integer numbers: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> array[i];
    }

    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (array[i] > array[maxIndex]) {
            maxIndex = i;
        }
    }

    int firstZeroIndex = -1;
    int secondZeroIndex = -1;
    for (int i = 0; i < size; ++i) {
        if (array[i] == 0) {
            if (firstZeroIndex == -1) {
                firstZeroIndex = i;
            }
            else {
                secondZeroIndex = i;
                break;
            }
        }
    }

    int productBetweenZeros = 1;
    if (firstZeroIndex != -1 && secondZeroIndex != -1 && firstZeroIndex < secondZeroIndex) {
        for (int i = firstZeroIndex + 1; i < secondZeroIndex; ++i) {
            productBetweenZeros *= array[i];
        }
    }

    std::cout << "Index of maximum element: " << maxIndex << std::endl;
    std::cout << "Product of elements between first and second zero elements: " << productBetweenZeros << std::endl;

    int transformedArray[maxSize];
    int transformedSize = 0;

    for (int i = 0; i < size; i += 2) {
        transformedArray[transformedSize++] = array[i];
    }

    for (int i = 1; i < size; i += 2) {
        transformedArray[transformedSize++] = array[i];
    }

    std::cout << "Transformed array: ";
    for (int i = 0; i < transformedSize; ++i) {
        std::cout << transformedArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
