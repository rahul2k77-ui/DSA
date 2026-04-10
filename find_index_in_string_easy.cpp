/*
Given two strings, haystack and needle, 
which consist entirely of lowercase English characters and have lengths between 1 and 10,000, 
write a program to return the integer index of the first occurrence of needle within haystack,
or return -1 if the needle string is not found.
*/


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        
        if (n < m) {
            return -1;
        }

        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == m) {
                return i;
            }
        }
        
        return -1;
    }
};

int main() {
    Solution sol;
    cout << sol.strStr("sadbutsad", "sad") << "\n";
    cout << sol.strStr("leetcode", "leeto") << "\n";
    return 0;
}