#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int max_possible_cost = m + n;
        int k_limit = min(k, max_possible_cost);

        vector<vector<int>> dp(n, vector<int>(k_limit + 1, -1));

        dp[0][0] = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                
                int cell_cost = (grid[i][j] == 0) ? 0 : 1;
                int cell_score = (grid[i][j] == 0) ? 0 : (grid[i][j] == 1) ? 1 : 2;

                vector<int> new_dp(k_limit + 1, -1);
                
                for (int c = 0; c <= k_limit - cell_cost; ++c) {

                    if (i > 0 && dp[j][c] != -1) {
                        new_dp[c + cell_cost] = max(new_dp[c + cell_cost], dp[j][c] + cell_score);
                    }
                    
                    if (j > 0 && dp[j - 1][c] != -1) {
                        new_dp[c + cell_cost] = max(new_dp[c + cell_cost], dp[j - 1][c] + cell_score);
                    }
                }
                
                dp[j] = new_dp;
            }
        }
        
        int max_score = -1;
        for (int c = 0; c <= k_limit; ++c) {
            max_score = max(max_score, dp[n - 1][c]);
        }
        
        return max_score;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid1 = {{0, 1}, {2, 0}};
    int k1 = 1;
    cout << "Example 1 Output: " << sol.maxPathScore(grid1, k1) << "\n";
    cout << "Expected: 2\n\n";

    vector<vector<int>> grid2 = {{0, 1}, {1, 2}};
    int k2 = 1;
    cout << "Example 2 Output: " << sol.maxPathScore(grid2, k2) << "\n";
    cout << "Expected: -1\n";

    return 0;
}