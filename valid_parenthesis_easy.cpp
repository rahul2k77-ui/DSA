/*
Given a string s containing only the characters (, ), {, }, [, ], write a program to determine if the input string is valid.
A string is valid if:

-Every open bracket is closed by the same type of bracket.
-Open brackets are closed in the correct order.
-Every closing bracket has a corresponding open bracket.
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                
                char top = st.top();
                st.pop();
                
                if (c == ')' && top != '(') return false;
                if (c == '}' && top != '{') return false;
                if (c == ']' && top != '[') return false;
            }
        }
        
        return st.empty();
    }
};

int main() {
    Solution sol;
    
    string s;
    cout << "Enter the string: ";
    cin >> s;
    
    if (sol.isValid(s))
        cout << "Output: true" << endl;
    else
        cout << "Output: false" << endl;

    return 0;
}