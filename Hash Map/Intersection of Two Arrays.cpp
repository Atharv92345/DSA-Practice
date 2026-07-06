//Leetcode 349 - Intersection of Two Arrays
//https://leetcode.com/problems/intersection-of-two-arrays/description/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> check(nums1.begin(), nums1.end());
        vector<int> final;
        for(int i : nums2){
            if(check.count(i)){
                final.push_back(i);
                check.erase(i);
            }
        }
        return final;
    }
};
