#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int main() {
    const int size = 300;
    int arr[size];

    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 201 - 100;
    }

    unordered_map<int, vector<int>> sumIndices;
    int sum = 0;

    for (int i = 0; i < size; ++i) {
        sum += arr[i];

        if (sum == 0) {

            cout << "Zero sum subarray found: ";
            for (int j = 0; j <= i; ++j) {
                cout << arr[j] << " ";
            }
            cout << endl;
        }

        if (sumIndices.find(sum) != sumIndices.end()) {

            cout << "Zero sum subarray found: ";
            for (int j : sumIndices[sum]) {
                cout << arr[j + 1] << " ";
            }
            cout << "to ";
            for (int j = i; j <= i; ++j) {
                cout << arr[j] << " ";
            }
            cout << endl;
        }
        else {

            sumIndices[sum].push_back(i);
        }
    }

    return 0;
}