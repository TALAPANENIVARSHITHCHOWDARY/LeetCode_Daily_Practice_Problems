# 2375. Construct Smallest Number From DI String

## Problem Statement
You are given a string `pattern` of length `n` consisting of the characters `'I'` (increasing) and `'D'` (decreasing). Your task is to construct the smallest numerical sequence that follows the given pattern.

Each number in the sequence must be unique and between `1` and `n+1`. The goal is to return the lexicographically smallest valid sequence.

### Constraints:
- `1 <= pattern.length <= 8`
- `pattern` consists only of `'I'` and `'D'`

## Approach

1. **Initialize a sequence**:
   - Create a sequence of numbers from `1` to `n+1`.

2. **Process the pattern**:
   - Traverse the `pattern` string.
   - If a `'D'` is found, find the longest contiguous decreasing segment and reverse that part of the sequence.
   
3. **Return the final sequence as a string**.

## Code

```cpp
class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string num(n + 1, '0');
        for (int i = 0; i <= n; ++i) {
            num[i] = '1' + i;
        }
        for (int i = 0; i < n; ++i) {
            if (pattern[i] == 'D') {
                int j = i;
                while (j < n && pattern[j] == 'D') {
                    ++j;
                }
                reverse(num.begin() + i, num.begin() + j + 1);
                i = j - 1;
            }
        }
        return num;
    }
};
```

## Example

### Input
```cpp
pattern = "IDID"
```

### Output
```cpp
"13254"
```

### Explanation
- `'I'` → Increase: `1 -> 3`
- `'D'` → Decrease: `3 -> 2`
- `'I'` → Increase: `2 -> 5`
- `'D'` → Decrease: `5 -> 4`

## Complexity Analysis

- **Time Complexity:** `O(n)`, as we iterate through the string once and perform limited reversals.
- **Space Complexity:** `O(n)`, since we store the sequence in a string.

## Usage

```cpp
int main() {
    Solution sol;
    string pattern = "IDID";
    cout << sol.smallestNumber(pattern) << endl; // Output: "13254"
    return 0;
}
```
