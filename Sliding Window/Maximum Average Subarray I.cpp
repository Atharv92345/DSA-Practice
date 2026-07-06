//Leetcode 643 - Maximum Average Subarray I
//https://leetcode.com/problems/maximum-average-subarray-i/description/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for(int i = 0; i < k; i++){
             sum += nums[i];
        }
        double sumMax = sum;
        for(int i = k; i < nums.size(); i++){
             sum = sum + nums[i] - nums[i-k];
             sumMax = max(sumMax, sum);
        }
        return sumMax/k;
    }
};
