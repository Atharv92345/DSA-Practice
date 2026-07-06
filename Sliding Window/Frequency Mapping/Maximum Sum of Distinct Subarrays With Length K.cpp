//Leetcode 2461 - Maximum Sum of Distinct Subarrays With Length K
//https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        int j = 0;
        unordered_map<int, int> mp;
        long long temp = 0;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
            temp += nums[i];
            if((i-j+1) == k){
                if(k == mp.size()){
                    sum = max(temp, sum);
                }
                temp-= nums[j];
                mp[nums[j]]--;
                if(mp[nums[j]] == 0){
                    mp.erase(nums[j]);
                }
                j++;
            }
        }
        return sum;
    }
};
