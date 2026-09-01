//Leetcode 322 - Coin Change
//https://leetcode.com/problems/coin-change/description/

class Solution {
public:
    int mincoin(vector<int>& coins, int i, int amount, vector<vector<int>> &dp){
        if(amount == 0){
            return 0;
        }
        if(i == 0){
           if(amount % coins[0] == 0){
               return amount/coins[0];
           }
            return 1e9;
        }
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        int reject = mincoin(coins, i-1, amount, dp);
        int accept = 1e9;
        if(coins[i] <= amount){
            accept = 1 + mincoin(coins, i, amount-coins[i], dp);
        }
        return dp[i][amount] = min(accept,reject);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int i = coins.size()-1;
        vector<vector<int>> dp(coins.size(), vector<int> (amount+1, -1));
        int ans = mincoin(coins, i, amount, dp);
        if(ans >= 1e9){
            return -1;
        }
        return ans;
    }
};
