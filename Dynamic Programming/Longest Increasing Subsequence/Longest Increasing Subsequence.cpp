//Leetcode 300 - Longest Increasing Subsequence
//https://leetcode.com/problems/longest-increasing-subsequence/description/

class Solution {
public:
    int count(vector<int>& nums, vector<vector<int>>& dp, int i, int j){
        if(j >= nums.size()){
            return 0;
        }
        if(dp[i+1][j] != -1){
            return dp[i+1][j];
        }
        int reject = count(nums, dp, i, j+1);
        int accept = 0;
        if(i==-1 || nums[j] > nums[i]){
            accept = 1 + count(nums, dp, j, j+1);
        }
        return dp[i+1][j] = max(accept, reject);
    }

    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 1){
            return 1;
        }
        vector<vector<int>> dp (nums.size()+1, vector<int>(nums.size(), -1));
        int i = -1;
        int j = 0;
        return count(nums, dp, i, j);
    }
};
