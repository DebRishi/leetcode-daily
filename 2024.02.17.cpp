#include <iostream>
#include <queue>
using namespace std;

class Solution2 {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> minheap;
        for (int idx = 0; idx < heights.size()-1; idx++) {
            int gap = heights[idx+1] - heights[idx];
            if (gap <= 0)
                continue;
            minheap.push(gap);
            if (minheap.size() > ladders) {
                bricks -= minheap.top();
                minheap.pop();
            }
            if (bricks < 0)
                return idx;
        }
        return heights.size()-1;
    }
};

class Solution1 {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> minheap;
        int sum = 0;
        int idx = 0;
        while (idx+1 < heights.size()) {
            int dif = heights[idx+1] - heights[idx];
            if (dif <= 0)
                idx++;
            else {
                minheap.push(dif);
                if (minheap.size() > ladders) {
                    sum += minheap.top();
                    minheap.pop();
                }
                if (sum <= bricks)
                    idx++;
                else
                    return idx;
            }
        }
        return idx;
    }
};