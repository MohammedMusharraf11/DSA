vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> nse(A.size(),-1);
    stack<int> st;
    int n = A.size();
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()>=A[i]){
            st.pop();
        }
        
        nse[i] = st.empty()?-1:st.top();
        st.push(A[i]);
    
}
    return nse;
}
