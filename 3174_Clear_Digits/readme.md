# 3174. Clear Digits

## Problem Statement

You are given a string `s` consisting of lowercase English letters and digits. You need to remove digits from `s` following these rules:

- If a digit appears, remove the **last** non-digit character that appears **before** it in `s`.
- If no non-digit character exists before a digit, the digit is ignored.

Return the modified string after processing all characters.

### Constraints:
- `1 <= s.length <= 100`
- `s` consists only of lowercase English letters and digits.

## Approach

1. **Use a Stack:**
   - Iterate through the string and maintain a stack.
   - If the character is a **letter**, push it onto the stack.
   - If the character is a **digit**, pop the top character from the stack if it's not empty.
   - Construct the final result by collecting remaining characters in the stack.

## Code

```cpp
class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for (char c : s) {
            if (isdigit(c)) {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(c);
            }
        } 
        string result;
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        } 
        return result;
    }
}; 
```

## Example

**Input:**
```cpp
s = "a1b2c3d"
```

**Output:**
```cpp
""
```

**Explanation:**
- `1` removes `a`
- `2` removes `b`
- `3` removes `c`
- `d` remains, but since `d` is removed by `3`, the final output is `""`.

**Input:**
```cpp
s = "abc123xyz"
```

**Output:**
```cpp
"xyz"
```

**Explanation:**
- `1` removes `c`
- `2` removes `b`
- `3` removes `a`
- `xyz` remains.

## Complexity Analysis

**Time Complexity:**
- **O(n)**, where *n* is the length of `s`, since each character is processed once.

**Space Complexity:**
- **O(n)** in the worst case (if no digits exist, we store all characters in the stack).

## Usage

```cpp
int main() {
    Solution sol;
    string s = "abc123xyz";
    cout << sol.clearDigits(s) << endl; // Output: "xyz"
    return 0;
}
```


