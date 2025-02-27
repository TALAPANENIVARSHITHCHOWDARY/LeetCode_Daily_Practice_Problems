# 873. Length of Longest Fibonacci Subsequence

## Problem Statement
Given an integer array `arr`, return the length of the longest Fibonacci-like subsequence of `arr`. If one does not exist, return `0`.

A sequence is **Fibonacci-like** if:
- It has at least `3` elements.
- The sum of the first two elements equals the third element.

### Constraints:
- `3 <= arr.length <= 1000`
- `1 <= arr[i] < 10^9`
- All elements in `arr` are distinct.

## Approach

1. **Index Mapping:**
   - Use a **hash map** to store the index of each element for quick lookups.

2. **Dynamic Programming (`dp`) Approach:**
   - Use a `dp` table where `dp[j][k]` represents the length of the Fibonacci-like sequence ending at indices `j` and `k`.
   - Iterate over all pairs `(j, k)` and check if `arr[k] - arr[j]` exists in the array (before `j`).
   - If such an index `i` exists, update `dp[j][k] = dp[i][j] + 1`.
   - Track the **maximum length** encountered.

3. **Edge Case:**
   - If no sequence of length `>= 3` is found, return `0`.

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; ++i) {
            index[arr[i]] = i;
        }

        vector<vector<int>> dp(n, vector<int>(n, 2));
        int maxLength = 0;

        for (int k = 0; k < n; ++k) {
            for (int j = 0; j < k; ++j) {
                int i = index.count(arr[k] - arr[j]) ? index[arr[k] - arr[j]] : -1;
                if (i >= 0 && i < j) {
                    dp[j][k] = dp[i][j] + 1;
                    maxLength = max(maxLength, dp[j][k]);
                }
            }
        }

        return maxLength >= 3 ? maxLength : 0;
    }
};
```

## Example

### Input:
```cpp
arr = [1,2,3,4,5,6,7,8]
```

### Output:
```cpp
5
```

### Explanation:
The longest Fibonacci-like subsequence is `[1,2,3,5,8]` with length `5`.

## Complexity Analysis

**Time Complexity:** `O(n^2)`, since we iterate over all pairs `(j, k)`.

**Space Complexity:** `O(n^2)`, due to the `dp` table storing results for all pairs.

---

### Notes
- Using a **hash map** for index lookup optimizes checking conditions.
- `dp` efficiently tracks subsequence lengths, avoiding redundant calculations.
- The problem is a variation of **dynamic programming with sequences**.

Happy Coding! 🚀

