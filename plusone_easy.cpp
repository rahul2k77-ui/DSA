/*
You are given a large integer represented as an array of single digits, ordered from most significant to least significant. 
The integer does not contain any leading zeros. 
Increment the large integer by one and return the resulting array of digits, ensuring any carry-over from adding one is properly handled.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n-1; i>= 0; i--){
            if(digits[i] < 9){
                digits[i]++;
                return digits;
            }

            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        
        return digits;
    }
};

int main() {
    int n;

    cout << "Enter the total number of digits: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a valid number of digits greater than 0." << endl;
        return 1;
    }

    vector<int> digits(n);

    cout << "Enter the digits separated by spaces (e.g., 1 2 3): ";
    for (int i = 0; i < n; i++) {
        cin >> digits[i];
    }

    Solution solution;
    vector<int> result = solution.plusOne(digits);

    cout << "Output: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    return 0;
}