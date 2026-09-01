//Leetcode 494 - Target Sum
//https://leetcode.com/problems/target-sum/description/

class Solution {
public:
    int count(int find, int i, vector<int>& nums, vector<vector<int>> &dp){
        if(i == 0){
            if (find == nums[0] && find == 0){
                return 2;
            }
            if(find == nums[0] || find == 0){
                return 1;
            }
            return 0;
        }
        if(dp[i][find] != -1){
            return dp[i][find];
        }
        int reject = count(find, i-1, nums, dp);
        int accept = 0;
        if(nums[i] <= find){
           accept = count(find - nums[i], i-1, nums, dp);
        }
        return dp[i][find] = reject+accept;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
       int c = 0;
       int sum = 0;
       for(int i = 0; i < nums.size(); i++){
         sum += nums[i];
       }
       int diff = sum - target;
       if(sum < target || diff % 2 != 0){
         return 0;
       }
       int find = diff/2;
       int i = nums.size()-1;
       vector<vector<int>> dp(nums.size(), vector<int>(find+1, -1));  
       return count(find, i, nums, dp);
    }
};
