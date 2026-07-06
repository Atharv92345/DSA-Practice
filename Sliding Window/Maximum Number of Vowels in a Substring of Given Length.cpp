//Leetcode 1456 - Maximum Number of Vowels in a Substring of Given Length
//https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/

class Solution {
public:
    int maxVowels(string s, int k) {
        int m = 0;
        int j = 0;
        int c = 0;
        for(int i = 0; i < s.length(); i++){
             if(isVow(s[i])){
                c++;
             }
             while(j <= i-k){
                if(isVow(s[j])){
                c--;
                }
                j++;
             }
             m = max(m, c);
             if(m == k) return m;
        }

        return m;
    }

    bool isVow(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
