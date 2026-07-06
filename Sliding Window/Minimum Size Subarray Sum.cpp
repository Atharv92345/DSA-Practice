//Leetcode 209 - Minimum Size Subarray Sum
//https://leetcode.com/problems/minimum-size-subarray-sum/description/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j = 0;
        int sum = 0;
        int f = nums.size()+1;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            while(sum >= target){
                f = min(i-j+1, f);
                sum -= nums[j];
                j++;
            }
        }
        if(f == nums.size() + 1){
            f = 0;
        }
        return f;
    }
};
