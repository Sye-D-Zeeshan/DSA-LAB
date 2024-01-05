#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int removeMax() {
        if (heap.empty()) {
            cerr << "Heap is empty!" << endl;
            return -1;
        }

        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return max;
    }

    void printHeap() {
        for (int value : heap) {
            cout << value << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap maxHeap;

    vector<int> elements = {10, 12, 1, 14, 6, 5, 8, 15, 3, 9, 7, 4, 11, 13, 2};
    for (int element : elements) {
        maxHeap.insert(element);
    }

    cout << "Initial Max Heap: ";
    maxHeap.printHeap();

    cout << "\nRemoving maximum elements:\n";
    for (int i = 0; i < 7; ++i) {
        int removedValue = maxHeap.removeMax();
        cout << "Removed: " << removedValue << "\tUpdated Max Heap: ";
        maxHeap.printHeap();
    }

    return 0;
}