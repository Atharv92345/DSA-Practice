//Leetcode 14 - Longest Common Prefix
//https://leetcode.com/problems/longest-common-prefix/description/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        int ms = strs[0].length();
        for(int i = 1; i < strs.size(); i++){
           if(strs[i].length() < ms){
             ms = strs[i].length();
             ans.resize(ms);
           }
           for(int j = 0; j < strs[i].length() && j < ans.length(); j++){
              if(strs[i][j] != ans[j]){
                ans.resize(j);
              }
           }
        }
        return ans;
    }
};
