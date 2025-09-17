#include <iostream>
#include <queue>
using namespace std;

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    queue<char> q;
    int freq[256] = {0};   // frequency array for ASCII chars

    for (char c : s) {
        freq[c]++;
        q.push(c);

        // Remove characters from queue until front is non-repeating
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (q.empty()) cout << "-1 ";
        else cout << q.front() << " ";
    }
    return 0;
}
