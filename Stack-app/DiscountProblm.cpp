class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> sp(prices.size(),0);
        stack<int> st;
        for(int i = prices.size()-1 ;i>=0;i--){
            while(!st.empty() && st.top()>prices[i]){
                st.pop();
            }
            if(st.empty()){
                sp[i] = prices[i];
            }else{
                sp[i] = prices[i] - st.top();
            }
            st.push(prices[i]);
        }
        return sp;
    }
};
