//Leetcode 217 - Contains Duplicate
//https://leetcode.com/problems/contains-duplicate/description/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int i = 0; i < nums.size(); i++){
            if(seen.count(nums[i])){
                return true;
            }
            seen.insert(nums[i]);
        }
        return false;
    }
};
