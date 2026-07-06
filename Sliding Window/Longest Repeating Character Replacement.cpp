//Leetcode 424 - Longest Repeating Character Replacement
//https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:
    int characterReplacement(string s, int k) {
       int size = 0;
       int j = 0;
       int maxfreq = 0;
       vector<int> freq(26,0);
       for(int i = 0; i < s.size(); i++){
           freq[s[i] - 'A']++;
           maxfreq = max(freq[s[i] - 'A'], maxfreq);
           while((i - j + 1) - maxfreq > k){
               freq[s[j] - 'A']--;
               j++;
           } 
           size = max(size, (i-j+1));
       }
       return size;
    }
};
