//Leetcode 11 - Container With Most Water
//https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int ma = 0;
        while(left < right){
            int temp = min(height[left], height[right]);
            int c = right - left;
            temp *= c;
            ma = max(temp, ma);
            if(height[left] > height[right]){
                right--;
            }else{
                left++;
            }
        }
        return ma;
    }
};
