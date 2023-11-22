#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    const int size = 9;
    double arr[size];

    cout << "Enter " << size << " real numbers separated by spaces (enter a letter to stop)::" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    double A, B;
    cout << "Enter the range [A, B]:" << endl;
    cin >> A >> B;

    int countInRange = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] >= A && arr[i] <= B) {
            countInRange++;
        }
    }

    double maxElement = arr[0];
    int maxIndex = 0;
    double sumAfterMax = 0;

    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
            maxIndex = i;
        }
    }

    for (int i = maxIndex + 1; i < size; ++i) {
        sumAfterMax += arr[i];
    }

    sort(arr, arr + size, [](double a, double b) {
        return abs(a) > abs(b);
        });

    cout << "Number of elements in the range [" << A << ", " << B << "]: " << countInRange << endl;
    cout << "Sum of elements after the maximum element: " << sumAfterMax << endl;
    cout << "Sorted array in descending order of absolute values:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
