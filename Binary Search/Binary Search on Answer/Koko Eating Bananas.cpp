//Leetcode 875 - Koko Eating Bananas
//https://leetcode.com/problems/koko-eating-bananas/description/

class Solution {
public:
    bool traverse(long long mid, vector<int>& piles, int hours){
        long long c = 0;
        for(int i = 0; i < piles.size(); i++){
            if(piles[i]%mid == 0){
                c += piles[i]/mid;
            }else{
                 c += (piles[i]/mid) + 1;
            }
        }
        if(c > hours){
            return false;
        }else{
            return true;
        }
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long ma = 0;
        for(int i = 0; i < piles.size(); i++){
            if(ma < piles[i]){
                ma = piles[i];
            }
        }
        long long high = ma;
        long long low = 1;
        while(high >= low){
            long long mid = (low + high)/2;
            bool check = traverse(mid, piles, h);
            if(check == false){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return high+1;
    }
};
