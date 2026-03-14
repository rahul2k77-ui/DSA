#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        
        std::unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int total = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {

            if (i < n - 1 && roman[s[i]] < roman[s[i + 1]]) {
                total -= roman[s[i]];
            } else {
                total += roman[s[i]];
            }
        }
        
        return total;
    }
};

int main() {

    Solution solution;

    // Test cases
    std::string test1 = "III";
    std::string test2 = "LVIII";
    std::string test3 = "MCMXCIV";

    // Execute the function and print the results
    std::cout << "Input: " << test1 << " -> Output: " << solution.romanToInt(test1) << std::endl;
    std::cout << "Input: " << test2 << " -> Output: " << solution.romanToInt(test2) << std::endl;
    std::cout << "Input: " << test3 << " -> Output: " << solution.romanToInt(test3) << std::endl;

    // Optional: Allow interactive input from the terminal
    std::string customInput;
    std::cout << "\nEnter your own Roman numeral: ";
    std::cin >> customInput;
    std::cout << "Output: " << solution.romanToInt(customInput) << std::endl;

    return 0;
}