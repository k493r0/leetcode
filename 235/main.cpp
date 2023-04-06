#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        int max = std::max(p->val, q->val), min = std::min(p->val, q->val);

        while (root != nullptr){
            if (root->val > max) root = root->left; // if root is greater than max, then the LCA must be in the left subtree
            else if (root->val < min) root = root->right; // if root is less than min, then the LCA must be in the right subtree
            else return root; // if root is between min and max, then root is the LCA
        }

        return nullptr;
    }
};

int main() {

    Solution s;
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    std::cout << s.lowestCommonAncestor(root, root->left, root->right)->val << std::endl;

    return 0;
}
