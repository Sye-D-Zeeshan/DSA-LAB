#include <iostream>
using namespace std;

struct MinMax {
    int min;
    int max;
};

MinMax FindMinMax(int arr[], int low, int high) {
    MinMax mm = { arr[low], arr[low] };
    if (low == high) {
        mm.min = arr[low];
        mm.max = arr[low];
        return mm;
    }

    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            mm.min = arr[low];
            mm.max = arr[high];
        }
        else {
            mm.min = arr[high];
            mm.max = arr[low];
        }
        return mm;
    }

    int mid = low + (high - low) / 2;
    MinMax left_mm = FindMinMax(arr, low, mid);
    MinMax right_mm = FindMinMax(arr, mid + 1, high);

    mm.min = (left_mm.min < right_mm.min) ? left_mm.min : right_mm.min;
    mm.max = (left_mm.max > right_mm.max) ? left_mm.max : right_mm.max;

    return mm;
}


int main() {
    const int size = 10;
    int arr[size];
    for (int i = 0; i < size; i++) {
        cout << "Enter the value of the Array at index " << i << ": ";
        cin >> arr[i];
    }

    MinMax result = FindMinMax(arr, 0, size - 1);

    cout << "Minimum Value of the Array: " << result.min << endl;
    cout << "Maximum Value of the Array: " << result.max << endl;
    return 0;
}