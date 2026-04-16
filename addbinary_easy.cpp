#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }

            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            result += (sum % 2) + '0';
            carry = sum / 2;
        }

        reverse(result.begin(), result.end());
        
        return result;
    }
};

int main() {
    Solution solution;
    string a, b;

    cout << "Enter the first binary string (a): ";
    cin >> a;

    cout << "Enter the second binary string (b): ";
    cin >> b;

    string sum = solution.addBinary(a, b);
    cout << "Output: " << sum << endl;

    return 0;
}