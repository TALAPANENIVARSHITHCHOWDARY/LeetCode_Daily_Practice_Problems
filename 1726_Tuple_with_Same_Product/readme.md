# 1726. Tuple with Same Product

## Problem Statement

Given an array `nums` of distinct positive integers, find the number of tuples `(a, b, c, d)` such that:
- `a * b = c * d`
- `(a, b, c, d)` are elements from `nums`
- `(a, b)` and `(c, d)` are distinct pairs

Return the number of such tuples.

### Constraints:
- `1 <= nums.length <= 1000`
- `1 <= nums[i] <= 10^4`
- All elements in `nums` are distinct.

## Approach

1. **Use a Hash Map to Store Products:**
   - Iterate over all pairs `(i, j)` in `nums`.
   - Compute the product `nums[i] * nums[j]`.
   - Store the count of occurrences of each product in a hash map.

2. **Count Valid Tuples:**
   - If a product appears `k` times in the map, the number of ways to select two distinct pairs is `k * (k - 1) / 2`.
   - Since each such selection can be arranged in `8` different ways, multiply by `8`.
   - Sum up the total count.

## Code

```cpp
class Solution {
public:
    int tupleSameProduct(std::vector<int>& nums) {
        unordered_map<int, int> mpp;
        int count = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                int temp = nums[i] * nums[j];
                mpp[temp]++;
            }
        }
        
        for (const auto& entry : mpp) {
            int k = entry.second;
            if (k > 1) {
                 count += (k * (k - 1) / 2) * 8;
            }
        }
        
        return count;
    }
};
```

## Example

**Input:**  
`nums = [2, 3, 4, 6]`

**Output:**  
`8`

**Explanation:**
- The valid tuples are `(2,6,3,4)`, `(2,6,4,3)`, `(6,2,3,4)`, `(6,2,4,3)`, `(3,4,2,6)`, `(3,4,6,2)`, `(4,3,2,6)`, `(4,3,6,2)`, all derived from `2 * 6 = 3 * 4`.

## Complexity Analysis

**Time Complexity:**  
- The double loop runs in **O(n²)** time.
- The map lookup and update are **O(1)** on average.
- The final loop to count tuples is **O(n)**.
- Overall complexity: **O(n²)**.

**Space Complexity:**  
- The hash map stores product counts, which can have at most **O(n²)** entries.
- Overall complexity: **O(n²)** in the worst case.

## Usage

1. Include the header files and define the `Solution` class.
2. Create an object of the `Solution` class.
3. Call the `tupleSameProduct` method by passing a vector of integers.

```cpp
int main() {
    Solution sol;
    vector<int> nums = {2, 3, 4, 6};
    cout << sol.tupleSameProduct(nums) << endl;  // Output: 8
    return 0;
}
```

