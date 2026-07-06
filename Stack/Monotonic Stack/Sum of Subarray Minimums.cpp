//Leetcode 907 - Sum of Subarray Minimums
//https://leetcode.com/problems/sum-of-subarray-minimums/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long MOD = 1e9 + 7;
        stack<int> right;
        stack<int> left;
        vector<int> d1;
        int d2[arr.size()];
        int boundary = -1;
        for(int i = 0; i < arr.size(); i++){
           while(!right.empty() && arr[right.top()] > arr[i]){
             right.pop();
           }
           if(!right.empty()){
            boundary = right.top();
           }else{
            boundary = -1;
           }
           d1.push_back(i-boundary);
           right.push(i);
           
        }
        boundary = arr.size();
        for(int i = arr.size()-1; i >= 0; i--){
           while(!left.empty() && arr[left.top()] >= arr[i]){
             left.pop();
           }
           if(!left.empty()){
            boundary = left.top();
           }else{
            boundary = arr.size();
           }
           d2[i] = boundary - i;
           left.push(i); 
        }
        long long sum = 0;
        for(int i = 0; i < d1.size(); i++){
            long long contri = (1LL * d1[i] * d2[i]) % MOD;
            contri = (contri * arr[i]) % MOD;
            sum = (sum + contri) % MOD;
        }
        return sum;
    }
};
