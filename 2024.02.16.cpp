#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    
    struct Node {
        int num;
        int cnt;
        
        bool operator()(Node& a, Node& b) {
            return a.cnt > b.cnt;
        }
    };
    
    int findLeastNumOfUniqueInts(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        priority_queue<Node, vector<Node>, Node> minheap;
        int idx = 0;
        int num = 0;
        int cnt = 0;
        while (idx < nums.size()) {
            cnt = 0;
            num = nums[idx];
            while (idx < nums.size() && nums[idx] == num) {
                idx++;
                cnt++;
            }
            minheap.push({num, cnt});
        }
        while (k--) {
            Node node = minheap.top();
            minheap.pop();
            if (node.cnt > 1)
                minheap.push({node.num, node.cnt-1});
        }
        return minheap.size();
    }
};