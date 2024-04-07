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
    
    int ans;
    vector<int> cnt;
    
    void solve(TreeNode* node) {
        if (!node)
            return;
        cnt[node->val]++;
        if (!node->left && !node->right) {
            int odd = 0;
            for (int i = 0 ; i < 10 ; i++) {
                if (cnt[i] % 2 != 0)
                    odd++;
            }
            if (odd <= 1)
                ans++;
        }
        if (node->left)
            solve(node->left);
        if (node->right)
            solve(node->right);
        cnt[node->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        ans = 0;
        cnt = vector<int>(10);
        solve(root);
        return ans;
    }
};