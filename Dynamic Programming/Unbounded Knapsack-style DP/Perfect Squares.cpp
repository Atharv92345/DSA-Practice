//Leetcode 279 - Perfect Squares
//https://leetcode.com/problems/perfect-squares/description/

class Solution {
public:
    int mincount(vector<vector<int>> &dp, int n, vector<int>& b, int i){
        if(n == 0){
            return 0;
        }
        if(i == 0){
            if(n%b[0] == 0){
                return n/b[0];
            }
            return 1e9;
        }
        if(dp[i][n] != -1){
            return dp[i][n];
        }
        int reject = mincount(dp, n, b, i-1);
        int accept = 1e9;
        if(b[i] <= n){
            accept = 1 + mincount(dp, n-b[i], b, i);
        }
        return dp[i][n] = min(accept, reject);
    }
    
    int numSquares(int n) {
        vector<int> b;
        bool a = true;
        int t = 1;
        while(a == 1){
            if(t*t <= n){
                b.push_back(t*t);
            }else{
                a = false;
            }
            t++;
        }
        vector<vector<int>> dp(b.size(), vector<int> (n+1, -1));
        int i = b.size()-1;
        return mincount(dp, n, b, i);
    }
};
