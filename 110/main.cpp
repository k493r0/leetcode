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

    int depth(TreeNode* root){

        if (!root) return 0;

        int left = depth(root->left);
        if (left == -1) return -1; // Do it here for earlier exit than a single condition at the end
        int right = depth(root->right);
        if (right == -1) return -1;

        if (abs(left-right) > 1) return -1;

        return std::max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {

        if (root == nullptr) return true;
        return depth(root) != -1;
    }
};

int main() {

    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(4);

    std::cout << s.isBalanced(root) << std::endl;

    return 0;
}
