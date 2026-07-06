//Leetcode 242 - Valid Anagram
//https://leetcode.com/problems/valid-anagram/description/

class Solution {
public:
    bool isAnagram(string s, string t) {
       if(s.size() != t.size()){
         return false;
       }
       unordered_map<char, int> hash;
       for(char c : s){
          hash[c]++;
       }
       for(char c : t){
          hash[c]--;
          if(hash[c] < 0){
              return false;
          }
       }
       return true;
    }
};
