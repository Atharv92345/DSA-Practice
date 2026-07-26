//Leetcode 167 - Two Sum II - Input Array Is Sorted
//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int l = 0;
        int r = numbers.size()-1;
        while(l < r){
            if(numbers[r] + numbers[l] == target){
                ans.push_back(l+1);
                ans.push_back(r+1);
                break;
            }else if(numbers[r] + numbers[l] > target){
                r--;
            }else{
                l++;
            }
        }
        return ans;
    }
};
