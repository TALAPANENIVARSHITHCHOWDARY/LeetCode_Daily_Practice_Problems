# 1980. Find Unique Binary String

## Problem Statement
You are given an array `nums` containing `n` unique binary strings of length `n`. Your task is to return a binary string of length `n` that is **not** present in `nums`. There exists **exactly one** such string.

### Constraints:
- `1 <= n <= 16`
- `nums.length == n`
- `nums[i].length == n`
- Each `nums[i]` is either `'0'` or `'1'`

## Approach

1. **Backtracking Approach:**
   - Use a recursive function to generate a binary string character by character.
   - If a generated binary string is not found in `nums`, return it.
   - Try both `0` and `1` at each position.

2. **Hash Set for Fast Lookup:**
   - Store all strings from `nums` in an `unordered_set` for O(1) lookup.
   - Use backtracking to generate unique binary strings and check against the set.

## Code

```cpp
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> numSet(nums.begin(), nums.end());
        string current(n, '0');
        if (backtrack(numSet, current, 0, n)) {
            return current;
        }
        return "";
    }

private:
    bool backtrack(unordered_set<string>& numSet, string& current, int pos, int n) {
        if (pos == n) {
            return numSet.find(current) == numSet.end();
        }
        if (backtrack(numSet, current, pos + 1, n)) {
            return true;
        }
        current[pos] = '1';
        if (backtrack(numSet, current, pos + 1, n)) {
            return true;
        }
        current[pos] = '0';
        return false;
    }
};
```

## Example

**Input:**
```cpp
nums = ["01", "10"]
```

**Output:**
```cpp
"00"
```

**Explanation:**
- Possible binary strings of length `n=2`: {"00", "01", "10", "11"}
- "01" and "10" are given in `nums`.
- "00" is missing, so we return it.

## Complexity Analysis

**Time Complexity:** O(2^n)
- The worst case explores all possible binary strings of length `n`, which is `2^n`.
- However, pruning using backtracking significantly reduces unnecessary computation.

**Space Complexity:** O(n)
- The recursive stack depth is at most `n`.
- The unordered set stores `n` strings, which is negligible for `n <= 16`.

## Usage

```cpp
int main() {
    Solution sol;
    vector<string> nums = {"01", "10"};
    cout << sol.findDifferentBinaryString(nums) << endl; // Output: "00"
    return 0;
}
```

#

