#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
private:
    int checkHeight(TreeNode* node) {
        
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1;

        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1; 

        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        return max(leftHeight, rightHeight) + 1;
    }   
};

TreeNode* buildTree(const string& str) {
    if (str.empty() || str == "[]") return nullptr;

    string cleanStr = str;
    cleanStr.erase(remove(cleanStr.begin(), cleanStr.end(), '['), cleanStr.end());
    cleanStr.erase(remove(cleanStr.begin(), cleanStr.end(), ']'), cleanStr.end());

    replace(cleanStr.begin(), cleanStr.end(), ',', ' ');

    stringstream ss(cleanStr);
    string item;

    ss >> item;
    if (item == "null" || item.empty()) return nullptr;
    
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if (ss >> item) {
            if (item != "null") {
                curr->left = new TreeNode(stoi(item));
                q.push(curr->left);
            }
        } else {
            break; 
        }

        if (ss >> item) {
            if (item != "null") {
                curr->right = new TreeNode(stoi(item));
                q.push(curr->right);
            }
        } else {
            break;
        }
    }
    return root;
}

int main() {
    cout << "Enter tree in LeetCode level-order format (e.g., [3,9,20,null,null,15,7]):\n> ";
    string input;
    getline(cin, input);

    TreeNode* root = buildTree(input);

    Solution sol;
    bool result = sol.isBalanced(root);

    cout << "Output: " << (result ? "true" : "false") << "\n";

    return 0;
}