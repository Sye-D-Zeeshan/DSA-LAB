#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    queue<float> floatQueue;

    for (int i = 0; i < N; ++i) {
        float value;
        cin >> value;
        floatQueue.push(value);
    }

    int dequeueCount = min(N, 5);
    for (int i = 0; i < dequeueCount; ++i) {
        if (!floatQueue.empty()) {
            cout << floatQueue.front() << "\n";
            floatQueue.pop();
        } else {
            cout << "Queue is empty, cannot perform dequeue operation.\n";
        }
    }

    return 0;
}
