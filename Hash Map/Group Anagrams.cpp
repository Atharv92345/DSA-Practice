//Leetcode - 49
//https://leetcode.com/problems/group-anagrams/description/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string, vector<string>> hash;
       vector<vector<string>> end;
       for(string s: strs){
           vector<int> freq(26,0);
           for(char c: s){
             freq[c - 'a']++;
           }
           string key = "";
           for(int i = 0; i < 26; i++){
               key += to_string(freq[i]) + "#";
           }
           hash[key].push_back(s);   
       }
       for(auto &p: hash){
              end.push_back(p.second);
       }
       return end;
    }
};
