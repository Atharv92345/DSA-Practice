//Leetcode 3 - Longest Substring Without Repeating Characters
//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int maxL = 0;
       int j = 0;
       unordered_map<char, int> mp;
       for(int i = 0; i < s.length(); i++){
            mp[s[i]]++;
            while((i-j+1) != mp.size()){
                mp[s[j]]--;
                if(mp[s[j]] == 0){
                    mp.erase(s[j]);
                }
                j++;
            }
            int b = mp.size();
            maxL = max(maxL, b);
       }
       return maxL;
    }
};
