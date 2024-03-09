#include <iostream>
#include <stack>
#include <string>
using namespace std;
string checkBrackets(const string& str) {
    stack<int> stk;
    char result[1000];
    int i = 0;
    for (char ch : str) {
        if (ch == '(') {
            stk.push(i);
            result[i] = ' ';
        }
        else if (ch == ')') {
            if (!stk.empty()) {
                stk.pop();
                result[i] = ' ';
            }
            else {
                result[i] = '?';
            }
        }
        else {
            result[i] = ' ';
        }
        i++;
    }
    result[i] = '\0';
    int k;
    while (!stk.empty()) {
        k = stk.top();
        result[k] = 'x';
        stk.pop();
    }
    string r(result);
    return r;
}

int main() {
    string testCases[] = {
        "bge)))))))))",
        "((IIII))))))",
        "()()()()(uuu",
        "))))UUUU((()"
    };

    for (const string& testCase : testCases) {
        cout << testCase << endl;
        cout << checkBrackets(testCase) << endl;
    }
    return 0;
}