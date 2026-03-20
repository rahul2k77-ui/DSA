#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }
        return x == reversedHalf || x == reversedHalf / 10;
    }
};

int main() {
    Solution solution;
    int userInput;
    std::cout << "Enter an integer to check if it's a palindrome: ";

    std::cin >> userInput;

    std::cout << std::boolalpha;
    bool result = solution.isPalindrome(userInput);
    std::cout << "\nInput: x = " << userInput << "\nOutput: " << result << "\n";

    return 0;
    
}