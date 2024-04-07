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
    
    int answer;
    
    int solve(TreeNode* root) {
        if (!root)
            return 0;
        int lcnt = solve(root->left);
        int rcnt = solve(root->right);
        answer = max(answer, 1 + lcnt + rcnt);
        return 1 + max(lcnt, rcnt);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        answer = 0;
        solve(root);
        return answer;
    }
};