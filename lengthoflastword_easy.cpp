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