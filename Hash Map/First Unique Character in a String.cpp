//Leetcode 387 - First Unique Character in a String
//https://leetcode.com/problems/first-unique-character-in-a-string/description/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hash;
        for(char c : s){
            hash[c]++;
        }
        for(int i = 0; i < s.size(); i++){
            if(hash[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};
