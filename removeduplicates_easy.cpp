/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. 
The relative order of the elements should be kept the same. 
Then return the number of unique elements in nums.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int i=1;

        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[j - 1]) {
                nums[i] = nums[j];
                i++;
            }
        }

        return i;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1, 1, 2};

    cout << "--- Test Case 1 ---" << endl;
    int k = solution.removeDuplicates(nums);

    cout << "Output k: " << k << endl;
    cout << "Modified array: [";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << (i < k - 1 ? ", " : "");
    }
    cout << "]\n\n";

    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    
    cout << "--- Test Case 2 ---" << endl;
    int k2 = solution.removeDuplicates(nums2);
    
    cout << "Output k: " << k2 << endl;
    cout << "Modified array: [";
    for (int i = 0; i < k2; i++) {
        cout << nums2[i] << (i < k2 - 1 ? ", " : "");
    }
    cout << "]\n";

    return 0;
}