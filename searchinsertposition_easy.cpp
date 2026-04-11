#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return left;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {1, 3, 5, 6};
    int target1 = 5;
    cout << "Example 1 Output: " << sol.searchInsert(nums1, target1) << " (Expected: 2)\n";
    
    // Example 2
    vector<int> nums2 = {1, 3, 5, 6};
    int target2 = 2;
    cout << "Example 2 Output: " << sol.searchInsert(nums2, target2) << " (Expected: 1)\n";

    // Example 3
    vector<int> nums3 = {1, 3, 5, 6};
    int target3 = 7;
    cout << "Example 3 Output: " << sol.searchInsert(nums3, target3) << " (Expected: 4)\n";

    return 0;
}