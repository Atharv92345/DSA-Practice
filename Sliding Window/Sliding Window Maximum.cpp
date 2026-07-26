//Leetcode 239 - Sliding Window Maximum
//https://leetcode.com/problems/sliding-window-maximum/description/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1){
            return nums;
        }
        vector<int> ans;
        int i = 1;
        int j = k;
        map<int, int> a;
        for(int x = 0; x < k; x++){
            a[nums[x]]++;
        }
        auto it = prev(a.end());
        ans.push_back(it->first);
        if(a[nums[0]] == 1){
            a.erase(nums[0]);
        }else{
            a[nums[0]]--;
        }
        while(j < nums.size()){
            a[nums[j]]++;
            it = prev(a.end());
            ans.push_back(it -> first);
            if(a[nums[i]] == 1){
                a.erase(nums[i]);
            }else{
                a[nums[i]]--;
            }
            i++;
            j++;
        }
        return ans;
    }
};
