# 1092. Shortest Common Supersequence

## Problem Statement
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If multiple answers exist, you may return any of them.

A **subsequence** of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

### Constraints:
- 1 <= str1.length, str2.length <= 1000
- str1 and str2 consist of lowercase English letters.

## Approach

1. **Longest Common Subsequence (LCS) Computation:**
   - Use **dynamic programming** to find the LCS of both strings.
   - Store actual LCS string rather than just its length.

2. **Building the Supersequence:**
   - Traverse both strings and the LCS simultaneously.
   - For characters not in the LCS, add them to the result.
   - For characters in the LCS, add them only once.
   - Track positions in each string during traversal.

3. **Handling Trailing Characters:**
   - After traversal, add any remaining characters from both strings.

## Code

\\\cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length(), n = str2.length();
        vector<vector<string>> dp(m + 1, vector<string>(n + 1, ""));
        
        // Build LCS string matrix
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = dp[i-1][j-1] + str1[i-1];
                else
                    dp[i][j] = dp[i-1][j].length() > dp[i][j-1].length() ? 
                              dp[i-1][j] : dp[i][j-1];
            }
        }
        
        // Construct supersequence
        string result;
        int i = 0, j = 0;
        for(char c : dp[m][n]) {
            while(i < m && str1[i] != c)
                result += str1[i++];
            while(j < n && str2[j] != c)
                result += str2[j++];
            result += c;
            i++; j++;
        }
        
        // Add remaining characters
        return result + str1.substr(i) + str2.substr(j);
    }
};
\\\

## Example

### Input:
\\\cpp
str1 = "abac"
str2 = "cab"
\\\

### Output:
\\\cpp
"cabac"
\\\

### Explanation:
- LCS of "abac" and "cab" is "ab"
- The shortest common supersequence merges both strings, including the common part "ab" just once

## Complexity Analysis

**Time Complexity:** O(m*n), where m and n are lengths of input strings.

**Space Complexity:** O(m*n), for the dp table storing LCS strings.

---

### Notes
- The key insight is that characters in the **LCS appear exactly once** in the result.
- Characters not in LCS must be included in their original order from both strings.
- This approach is more efficient than trying all possible combinations.

Happy Coding! 
