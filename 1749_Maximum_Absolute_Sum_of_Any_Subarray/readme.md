# 1749. Maximum Absolute Sum of Any Subarray

## Problem Statement
Given an integer array `nums`, find the **maximum absolute sum** of any subarray.

A **subarray** is a contiguous part of an array.

### Constraints:
- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

## Approach

### Key Observations:
1. The maximum absolute sum of any subarray is determined by the largest sum subarray and the smallest sum subarray.
2. Instead of using Kadane's algorithm twice, we track both the maximum and minimum prefix sum values in one pass.

### Steps:
1. Initialize three variables:
   - `mini = 0` (tracks the minimum prefix sum)
   - `maxi = 0` (tracks the maximum prefix sum)
   - `sum = 0` (accumulates the running sum)
2. Iterate through `nums`:
   - Update `sum` with the current element.
   - Update `mini` to track the lowest prefix sum encountered.
   - Update `maxi` to track the highest prefix sum encountered.
3. The result is `maxi - mini`, which gives the maximum absolute sum of any subarray.

## Code Implementation

```cpp
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mini = 0, maxi = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            mini = min(mini, sum);
            maxi = max(maxi, sum);
        }
        return maxi - mini;
    }
};
```

## Complexity Analysis
- **Time Complexity:** `O(n)` since we iterate through the array once.
- **Space Complexity:** `O(1)` as we only use a few extra variables.

## Example

### Input:
```cpp
nums = [1,-3,2,3,-4]
```

### Output:
```cpp
5
```

### Explanation:
- The subarray `[2,3]` has a sum of `5`.
- The subarray `[-3]` has a sum of `-3`.
- The absolute max sum is `5`.

## Edge Cases Considered:
- All positive numbers
- All negative numbers
- Mixed positive and negative numbers
- Single-element array
- Large input sizes

---

Happy Coding! 🚀

