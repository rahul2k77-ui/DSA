#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>> & grid, int x, int y, int k){
        for(int i=0; i < k/2; i++){
            for(int j=0; j<k; ++j){
                swap(grid[x + i][y + j], grid[x + k - 1 - i][y + j]); 
            }
        }
        return grid;
    }
};

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        cout << "[ ";
        for (int val : row) {
            cout << val << " ";
        }
        cout << "]\n";
    }
}

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9,  10, 11, 12},
        {13, 14, 15, 16}
    };
    int x = 1;
    int y = 0;
    int k = 3;

    cout << "Original Matrix:\n";
    printMatrix(grid);
    cout << "\nFlipping submatrix at (" << x << ", " << y << ") of size " << k << "...\n\n";
    vector<vector<int>> result = sol.reverseSubmatrix(grid, x, y, k);

    cout << "Updated Matrix:\n";
    printMatrix(result);

    return 0;
}