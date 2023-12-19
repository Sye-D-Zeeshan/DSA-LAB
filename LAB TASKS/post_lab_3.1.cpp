#include <iostream>
using namespace std;

void reversePrint(const string& str, int index) {
    // Base case: If we have reached the beginning of the string, stop the recursion.
    if (index < 0) {
        return;
    }

    // Recursive case: Print the character at the current index and move to the previous index.
    std::cout << str[index];
    reversePrint(str, index - 1);
}

int main() {
    string inputString;

    // Input a string from the user
    cout << "Enter a string: ";
    cin >> inputString;

    int length = inputString.length();

    // Call the recursive function to print the string in reverse order
    reversePrint(inputString, length - 1);

    cout << std::endl;

    return 0;
}
