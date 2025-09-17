#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int prec(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(string expr) {
    stack<char> st;
    string result;

    for (char c : expr) {
        if (isalnum(c)) {
            result += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }
        else {
            while (!st.empty() && prec(st.top()) >= prec(c)) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    return result;
}

int main() {
    string expr;
    cout << "Enter infix expression: ";
    cin >> expr;

    cout << "Postfix: " << infixToPostfix(expr) << endl;
    return 0;
}
