class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> nge(nums.size(),-1);//Space Complexity --> N
        stack<int> st;
        int n = nums.size();
        for(int i= 2*n-1;i>=0;i--){  //TC --> 2N
            while(!st.empty() && st.top()<=nums[i%n]){ //TC --> 2N
                st.pop();
            }
            if(i<n){
                nge[i] = st.empty()?-1:st.top();
            }
            st.push(nums[i%n]); //Space Complexity --> 2N
        }
        return nge;
        //Total SC:3N TC:4N

    }
};

// Leetcode: https://leetcode.com/problems/next-greater-element-ii
// Youtube: https://www.youtube.com/watch?v=7PrncD7v9YQ
