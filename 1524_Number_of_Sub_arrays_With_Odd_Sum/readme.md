# 1524. Number of Sub-arrays With Odd Sum

## Problem Statement
Given an array of integers `arr`, count the number of subarrays where the sum of elements is **odd**. Since the answer may be large, return it **modulo** `10^9 + 7`.

### Constraints:
- `1 <= arr.length <= 10^5`
- `1 <= arr[i] <= 100`

## Approach

### 1. **Using Prefix Sum and Counting Odd/Even Prefix Sums**
- Maintain counts of prefix sums that are **even** and **odd**.
- If the prefix sum at any point is **odd**, it means there are `even` prefix sums before it that can form an odd subarray.
- If the prefix sum is **even**, it means there are `odd` prefix sums before it that can form an odd subarray.
- Use a single pass to update and count the valid subarrays efficiently.

## Code Implementation

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int odd = 0, even = 1;  // Initialize with empty subarray (even sum)
        int prefixSum = 0;
        int result = 0;
        
        for(int num : arr) {
            prefixSum += num;
            if(prefixSum % 2 == 0) {
                result = (result + odd) % MOD;
                even++;
            } else {
                result = (result + even) % MOD;
                odd++;
            }
        }
        
        return result;
    }
};
```

## Example

**Input:**
```cpp
arr = [1,3,5]
```

**Output:**
```cpp
4
```

**Explanation:**
- `[1]`, `[1,3,5]`, `[3]`, `[5]` are the subarrays with an odd sum.

## Complexity Analysis

- **Time Complexity:** `O(n)`, since we iterate through `arr` once.
- **Space Complexity:** `O(1)`, since we only use a few integer variables.

## Edge Cases Considered
- Single element arrays
- All even numbers
- Large values for `arr.length` to ensure efficiency.

## Summary
- We use **prefix sum parity tracking** to efficiently count odd subarrays in `O(n)`, avoiding nested loops.
- The key idea is to **track even and odd prefix sums** and use their count to determine valid subarrays.
- Modular arithmetic ensures handling of large results efficiently.

