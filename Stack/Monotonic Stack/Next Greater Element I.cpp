//Leetcode 496 - Next Greater Element I
//https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash;
        vector<int> result;
        stack<int> t;
        for(int i = 0; i < nums2.size(); i++){
            if(!t.empty() && t.top() >= nums2[i])
              t.push(nums2[i]);
            while(!t.empty() && t.top() < nums2[i]){
                hash[t.top()] = nums2[i];
                t.pop();
            }
            t.push(nums2[i]);
        }
        for(int i = 0; i < nums1.size(); i++){
             if(hash.contains(nums1[i])){
               result.push_back(hash[nums1[i]]);
             }else{
               result.push_back(-1);
             }
        }
        return result;
    }
};
