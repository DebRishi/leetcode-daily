#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    int convert(string& str) {
        int num = 0;
        for (char ch : str) {
            if (num & (1 << (ch-'a')))
                return 0;
            else
                num = (1 << (ch-'a')) + num;
        }
        return num;
    }
    
    int countSetBits(int num) {
        int ans = 0;
        for (int i = 0 ; i < 32 ; i++) {
            if (num & 1 << i)
                ans++;
        }
        return ans;
    }
    
    int ans = 0;
    
    void solve(vector<int>& nums, int idx, int prev) {
        if (idx == nums.size())
            return;
        if (nums[idx] & prev) {
            solve(nums, idx+1, prev);
        }
        else {
            int next = nums[idx] & prev;
            ans = max(ans, countSetBits(next));
            solve(nums, idx+1, next);
        }
    }
    
    int maxLength(vector<string>& strs) {
        vector<int> nums;
        for (auto str : strs) {
            int num = convert(str);
            if (num)
                nums.push_back(num);
        }
        solve(nums, 0, 0);
        return ans;
    }
};