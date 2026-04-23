#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <sstream>

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            result.push_back(curr->val);
            curr = curr->right;
        }
        return result;
    }
};

TreeNode* buildTree(string input) {
    if (input.empty() || input == "null") return nullptr;
    
    stringstream ss(input);
    string item;
    getline(ss, item, ' ');
    
    if (item == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if (!getline(ss, item, ' ')) break;
        if (item != "null") {
            curr->left = new TreeNode(stoi(item));
            q.push(curr->left);
        }

        if (!getline(ss, item, ' ')) break;
        if (item != "null") {
            curr->right = new TreeNode(stoi(item));
            q.push(curr->right);
        }
    }
    return root;
}

int main() {
    Solution solution;
    string input;

    cout << "Enter tree nodes in level-order, separated by spaces (use 'null' for empty nodes)." << endl;
    cout << "Example 1 format: 1 null 2 3" << endl;
    cout << "Example 2 format: 1 2 3 4 5 null 8 null null 6 7 9" << endl;
    cout << "Input: ";

    getline(cin, input);

    TreeNode* root = buildTree(input);

    vector<int> result = solution.inorderTraversal(root);

    cout << "\nInorder Traversal Output: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << (i < result.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;

    return 0;
}