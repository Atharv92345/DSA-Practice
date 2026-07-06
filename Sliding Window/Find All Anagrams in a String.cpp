//Leetcode 438 - Find All Anagrams in a String
//https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> anagram;
        if(s.length() < p.length()){
            return anagram;
        }
        vector<int> freq1 (26, 0), freq2(26, 0);
        int k = p.length();
        for(int i = 0; i < p.length(); i++){
            freq1[p[i] - 'a']++;
        }
        for(int i = 0; i < s.length(); i++){
            freq2[s[i] - 'a']++;
            if(i >= k){
                freq2[s[i-k] - 'a']--;
            }
            if(freq1 == freq2) anagram.push_back(i-k+1);
        }
        return anagram;
    }
};
