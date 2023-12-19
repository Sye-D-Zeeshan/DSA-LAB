#include <iostream>
using namespace std;
	int numberCount(int x) {
		if (x == 0)
			return 0;
	else
		return 1 + numberCount(x / 10);
		}
			int main() {
			int n;
			cout << "Enter your number :";
			cin >> n;
			cout << numberCount(n);
			}