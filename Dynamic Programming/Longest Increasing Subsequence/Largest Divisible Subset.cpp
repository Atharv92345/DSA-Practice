//Leetcode 368 - Largest Divisible Subset
//https://leetcode.com/problems/largest-divisible-subset/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() <= 1){
            return nums;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        int ma = 1;
        int me = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            if(dp[i] > ma){
                ma = dp[i];
                me = i;
            }
        }
        vector<int> ans;
        int last = nums[me];
        for(int i = me; i >= 0; i--){
            if((dp[i] == ma && last%nums[i] == 0)){
                ans.push_back(nums[i]);
                last = nums[i];
                ma--;
            }
        }
        return ans;
    }
};
