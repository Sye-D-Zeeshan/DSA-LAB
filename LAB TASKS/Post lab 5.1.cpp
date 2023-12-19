#include <iostream>
#include <chrono>

void bubbleSort(float arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int size = 1000;
    float numbers[size];

    // Initialize array with random floating-point numbers
    for (int i = 0; i < size; ++i) {
        numbers[i] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    }

    // Measure execution time of bubble sort
    auto start = std::chrono::high_resolution_clock::now();

    bubbleSort(numbers, size);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Sorted array:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << numbers[i] << " ";
    }

    std::cout << "\n\nExecution time for sorting " << size << " numbers: " << duration.count() << " microseconds\n";

    return 0;
}
