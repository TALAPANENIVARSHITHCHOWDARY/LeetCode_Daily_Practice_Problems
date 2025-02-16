# LeetCode 1718: Construct the Lexicographically Largest Valid Sequence

## Problem Statement
You are given an integer `n` (1 <= n <= 20). Your task is to construct a **distanced sequence** of length `2 * n - 1` that satisfies the following conditions:

1. Each integer from `1` to `n` appears exactly once or twice.
2. If an integer `x` appears twice, the second occurrence must be `x` indices after the first occurrence.
3. The sequence must be **lexicographically largest**.

Return a valid sequence or an empty array if no valid sequence exists.

## Approach
The solution is implemented using **backtracking** to explore all possible sequences while ensuring that they are valid and lexicographically largest.

### Algorithm:
1. Initialize a result array of size `2 * n - 1` filled with zeros.
2. Use a boolean array `used` to keep track of numbers already placed.
3. Start backtracking from position `0`:
   - Try placing numbers from `n` down to `1` (ensuring lexicographical order).
   - If the number is `x > 1`, check if position `pos + x` is available.
   - If valid, place the number and recursively continue.
   - If a valid sequence is found, return `true`.
   - Otherwise, backtrack and remove the number.
4. Return the constructed sequence.

## Implementation
```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backtrack(vector<int>& result, vector<bool>& used, int pos, int n) {
        if (pos >= result.size()) return true;
        if (result[pos] != 0) return backtrack(result, used, pos + 1, n);
        
        for (int i = n; i >= 1; i--) {
            if (used[i]) continue;
            if (i != 1 && (pos + i >= result.size() || result[pos + i] != 0)) continue;
            
            used[i] = true;
            result[pos] = i;
            if (i != 1) result[pos + i] = i;
            
            if (backtrack(result, used, pos + 1, n)) return true;
            
            used[i] = false;
            result[pos] = 0;
            if (i != 1) result[pos + i] = 0;
        }
        return false;
    }
    
    vector<int> constructDistancedSequence(int n) {
        int size = 2 * n - 1;
        vector<int> result(size);
        vector<bool> used(n + 1);
        backtrack(result, used, 0, n);
        return result;
    }
};
```

## Complexity Analysis
- **Time Complexity:** `O(n!)` in the worst case since it tries different placements through backtracking.
- **Space Complexity:** `O(n)`, where `n` is the maximum depth of the recursion stack and auxiliary arrays used.

## Example
### Input:
```cpp
n = 3
```

### Output:
```cpp
[3, 1, 2, 3, 2]
```

## Edge Cases Considered
- `n = 1`, smallest input case.
- `n = 20`, largest input case.
- Cases where placement is not straightforward (e.g., requiring backtracking).

## Summary
This solution effectively leverages backtracking to construct the lexicographically largest valid sequence by prioritizing higher numbers first while ensuring constraints are met.

