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