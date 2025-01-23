class Solution {
public:
    int characterReplacement(string s, int k) {
    int n=s.size();
    unordered_set<char>st;
    for(auto it:s){
       st.insert(it); 
    }
    int l,r,maxlen=0;
    for(auto ch:st){
       l=0;
       r=0;
       int notsame=0;
        while(r<n){
            if(s[r]!=ch) notsame++;
        if(notsame>k){
            if(s[l]!=ch) notsame--;
            l++;
        }
        // increase r and check for maxlen
        maxlen=max(maxlen,r-l+1);
        r++;
        }
    }
    return maxlen;
    }
};
