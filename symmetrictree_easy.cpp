/*
Given the root of a binary tree, determine if it is symmetric (a mirror of itself around its center).
Return true if it is symmetric, or false otherwise.
A symmetric tree requires the left and right subtrees to be exact mirror reflections of each other.
This means corresponding nodes must have identical values, and their child structures must also be mirrored.
*/

#include <iostream>
#include <string>
#include <queue>
#include <sstream>
#include <vector>

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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* leftNode, TreeNode* rightNode) {
        if (leftNode == nullptr && rightNode == nullptr) return true;
        if (leftNode == nullptr || rightNode == nullptr) return false;
        
        return (leftNode->val == rightNode->val) &&
               isMirror(leftNode->left, rightNode->right) &&
               isMirror(leftNode->right, rightNode->left);
    }
};

TreeNode* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') {
        return nullptr;
    }

    vector<string> ip;
    istringstream iss(str);
    for (string s; iss >> s; ) {
        ip.push_back(s);
    }

    TreeNode* root = new TreeNode(stoi(ip[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < ip.size()) {
        TreeNode* currNode = q.front();
        q.pop();

        string currVal = ip[i];
        if (currVal != "N") {
            currNode->left = new TreeNode(stoi(currVal));
            q.push(currNode->left);
        }

        i++;
        if (i >= ip.size()) break;

        currVal = ip[i];
        if (currVal != "N") {
            currNode->right = new TreeNode(stoi(currVal));
            q.push(currNode->right);
        }
        i++;
    }

    return root;
}

void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    cout << "Enter tree nodes in level-order separated by spaces (use 'N' for null nodes)." << endl;
    cout << "Example 1 (Symmetric): 1 2 2 3 4 4 3" << endl;
    cout << "Example 2 (Asymmetric): 1 2 2 N 3 N 3" << endl;
    cout << "Enter your tree: ";
    
    string inputLine;
    getline(cin, inputLine);

    TreeNode* root = buildTree(inputLine);
    
    Solution solution;
    bool result = solution.isSymmetric(root);
    
    cout << "Output: " << (result ? "true" : "false") << endl;

    deleteTree(root);

    return 0;
}