#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<double> array;

    std::cout << "Enter real numbers separated by spaces (enter a letter to stop): ";
    double input;
    while (std::cin >> input) {
        array.push_back(input);
    }

    if (array.empty()) {
        std::cerr << "No elements entered. Exiting." << std::endl;
        return 1;
    }
    auto minElementPos = std::min_element(array.begin(), array.end());
    double minElement = *minElementPos;
    size_t minIndex = std::distance(array.begin(), minElementPos);

    double productOfPositives = 1.0;
    for (double num : array) {
        if (num > 0) {
            productOfPositives *= num;
        }
    }

    double sumBeforeMin = 0.0;
    for (size_t i = 0; i < minIndex; ++i) {
        sumBeforeMin += array[i];
    }

    std::vector<double> evenPositioned, oddPositioned;
    for (size_t i = 0; i < array.size(); ++i) {
        if (i % 2 == 0) {
            evenPositioned.push_back(array[i]);
        }
        else {
            oddPositioned.push_back(array[i]);
        }
    }

    std::sort(evenPositioned.begin(), evenPositioned.end());
    std::sort(oddPositioned.begin(), oddPositioned.end());

    std::cout << "Product of positive elements: " << productOfPositives << std::endl;
    std::cout << "Sum of elements before the minimum element: " << sumBeforeMin << std::endl;

    std::cout << "Sorted elements at even positions: ";
    for (double num : evenPositioned) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Sorted elements at odd positions: ";
    for (double num : oddPositioned) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}