//Leetcode - 84
//https://leetcode.com/problems/largest-rectangle-in-histogram/description/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int m = 0;
        for(int i = 0; i <= heights.size(); i++){
            int c;
            if(i == heights.size()){
                c = 0;
            }else{
                c = heights[i];
            }
            while(!s.empty() && heights[s.top()] > c){
                int h = heights[s.top()];
                s.pop();
                if(!s.empty()){
                     int w = i - s.top() -1;
                     m = max(w * h, m);
                }else{
                     m = max(i * h, m);
                }
            }
            s.push(i);
        }
        return m;
    }
};
