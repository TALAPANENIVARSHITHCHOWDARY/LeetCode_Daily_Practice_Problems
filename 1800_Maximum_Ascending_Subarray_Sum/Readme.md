# 1800. Maximum Ascending Subarray Sum

## Problem Statement

Given an array of positive integers `nums`, find the maximum sum of any ascending subarray. An ascending subarray is defined as a contiguous sequence where each element is strictly greater than the previous one.

Return the maximum sum of such a subarray.

### Constraints:
- `1 <= nums.length <= 100`
- `1 <= nums[i] <= 100`

## Approach

1. **Initialize Variables:**
   - `cur`: Tracks the current ascending subarray sum.
   - `maxi`: Stores the maximum sum encountered so far.

2. **Iterate Through the Array:**
   - For each element starting from the second one, compare it with the previous element.
   - If the current element is greater than the previous one, add it to the `cur` sum (indicating an ascending subarray).
   - If the current element is not greater, update `maxi` if `cur` is larger, then reset `cur` to the current element.

3. **Final Comparison:**
   - After the loop, ensure to update `maxi` one last time to account for any ascending sequence that may have extended to the end of the array.

4. **Return the Result:**
   - Return the value stored in `maxi`, which represents the maximum sum of an ascending subarray.

## Code

```cpp
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int cur = nums[0];
        int maxi = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                cur += nums[i];
            } else {
                maxi = max(maxi, cur);
                cur = nums[i];
            }
        }
        maxi = max(cur, maxi);
        return maxi;
    }
};
```

## Example

**Input:**  
`nums = [10, 20, 30, 5, 10, 50]`

**Output:**  
`65`

**Explanation:**  
- The ascending subarrays are `[10, 20, 30]` with sum `60`, and `[5, 10, 50]` with sum `65`.
- The maximum sum is `65`.

---

**Input:**  
`nums = [10, 20, 30, 40, 50]`

**Output:**  
`150`

**Explanation:**  
- The entire array is an ascending subarray with sum `150`.

## Complexity Analysis

**Time Complexity:**  
- The algorithm iterates through the array once, leading to a time complexity of **O(n)**, where *n* is the number of elements in the array.

**Space Complexity:**  
- The algorithm uses a constant amount of extra space, leading to a space complexity of **O(1)**.

## Usage

1. Include the header files and define the `Solution` class.
2. Create an object of the `Solution` class.
3. Call the `maxAscendingSum` method by passing a vector of integers.

```cpp
int main() {
    Solution sol;
    vector<int> nums = {10, 20, 30, 5, 10, 50};
    cout << sol.maxAscendingSum(nums) << endl;  // Output: 65
    return 0;
}
```



