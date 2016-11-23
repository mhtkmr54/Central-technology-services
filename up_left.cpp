
int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified

            int m = obstacleGrid.size(), n = obstacleGrid[0].size();
            int uniquePaths[m + 1][n + 1];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    uniquePaths[i][j] = 0;
                    if (obstacleGrid[i][j]) continue;
                    if (i == 0 && j == 0) uniquePaths[i][j] = 1;
                    if (i > 0) uniquePaths[i][j] += uniquePaths[i-1][j];
                    if (j > 0) uniquePaths[i][j] += uniquePaths[i][j-1];
                }
            }
            return uniquePaths[m-1][n-1];
        
}

class Solution {
    public:
        int minPathSum(vector<vector<int> > &grid) {
            if (grid.size() == 0) return 0;
            int m = grid.size(), n = grid[0].size();
            int minPath[m + 1][n + 1];
            for (int i = 0; i < m; i++) {
                minPath[i][0] = grid[i][0]; 
                if (i > 0) minPath[i][0] += minPath[i - 1][0];
                for (int j = 1; j < n; j++) {
                    minPath[i][j] = grid[i][j] + minPath[i][j-1];
                    if (i > 0) minPath[i][j] = min(minPath[i][j], grid[i][j] + minPath[i-1][j]);
                }
            }
            return minPath[m-1][n-1];
        }
};