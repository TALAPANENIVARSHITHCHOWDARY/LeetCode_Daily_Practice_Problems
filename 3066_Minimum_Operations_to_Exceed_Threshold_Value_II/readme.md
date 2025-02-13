# 3066. Minimum Operations to Exceed Threshold Value II

## Problem Statement
You are given an array `nums` of positive integers and a threshold value `k`. In each operation, you can:
1. Take the two smallest numbers `x` and `y` from `nums`.
2. Remove both `x` and `y` from the array.
3. Insert a new number `newVal = min(x, y) * 2 + max(x, y)` into the array.

Return the minimum number of operations required to make **all** elements in `nums` at least `k`.

### Constraints:
- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`
- `1 <= k <= 10^9`

## Approach

1. **Use a Min Heap (Priority Queue):**
   - Push all elements into a min heap.
   - If the smallest element is already `>= k`, return 0.
   - Repeatedly combine the two smallest elements using the given formula until all elements are `>= k`.
   
2. **Keep Track of Operations:**
   - Each combination counts as an operation.
   - Continue the process until all elements meet the condition.

## Code

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int num : nums) {
            pq.push((long long)num);
        }
        int ops = 0;
        while(pq.size() >= 2 && pq.top() < k) {
            long long x = pq.top(); pq.pop();
            long long y = pq.top(); pq.pop();
            long long newVal = min(x, y) * 2 + max(x, y);
            pq.push(newVal);
            ops++;
        }
        return ops;
    }
};
```

## Example

**Input:**
```cpp
nums = [1, 2, 3, 4, 10]
k = 20
```

**Output:**
```cpp
2
```

**Explanation:**
1. Merge `1` and `2`: `newVal = 1*2 + 2 = 4` → `nums = [3, 4, 4, 10]`
2. Merge `3` and `4`: `newVal = 3*2 + 4 = 10` → `nums = [4, 10, 10]`

Now, all elements are `>= k = 20`, so the result is `2`.

## Complexity Analysis

**Time Complexity:**
- **O(n log n)** due to heap operations.
- Heap insertions and deletions are **O(log n)**, and we process at most **n** elements.

**Space Complexity:**
- **O(n)** for storing elements in the priority queue.

## Usage
```cpp
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 10};
    int k = 20;
    cout << sol.minOperations(nums, k) << endl; // Output: 2
    return 0;
}
```
