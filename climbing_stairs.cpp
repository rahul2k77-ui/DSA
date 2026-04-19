#include<iostream>

class Solution {
public:
    int climbStairs(int n) {
        
        if (n <= 2) {
            return n;
        }
        
        int prev2 = 1; 
        int prev1 = 2; 
        int currentWays = 0;
        
        for (int i = 3; i <= n; i++) {
            currentWays = prev1 + prev2;
            
            prev2 = prev1;
            prev1 = currentWays;
        }
        
        return currentWays;
    }
};

int main() {
    Solution solution;
    int n;

    std::cout << "Enter the number of stairs (n): ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Please enter a positive integer." << std::endl;
    } else {

        int result = solution.climbStairs(n);
        std::cout << "Distinct ways to climb to the top: " << result << std::endl;
    }
    return 0;
}