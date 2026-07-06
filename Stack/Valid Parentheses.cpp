//Leetcode 20 - Valid Parentheses
//https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {
       stack<int> b;
       for(int i = 0; i < s.size(); i++){
           if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
               b.push(s[i]);
           }else if(!b.empty() && ((b.top() == '(' && s[i] == ')') || (b.top() == '[' && s[i] == ']') || (b.top() == '{' && s[i] == '}'))){
              b.pop();
           }else{
              return false;
           }
       }
       if(b.empty()){
        return true;
       }else{
        return false;
       }
    }
};
