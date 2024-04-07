#include <iostream>
using namespace std;

class Solution {
public:
    
    int MOD = 1e9+7;
    vector<vector<vector<int>>> memo;
    
    long solve(int rows, int cols, int moves, int i, int j) {
        if (i < 0 || j < 0 || i == rows || j == cols)
            return 1;
        if (moves == 0)
            return 0;
        if (memo[i][j][moves] != -1)
            return memo[i][j][moves];
        long ans = 
            solve(rows, cols, moves-1, i-1, j) + 
            solve(rows, cols, moves-1, i, j-1) + 
            solve(rows, cols, moves-1, i+1, j) + 
            solve(rows, cols, moves-1, i, j+1);
        return memo[i][j][moves] = ans % MOD;
    }
    
    int findPaths(int rows, int cols, int moves, int startRow, int startCol) {
        memo = vector<vector<vector<int>>>(rows, vector<vector<int>>(cols, vector<int>(moves+1, -1)));
        return solve(rows, cols, moves, startRow, startCol) % MOD;
    }
};