#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        
        return k;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {3, 2, 2, 3};
    
    int val1 = 3;
    int k1 = sol.removeElement(nums1, val1);
    cout << "Example 1 Output: k = " << k1 << ", nums = [";
    for (int i = 0; i < k1; i++) {
        cout << nums1[i];
        if (i < k1 - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    int k2 = sol.removeElement(nums2, val2);
    cout << "Example 2 Output: k = " << k2 << ", nums = [";
    for (int i = 0; i < k2; i++) {
        cout << nums2[i];
        if (i < k2 - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}