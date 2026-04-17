#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        
        int left = 1;
        int right = x;
        int ans = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (mid <= x / mid) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    // 1. Create an instance of the Solution class
    Solution sol; 
    
    int test1 = 4;
    int test2 = 8;
    
    printf("Example 1:\n");
    printf("Input: x = %d\n", test1);
    // 2. Call the function using the instance
    printf("Output: %d\n\n", sol.mySqrt(test1)); 
    
    printf("Example 2:\n");
    printf("Input: x = %d\n", test2);
    // 2. Call the function using the instance
    printf("Output: %d\n", sol.mySqrt(test2)); 
    
    return 0;
}