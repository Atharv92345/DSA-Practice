//Leetcode 739 - Daily Temperatures
//https://leetcode.com/problems/daily-temperatures/description/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> days;
        for(int i = 0; i < temperatures.size(); i++){
            while(!days.empty() && temperatures[days.top()] < temperatures[i]){
                result[days.top()] = i - days.top();
                days.pop();
            }
            days.push(i);
        }
        return result;
    }
};
