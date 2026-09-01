//Leetcode 62 - Unique Paths
//https://leetcode.com/problems/unique-paths/description/

class Solution {
public:
    int uniquePaths(int m, int n) {
        double path = 1;
        for(int i = 1; i <= (m-1)+(n-1); i++){
            if(i > m-1){
                path *= (1.0*i/(i-(m-1)*1.0));
            }
        }
        return round(path);
    }
};
