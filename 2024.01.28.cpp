#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // Adding columns wise
        for (int i = 0 ; i < rows ; i++) {
            for (int j = 1 ; j < cols ; j++) {
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
        // Adding rows wise
        for (int j = 0 ; j < cols ; j++) {
            for (int i = 1 ; i < rows ; i++) {
                matrix[i][j] += matrix[i-1][j];
            }
        }
        
        
        // submatrixSum[i,j,x,y] = sum[x][j] - sum[i-1][y] - sum[x][j-1] + sum[i-1][j-1]
        int ans = 0;
        for (int i = 0 ; i < rows ; i++) {
            for (int j = 0 ; j < cols ; j++) {
                for (int x = i ; x < rows ; x++) {
                    for (int y = j ; y < cols ; y++) {
                        int matrixSum = matrix[x][y];
                        if (i-1 >= 0)
                            matrixSum -= matrix[i-1][y];
                        if (j-1 >= 0)
                            matrixSum -= matrix[x][j-1];
                        if (i-1 >= 0 && j-1 >= 0)
                            matrixSum += matrix[i-1][j-1];
                        if (matrixSum == target)
                            ans++;
                    }
                }
            }
        }
        return ans;
    }
};