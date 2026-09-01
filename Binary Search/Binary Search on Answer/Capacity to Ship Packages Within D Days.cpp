//Leetcode 1011 - Capacity to Ship Packages Within D Days
//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

class Solution {
public:
    bool check(vector<int>& weights, int days, int mid){
        int count = 0;
        int d2 = 1;
        for(int i = 0; i < weights.size(); i++){
            if(count + weights[i] > mid){
                d2++;
                count = weights[i];
            }else{
                count += weights[i];
            }
        }
        if(d2 > days){
            return false;
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int ma = 0;
        for(int i = 0; i < weights.size(); i++){
            sum += weights[i];
            ma = max(ma, weights[i]);
        }
        int mid = 0;
        int accept = 0;
        while(ma <= sum){
            mid = (ma + sum)/2;
            bool c = check(weights, days, mid);
            if(c == false){
                ma = mid+1;
            }else{
                accept = mid;
                sum = mid-1;
            }
        } 
        return accept;
    }
};
