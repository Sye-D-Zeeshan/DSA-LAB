#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        vector<string> strings;
        int numStrings;
        cin >> numStrings;

        // Read and store the strings in a vector
        for (int j = 0; j < numStrings; ++j) {
            string str;
            cin >> str;
            strings.push_back(str);
        }

        // Sort the vector of strings based on their length
        sort(strings.begin(), strings.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
            });

        // Output the sorted set of strings
        for (const string& str : strings) {
            cout << str << " ";
        }

        cout << endl;
    }

    return 0;
}
