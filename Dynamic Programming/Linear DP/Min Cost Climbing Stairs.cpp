//Leetcode 746 - Min Cost Climbing Stairs
//https://leetcode.com/problems/min-cost-climbing-stairs/description/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        if(cost.size() == 2){
            return min(dp[0], dp[1]);
        }
        for(int i = 2; i < cost.size(); i++){
            if(i != cost.size()-1){
                dp[i] = min((cost[i] + dp[i-2]), dp[i-1] + cost[i]);
            }else{
                dp[i] = min(dp[i-1], dp[i-2] + cost[i]);
            }
        }
        return dp[cost.size() - 1];
    }
};
