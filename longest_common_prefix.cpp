/*
Write a function to find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string.
*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        string prefix = strs[0];
        
        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);
                if (prefix.empty()) return "";
            }
        }
        
        return prefix;
    }
};

int main() {
    Solution sol;
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << "Test 1: " << sol.longestCommonPrefix(strs1) << endl;

    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "Test 2: " << sol.longestCommonPrefix(strs2) << endl;

    vector<string> strs3;
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cout << "Enter strings: ";
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        strs3.push_back(s);
    }
    cout << "Longest Common Prefix: " << sol.longestCommonPrefix(strs3) << endl;
    
    return 0;
}