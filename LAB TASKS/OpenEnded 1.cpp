#include <iostream>
using namespace std;
void heapify(int arr[], int N, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N && arr[l] > arr[largest])
        largest = l;
    if (r < N && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, N, largest);
    }
}
void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
    for (int i = N - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void ArrayPrint(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    const int size = 5;
    int arr[size];
    cout << "Enter " << size << " Enter Array Elements :" << endl;
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    int N = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, N);
    cout << "Sorted array is \n";
    ArrayPrint(arr, N);
    cout << "Sorted Array after Heap sort is : ";
    ArrayPrint(arr, size);
    return 0;
}