#include <iostream>
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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        depth(root, diameter);
        return diameter;
    }

private:
    int depth(TreeNode* root, int& diameter) {
        if (root == nullptr) return 0;

        int leftDepth = depth(root->left, diameter);
        int rightDepth = depth(root->right, diameter);
        diameter = std::max(diameter, leftDepth + rightDepth);
        return std::max(leftDepth, rightDepth) + 1;
    }
};

int main() {

    Solution s;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << s.diameterOfBinaryTree(root) << std::endl;

    return 0;
}