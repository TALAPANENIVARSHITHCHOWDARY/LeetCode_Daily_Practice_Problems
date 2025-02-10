# 2364. Count Number of Bad Pairs

## Problem Statement

You are given an array `nums` of length `n`. A pair `(i, j)` is **bad** if:
- `i < j`
- `i - nums[i] != j - nums[j]`

Return the total number of bad pairs in the array.

### Constraints:
- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^9`

## Approach

### Observations

A pair `(i, j)` is considered **good** if:
- `i - nums[i] == j - nums[j]`

We count **bad pairs** using the formula:
```
Total pairs - Good pairs = Bad pairs
```

### Steps
1. **Use a Hash Map:**
   - Maintain a map `diffCount` to store how many times each `i - nums[i]` difference has appeared.
   - Iterate through `nums`, computing `diff = i - nums[i]` for each index `i`.
   - The count of **good pairs** for an index `i` is simply `diffCount[diff]`.
   - The number of **bad pairs** for `i` is `i - goodPairsCount`.
   - Update `diffCount[diff]` for future calculations.

## Code

```cpp
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long badPairs = 0;
        unordered_map<int, int> diffCount;

        for (int pos = 0; pos < nums.size(); pos++) {
            int diff = pos - nums[pos];

            // Count of previous positions with same difference
            int goodPairsCount = diffCount[diff];

            // Total possible pairs minus good pairs = bad pairs
            badPairs += pos - goodPairsCount;

            // Update count of positions with this difference
            diffCount[diff] = goodPairsCount + 1;
        }

        return badPairs;
    }
};
```

## Example

**Input:**
```cpp
nums = [4,1,3,3]
```

**Output:**
```cpp
5
```

**Explanation:**
- The total possible pairs are `C(4,2) = 6`.
- The **good pairs** are `[(1,2)]`.
- The **bad pairs** are `6 - 1 = 5`.

## Complexity Analysis

**Time Complexity:**
- **O(n)**, as we iterate through `nums` once and use a hash map for efficient lookups.

**Space Complexity:**
- **O(n)**, for storing values in `unordered_map`.

## Usage

```cpp
int main() {
    Solution sol;
    vector<int> nums = {4,1,3,3};
    cout << sol.countBadPairs(nums) << endl; // Output: 5
    return 0;
}
```

