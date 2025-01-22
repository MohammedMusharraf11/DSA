//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        
        
        int top = 0;
        int down = mat.size()-1;
        
        while(top<down){
            
            if(mat[top][down]==1){
                top++;
            }else if(mat[down][top]==1){
                down--;
            }else{
                top++;
                down--;
            }
            
            
        }
        
        //top and down both will be pointing celebrity
        
        if(top>down){
            return -1;
        }
        
        for(int i=0;i<mat.size()-1;i++){
            if(top==i){
                continue;
            }
            if(mat[top][i]==0 && mat[i][top]==1){
                continue;
            }else{
                return -1;
            }
        }
        // code here
    
        return 1;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends