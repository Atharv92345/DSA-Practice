//Leetcode 205 - Isomorphic Strings
//https://leetcode.com/problems/isomorphic-strings/description/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
       unordered_map<char, char> hash, hash2;
       for(int i = 0; i < s.size(); i++){
           if(hash.count(s[i]) && hash[s[i]] != t[i]){
                return false;
           }
           if(hash2.count(t[i]) && hash2[t[i]] != s[i]){
                return false;
           }
           hash[s[i]] = t[i];
           hash2[t[i]] = s[i];
       }
       return true;
    }
};
