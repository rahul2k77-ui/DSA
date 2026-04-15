/*
Given a string s consisting of words and spaces, return the length of the last word in the string.
A word is defined as a maximal substring consisting of non-space characters only.
Your solution must properly account for and ignore any trailing spaces at the end of the string.
Assume the input string will always contain at least one valid word.
*/


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.length() - 1;

        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }
        
        return length;
    }
};

int main() {
    string inputString;

    cout << "Enter a string: ";
    getline(cin, inputString);

    Solution solution;
    int result = solution.lengthOfLastWord(inputString);

    cout << "Output: " << result << endl;

    return 0;
}