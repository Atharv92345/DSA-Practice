//Leetcode 518 - Coin Change II
//https://leetcode.com/problems/coin-change-ii/description/

class Solution {
public:
    int count(vector<int>& coins, int i, vector<vector<int>>& dp, int amount){
         if(i == 0){
            if(amount % coins[0] == 0){
                return 1;
            }
            return 0;
         }
         if(dp[i][amount] != -1){
            return dp[i][amount];
         }
         int accept = 0;
         if(amount >= coins[i]){
            accept = count(coins, i, dp, amount-coins[i]);
         }
         int reject = count(coins, i-1, dp, amount);
         return dp[i][amount] = accept+reject;
    }
   
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp (coins.size(), vector<int> (amount+1, -1));
        int i = coins.size()-1;
        return count(coins, i, dp, amount);
    }
};
