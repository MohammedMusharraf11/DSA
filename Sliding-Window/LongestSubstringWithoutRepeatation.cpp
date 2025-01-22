class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Create a hash table to store the last seen index of characters (ASCII range)
        vector<int> hash(255, -1);
        int n = s.size();  // Length of the input string
        int l = 0;         // Left pointer of the sliding window
        int r = 0;         // Right pointer of the sliding window
        int maxLen = 0;    // Variable to store the length of the longest substring
        int len;           // Variable to store the current window length

        // Iterate through the string using the right pointer
        while (r < n) {
            // If the character at the right pointer is seen and is within the current window
            if (hash[s[r]] != -1 && hash[s[r]] >= l) {
                // Move the left pointer to exclude the last seen occurrence of s[r]
                l = hash[s[r]] + 1;
            }

            // Update the hash table with the current index of s[r]
            hash[s[r]] = r;

            // Calculate the current window length and update the maximum length
            len = r - l + 1;
            maxLen = max(len, maxLen);

            // Move the right pointer to expand the window
            r++;
        }

        return maxLen;  // Return the length of the longest substring
    }
};

/*
Algorithm:
1. Initialize a hash table to store the last seen index of each character. Set its values to -1.
2. Use two pointers (l for the left boundary and r for the right boundary) to maintain a sliding window.
3. Traverse the string using the right pointer (r):
   a. If the character s[r] is already seen and its last index is greater than or equal to l, 
      move the left pointer (l) to exclude the last seen occurrence of s[r] (i.e., l = hash[s[r]] + 1).
   b. Update the hash table with the current index of s[r].
   c. Calculate the current window length as (r - l + 1) and update the maximum length (maxLen).
4. Increment the right pointer to expand the window.
5. Return the maximum length of the substring without repeating characters.
*/
