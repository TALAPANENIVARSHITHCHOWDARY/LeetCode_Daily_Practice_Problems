# 2698. Find the Punishment Number of an Integer

## Problem Statement
Given an integer `n`, you need to find the **punishment number** of `n`. The punishment number is the sum of squares of certain integers that satisfy a specific condition.

### Conditions:
For each integer `x` from `1` to `n`, compute `x^2`. If you can partition `x^2` into contiguous substrings such that the sum of these substrings equals `x`, then `x^2` contributes to the punishment number.

Return the total sum of such squares.

### Constraints:
- `1 <= n <= 1000`

## Approach

1. **Recursive Function with Memoization:**
   - We define a helper function `func` to check if we can partition `x^2` such that the sum of its partitions equals `x`.
   - We use a recursive approach to explore all possible partitions.
   - Memoization (`dp`) is used to store results for overlapping subproblems to optimize performance.

2. **Iterate from `1` to `n`:**
   - Compute the square of each number.
   - Convert it into a string and check if it satisfies the condition using `func`.
   - If valid, add it to the punishment sum.

## Code

```cpp
class Solution {
public:
    bool func(int sind, int sum, string snum, int tar, vector<vector<int>>& dp) {
        if (sind == snum.size()) {
            return sum == tar;
        }
        if (sum > tar) return false;
        if (dp[sind][sum] != -1) return dp[sind][sum];
        bool ind = false;
        for (int curi = sind; curi < snum.size(); curi++) {
            string curs = snum.substr(sind, curi - sind + 1);
            int addend = stoi(curs);
            ind = ind || func(curi + 1, sum + addend, snum, tar, dp);
            if (ind == true) return true;
        }
        return dp[sind][sum] = ind;
    }
    
    int punishmentNumber(int n) {
        int result = 0;
        for (int currentNum = 1; currentNum <= n; currentNum++) {
            int squareNum = currentNum * currentNum;
            string snum = to_string(squareNum);
            vector<vector<int>> dp(snum.size(), vector<int>(currentNum + 1, -1));
            if (func(0, 0, snum, currentNum, dp)) {
                result += squareNum;
            }
        }
        return result;
    }
};
```

## Example

**Input:**
```cpp
n = 10
```

**Output:**
```cpp
182
```

**Explanation:**
- `1^2 = 1` → `1`
- `9^2 = 81` → `8 + 1 = 9`
- `10^2 = 100` → `1 + 00 = 10`

Total sum = `1 + 81 + 100 = 182`.

## Complexity Analysis

**Time Complexity:**
- **O(n * m * m)**, where `n` is the given number and `m` is the length of `x^2`.
- The recursion explores all substrings, making it exponential in the worst case.
- Memoization reduces redundant computations, optimizing the solution.

**Space Complexity:**
- **O(n * m)** due to memoization (`dp` table) storage.

## Usage

```cpp
int main() {
    Solution sol;
    int n = 10;
    cout << sol.punishmentNumber(n) << endl; // Output: 182
    return 0;
}
```

