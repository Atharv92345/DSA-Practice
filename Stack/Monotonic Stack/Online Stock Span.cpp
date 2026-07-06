//Leetcode 901 - Online Stock Span
//https://leetcode.com/problems/online-stock-span/description/

class StockSpanner {
public:
    stack<pair<int, int>> s;
    
    int next(int price) {
        int c = 1;
        if(s.empty()){
            s.push({price, c});
        }else{
            while(!s.empty() && price >= s.top().first){
                c+= s.top().second;
                s.pop();
            }
            s.push({price, c});
        }
         return c;
    }
};
