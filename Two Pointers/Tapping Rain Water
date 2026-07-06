//Leetcode - 42
//https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
       int c = 0;
       int r = 0;
       int cm = height[0];
       int volume = 0;
       int rm = height[height.size()-1];
       for(int i = 1; i < height.size(); i++){
            if(height[i] < cm){
                c += (cm - height[i]);
            }else{
                volume+= c;
                cm = height[i];
                c = 0;
            }
            if(height[height.size()-1-i] <= rm){
                r += (rm - height[height.size()-1-i]);
            }else{
                volume += r;
                rm = height[height.size()-1-i];
                r = 0;
            }
       }
       return volume;
    }
};
