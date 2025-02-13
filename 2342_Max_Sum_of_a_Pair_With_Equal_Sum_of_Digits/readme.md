# 2342. Max Sum of a Pair With Equal Sum of Digits

## Problem Statement

You are given an array `nums` consisting of positive integers. A pair `(nums[i], nums[j])` is considered **valid** if the sum of digits of `nums[i]` is equal to the sum of digits of `nums[j]` and `i != j`. The goal is to find the **maximum sum** among all valid pairs.

If no valid pair exists, return `-1`.

### Constraints:
- `2 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`

## Approach

### Observations
- Each number's **digit sum** is computed by summing its individual digits.
- We need to find **pairs of numbers** with the **same digit sum**.
- For each digit sum, we only care about the two largest numbers to maximize the sum.

### Steps
1. **Group numbers by their digit sums:**
   - Maintain a vector of **min-heaps** (priority queues) to store numbers for each possible digit sum.
   - Keep only the **top 2 largest numbers** for each digit sum.
2. **Compute maximum valid pair sum:**
   - Iterate over the groups, checking if a valid pair exists.
   - Extract the two largest numbers from the heap and compute their sum.
   - Keep track of the **maximum sum** encountered.

## Code

```cpp
class Solution {
private:
    // Helper function to compute the sum of digits of a number
    int calculateDigitSum(int num) {
        int digitSum = 0;
        while (num > 0) {
            digitSum += num % 10;
            num /= 10;
        }
        return digitSum;
    }

public:
    int maximumSum(vector<int>& nums) {
        // Vector to store a min heap for each possible digit sum (0 to 81)
        vector<priority_queue<int, vector<int>, greater<int>>> digitSumGroups(82);

        int maxPairSum = -1;

        // Group numbers by their digit sums, maintaining heap size of 2
        for (int number : nums) {
            int digitSum = calculateDigitSum(number);
            digitSumGroups[digitSum].push(number);

            // Keep only the top 2 largest numbers in the heap
            if (digitSumGroups[digitSum].size() > 2) {
                digitSumGroups[digitSum].pop();  // Remove the smallest element
            }
        }

        // Traverse the vector to find the maximum pair sum for each group
        for (auto& minHeap : digitSumGroups) {
            if (minHeap.size() == 2) {
                int first = minHeap.top();
                minHeap.pop();
                int second = minHeap.top();
                maxPairSum = max(maxPairSum, first + second);
            }
        }

        return maxPairSum;
    }
};
```

## Example

**Input:**
```cpp
nums = {18, 43, 36, 13, 7}
```

**Output:**
```cpp
54
```

**Explanation:**
- **Digit sum of 18** = `1 + 8 = 9`
- **Digit sum of 36** = `3 + 6 = 9`
- The only valid pair is `(18, 36)`, sum = `18 + 36 = 54`.

## Complexity Analysis

**Time Complexity:**
- **O(n log 2) = O(n)**, where `n` is the length of `nums`, because we insert at most 2 elements into a heap per digit sum.

**Space Complexity:**
- **O(82) ≈ O(1)** since there are at most 82 possible digit sums.

## Usage

```cpp
int main() {
    Solution sol;
    vector<int> nums = {18, 43, 36, 13, 7};
    cout << sol.maximumSum(nums) << endl; // Output: 54
    return 0;
}
```

