#include <iostream>
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
    int sumOfLeftLeaves(TreeNode* node) {
        if (!node)
            return 0;
        if (node->left && !node->left->left && !node->left->right) {
            return node->left->val + sumOfLeftLeaves(node->right);
        } else {
            return sumOfLeftLeaves(node->left) + sumOfLeftLeaves(node->right);
        }
    }
};