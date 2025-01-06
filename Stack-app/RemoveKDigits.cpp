#include <string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string st; // Use a string as a stack
        for (char digit : num) {
            // Remove digits from the stack while the current digit is smaller
            // than the top of the stack and we still have digits to remove
            while (!st.empty() && k > 0 && st.back() > digit) {
                st.pop_back();
                k--;
            }
            // Add the current digit to the stack
            if (!st.empty() || digit != '0') {
                st.push_back(digit); // Avoid leading zeros
            }
        }

        // Remove remaining digits from the end if `k > 0`
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        // If the stack is empty, return "0"
        return st.empty() ? "0" : st;
    }
};
