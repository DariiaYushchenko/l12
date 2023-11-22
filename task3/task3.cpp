#include <iostream>
#include <limits>

int main() {
    const int maxSize = 10;
    double array[maxSize];

    int size;

    std::cout << "Enter the size of the array (maximum " << maxSize << "): ";
    std::cin >> size;

    if (size > maxSize || size <= 0) {
        std::cerr << "Invalid array size. Please enter a positive size less than or equal to " << maxSize << "." << std::endl;
        return 1;
    }

    std::cout << "Enter " << size << " real numbers: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> array[i];
    }

    double minElement = std::numeric_limits<double>::max();
    for (int i = 0; i < size; ++i) {
        if (array[i] < minElement) {
            minElement = array[i];
        }
    }

    int firstPositiveIndex = -1;
    int lastPositiveIndex = -1;
    for (int i = 0; i < size; ++i) {
        if (array[i] > 0) {
            if (firstPositiveIndex == -1) {
                firstPositiveIndex = i;
            }
            lastPositiveIndex = i;
        }
    }

    double sumBetweenPositives = 0.0;
    if (firstPositiveIndex != -1 && lastPositiveIndex != -1 && firstPositiveIndex < lastPositiveIndex) {
        for (int i = firstPositiveIndex + 1; i < lastPositiveIndex; ++i) {
            sumBetweenPositives += array[i];
        }
    }

    std::cout << "Minimum element: " << minElement << std::endl;
    std::cout << "Sum of elements between first and last positive elements: " << sumBetweenPositives << std::endl;

    int zeroCount = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i] == 0) {
            ++zeroCount;
        }
    }

    for (int i = 0; i < size; ++i) {
        if (zeroCount > 0) {
            array[i] = 0;
            --zeroCount;
        }
        else {
            array[i] = minElement;
        }
    }


    std::cout << "Transformed array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}