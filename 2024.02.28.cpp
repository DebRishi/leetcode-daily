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
    
    int value;
    int level;
    
    void solve(TreeNode* node, int curLevel) {
        if (!node)
            return;
        if (curLevel > level) {
            level = curLevel;
            value = node->val;
        }
        solve(node->left, curLevel + 1);
        solve(node->right, curLevel + 1);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        value = INT_MIN;
        level = INT_MIN;
        solve(root, 0);
        return value;
    }
};