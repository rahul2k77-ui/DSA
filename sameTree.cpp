#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr || p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

TreeNode* buildTree(const std::vector<std::string>& nodes) {
    if (nodes.empty() || nodes[0] == "null" || nodes[0] == "N") {
        return nullptr;
    }

    TreeNode* root = new TreeNode(std::stoi(nodes[0]));
    std::queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (nodes[i] != "null" && nodes[i] != "N") {
            curr->left = new TreeNode(std::stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null" && nodes[i] != "N") {
            curr->right = new TreeNode(std::stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

std::vector<std::string> parseInput(const std::string& line) {
    std::vector<std::string> nodes;
    std::stringstream ss(line);
    std::string node;
    while (ss >> node) {
        nodes.push_back(node);
    }
    return nodes;
}


void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    std::string line1, line2;

    std::cout << "Enter Tree 1 nodes in level-order (use 'null' or 'N' for empty nodes, space-separated): \n";
    std::cout << "Example: 1 2 3\n> ";
    std::getline(std::cin, line1);

    std::cout << "Enter Tree 2 nodes in level-order (use 'null' or 'N' for empty nodes, space-separated): \n";
    std::cout << "Example: 1 N 2\n> ";
    std::getline(std::cin, line2);

    std::vector<std::string> nodes1 = parseInput(line1);
    std::vector<std::string> nodes2 = parseInput(line2);

    TreeNode* p = buildTree(nodes1);
    TreeNode* q = buildTree(nodes2);

    Solution solution;
    bool result = solution.isSameTree(p, q);

    std::cout << "\nResult: " << (result ? "true" : "false") << std::endl;

    deleteTree(p);
    deleteTree(q);

    return 0;
}