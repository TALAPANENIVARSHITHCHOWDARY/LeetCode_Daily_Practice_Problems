# Longest Monotonic Subarray

## Problem Statement

Given an array of integers, find the length of the longest monotonic subarray. A monotonic subarray is defined as a subarray that is either strictly increasing or strictly decreasing.

## Approach

The approach involves iterating through the array once and keeping track of two sequences:
1. **Increasing Subarray**
2. **Decreasing Subarray**

At each step, we compare the current element with the previous one to determine whether the sequence is increasing, decreasing, or neither. We maintain counters for both increasing and decreasing sequences and update the maximum length found so far.

## Code

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;

        int maxi = 1, maxd = 1, curi = 1, curd = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                curi++;
                maxi = max(maxi, curi);
                curd = 1;
            } else if (nums[i] < nums[i - 1]) {
                curd++;
                maxd = max(maxd, curd);
                curi = 1;
            } else {
                curi = 1;
                curd = 1;
            }
        }
        return max(maxi, maxd);
    }
};
```

## Example

**Input:**
```
nums = [1, 2, 2, 3, 4, 1, 0, -1]
```

**Output:**
```
4
```

**Explanation:**
- The longest increasing subarray is `[2, 3, 4]` with length 3.
- The longest decreasing subarray is `[4, 1, 0, -1]` with length 4.

Hence, the function returns 4.

## Complexity Analysis

**Time Complexity:**
- The algorithm iterates through the array once, resulting in a time complexity of **O(n)**, where *n* is the length of the input array.

**Space Complexity:**
- The algorithm uses a constant amount of extra space for variables, resulting in a space complexity of **O(1)**.

## Usage

1. Include the header files and define the `Solution` class.
2. Create an object of the `Solution` class.
3. Call the `longestMonotonicSubarray` method by passing a vector of integers.

```cpp
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2, 3, 4, 1, 0, -1};
    cout << sol.longestMonotonicSubarray(nums) << endl; // Output: 4
    return 0;
}
```

