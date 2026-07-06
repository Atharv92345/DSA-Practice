//Leetcode 890 - Find and Replace Pattern
//https://leetcode.com/problems/find-and-replace-pattern/description/

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> end;
        bool check = 1;
        for(int i = 0; i < words.size(); i++){
            unordered_map<char, char> hash, hash2;
            for(int j = 0; j < pattern.size(); j++){
                if(hash.count(words[i][j]) && hash[words[i][j]] != pattern[j]){
                     check = 0;
                     break;
                }
                if(hash2.count(pattern[j]) && hash2[pattern[j]] != words[i][j]){
                     check = 0;
                     break;
                }
                hash[words[i][j]] = pattern[j];
                hash2[pattern[j]] = words[i][j];
            }
            if(check == 1){
                end.push_back(words[i]);
            }
            check = 1;
        }
        return end;
    }
};
