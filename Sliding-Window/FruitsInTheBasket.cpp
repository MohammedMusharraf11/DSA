//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int r = 0;
        int l = 0;
        int maxLen = 0;
        int k = 2;
        map<int,int> mpp;
        
        while(r<arr.size()){
            
            mpp[arr[r]]++;
            if(mpp.size()>k){
                
                while(mpp.size()>k){
                    
                    mpp[arr[l]]--;
                    if(mpp[arr[l]]==0){
                        mpp.erase(arr[l]);
                    }
                    l++;
                }
            }
            if(mpp.size()<=k){
                maxLen = max(maxLen,r-l+1);
                
            }
            r++;
            
        }
      return maxLen;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalElements(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
