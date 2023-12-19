#include<iostream>
using namespace std;
void insertionSort(float arr[], int n) {
	float key;
	for (int i = 1; i < n; i++) {
		key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
void printArray(float arr[], int size){
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
int main() {
	const int size = 5;
	float arr[size];
	cout << "Enter " << size << " Floating point numbers :" << endl;
	for (int i = 0; i < size; i++)
		cin >> arr[i];
	insertionSort(arr, size);
	cout << "Sorted Array after Selection sort is : ";
	printArray(arr, size);
	return 0;
}