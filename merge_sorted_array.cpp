#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; 
        int j = n - 1; 
        int k = m + n - 1; 

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }
};

int main() {
    Solution solution;
    int m, n;

    cout << "Enter the number of valid elements in nums1 (m): ";
    cin >> m;
    
    cout << "Enter the number of elements in nums2 (n): ";
    cin >> n;

    vector<int> nums1(m + n, 0); 
    
    if (m > 0) {
        cout << "Enter the " << m << " sorted elements of nums1: ";
        for (int i = 0; i < m; i++) {
            cin >> nums1[i];
        }
    }

    vector<int> nums2(n);
    if (n > 0) {
        cout << "Enter the " << n << " sorted elements of nums2: ";
        for (int i = 0; i < n; i++) {
            cin >> nums2[i];
        }
    }

    solution.merge(nums1, m, nums2, n);

    cout << "\nMerged Array: [";
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << (i < nums1.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;

    return 0;
}