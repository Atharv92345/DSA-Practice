//Leetcode 1143 - Longest Common Subsequence
//https://leetcode.com/problems/longest-common-subsequence/description/

class Solution {
public:
    int count(string &text1, string &text2, int i, int j, vector<vector<int>>& dp){
        if(i == -1 || j == -1){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int accept = 0;
        if(text1[i] == text2[j]){
            return 1 + count(text1, text2, i-1, j-1, dp);
        }
        return dp[i][j] =  max(count(text1, text2, i-1, j, dp), count(text1, text2, i, j-1, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        if(text1 == text2){
            return text1.length();
        }
        int i = text1.length()-1;
        int j = text2.length()-1;
        vector<vector<int>> dp (text1.length(), vector<int> (text2.length(), -1));
        return count(text1, text2, i, j, dp);
    }
};
