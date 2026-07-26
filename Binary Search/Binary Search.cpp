//Leetcode 704 - Binary Search
//https://leetcode.com/problems/binary-search/

class Solution {
public:
    int findMid(int start, int end){
         return start + (end - start)/2;
    }

    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while(start <= end){
            int mid = findMid(start, end);
            if(nums[mid] == target){
               return mid;
            }else if(nums[mid] > target){
               end = mid - 1;  
            }else{
               start = mid + 1;
            }
        }
       return -1;
    }
};
