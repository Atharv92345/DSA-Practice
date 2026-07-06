//Leetcode 503 - Next Greater Element II
//https://leetcode.com/problems/next-greater-element-ii/description/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size(), -1);
        stack<int> t;
        for(int i = 0; i < 2 * nums.size() - 1; i++){
            while(!t.empty() && nums[t.top()] < nums[i % nums.size()]){
                result[t.top()] = nums[i % nums.size()];
                t.pop();
            }
            if(i < nums.size()){
              t.push(i);
            }
        }
        return result;
    }
};
