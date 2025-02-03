# 1752. Check if Array Is Sorted and Rotated

## Problem Statement

Given an array of `n` integers, check if it is a sorted array that has been rotated. A sorted array is considered to be rotated if it was sorted in ascending order and then rotated some number of positions (including zero). For example, `[3, 4, 5, 1, 2]` is a sorted and rotated version of `[1, 2, 3, 4, 5]`.

Return `true` if the array is sorted and rotated, otherwise return `false`.

### Constraints:
- `n == nums.length`
- `1 <= n <= 100`
- `1 <= nums[i] <= 100`

## Approach

1. **Count the Number of Decreasing Pairs:**
   - Iterate through the array and count the number of places where the current element is smaller than the previous one.
   - For a sorted and rotated array, there should be **at most one** such place.

2. **Check the Last Element with the First:**
   - Since the array can be rotated, we also need to compare the last element with the first element.
   - If the last element is greater than the first element, increment the count.

3. **Return Result:**
   - If the count of decreasing places is less than or equal to 1, the array is sorted and rotated. Otherwise, it's not.

## Code

```cpp
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) {
                cnt++;
            }
        }
        
        if (nums[n - 1] > nums[0]) {
            cnt++;
        }
        
        return cnt <= 1;
    }
};
```

## Example

**Input:**  
`nums = [3, 4, 5, 1, 2]`

**Output:**  
`true`

**Explanation:**  
- The array `[3, 4, 5, 1, 2]` is a rotated version of the sorted array `[1, 2, 3, 4, 5]`.
- There is only one decreasing pair (`5 > 1`), satisfying the condition.

---

**Input:**  
`nums = [2, 1, 3, 4]`

**Output:**  
`false`

**Explanation:**  
- The array `[2, 1, 3, 4]` has two decreasing pairs (`2 > 1` and `4 > 2`), so it is not sorted and rotated.

## Complexity Analysis

**Time Complexity:**  
- The algorithm iterates through the array once, leading to a time complexity of **O(n)**, where *n* is the number of elements in the array.

**Space Complexity:**  
- The algorithm uses a constant amount of extra space, leading to a space complexity of **O(1)**.

## Usage

1. Include the header files and define the `Solution` class.
2. Create an object of the `Solution` class.
3. Call the `check` method by passing a vector of integers.

```cpp
int main() {
    Solution sol;
    vector<int> nums = {3, 4, 5, 1, 2};
    cout << sol.check(nums) << endl;  // Output: true
    return 0;
}
```



