//Leetcode 63 - Unique Paths II
//https://leetcode.com/problems/unique-paths-ii/description/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size()));
        if(obstacleGrid[0][0] == 0){
            dp[0][0] = 1;
        }else{
            dp[0][0] = 0;
        }
        for(int i = 1; i < obstacleGrid.size(); i++){
            if(obstacleGrid[i][0] == 0){
                dp[i][0] += dp[i-1][0];
            } 
        }
        for(int j = 1; j < obstacleGrid[0].size(); j++){
            if(obstacleGrid[0][j] == 0){
                dp[0][j] += dp[0][j-1];
            }
        }
        for(int i = 1; i < obstacleGrid.size(); i++){
            for(int j = 1; j < obstacleGrid[0].size(); j++){
                if(obstacleGrid[i][j] == 0){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};
