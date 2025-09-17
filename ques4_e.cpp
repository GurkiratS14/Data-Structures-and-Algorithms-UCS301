#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter a character: ";
    cin >> ch;

    if(ch >= 'A' && ch <= 'Z') {
        ch = ch + 32; 
        cout << "Lowercase: " << ch << endl;
    } else {
        cout << "Already lowercase or not an uppercase letter: " << ch << endl;
    }

    return 0;
}
