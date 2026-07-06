//Leetcode 1004 - Max Consecutive Ones III'
//https://leetcode.com/problems/max-consecutive-ones-iii/description/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int m = 0;
        int j = 0;
        int z = -1;
        int freq = 0;
        int non = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 1){
                non++;
            }
            while(non > k){
                if(nums[j] != 1){
                    non--;
                }
                j++;
            }
            freq = i - j + 1;
            m = max(freq, m);
        }
        return m;
    }
};
