//Leetcode 904 - Fruit Into Baskets
//https://leetcode.com/problems/fruit-into-baskets/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int j = 0;
        int t = 2;
        int count = 0;
        unordered_map<int, int> hash;
        for(int i = 0; i < fruits.size(); i++){
            hash[fruits[i]]++;
            while(hash.size() > t){
               hash[fruits[j]]--;
               if(hash[fruits[j]] == 0){
                  hash.erase(fruits[j]);
               }
               j++;
            }
            count = max(count, i-j+1);
        } 
        return count;
    }
};
