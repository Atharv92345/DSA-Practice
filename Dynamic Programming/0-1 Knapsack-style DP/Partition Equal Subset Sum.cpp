//Leetcode 416 - Partition Equal Subset Sum
//https://leetcode.com/problems/partition-equal-subset-sum/description/

class Solution {
public:
    bool choice(int target, vector<vector<int>>&dp, int i, vector<int>&nums){
        if(i == -1){
            return false;
        }
        if(dp[i][target] != -1){
            return dp[i][target];
        }
        if(target == 0){
            return true;
        }
        bool reject = choice(target, dp, i-1, nums);
        bool select = false;
        if(nums[i] <= target){
            select = choice(target-nums[i], dp, i-1, nums);  
        }
        return dp[i][target] = (reject || select);      
    }
   
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        if(sum%2 != 0){
            return false;
        }
        int target = sum/2;
        vector<vector<int>>dp (nums.size(), vector<int>(target+1, -1));
        return choice(target, dp, nums.size()-1, nums);
    }
};
