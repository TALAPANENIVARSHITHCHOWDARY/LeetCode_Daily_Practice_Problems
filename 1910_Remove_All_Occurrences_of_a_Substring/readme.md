# 1910. Remove All Occurrences of a Substring

## Problem Statement

You are given two strings `s` and `part`. You need to repeatedly remove occurrences of `part` in `s` until `s` no longer contains `part`.

Return the final string after all such operations have been performed.

### Constraints:
- `1 <= s.length <= 1000`
- `1 <= part.length <= 100`
- `s` and `part` consist of lowercase English letters.

## Approach

### Observations

- We need to repeatedly search for `part` in `s` and remove it.
- A **stack-based** approach can help efficiently track character sequences.

### Steps
1. **Use a Stack:**
   - Iterate through `s` and push characters onto a stack.
   - If the top `part.length()` characters match `part`, remove them.
2. **Check for Matches Efficiently:**
   - A helper function verifies if the last `part.length()` characters match `part`.
3. **Construct the Result:**
   - The final string is built from the remaining characters in the stack.

## Code

```cpp
class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        int sLen = s.length();
        int pLen = part.length();
        for (int i = 0; i < sLen; i++) {
            st.push(s[i]);
            if (st.size() >= pLen && match(st, part, pLen)) {
                for (int j = 0; j < pLen; j++) {
                    st.pop();
                }
            }
        }
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }

private:
    bool match(stack<char>& st, string& part, int pLen) {
        stack<char> temp = st;
        for (int i = pLen - 1; i >= 0; i--) {
            if (temp.top() != part[i]) {
                return false;
            }
            temp.pop();
        }
        return true;
    }
};
```

## Example

**Input:**
```cpp
s = "daabcbaabcbc", part = "abc"
```

**Output:**
```cpp
"dab"
```

**Explanation:**
1. Remove "abc" → "dabaabcbc"
2. Remove "abc" → "dababc"
3. Remove "abc" → "dab"

## Complexity Analysis

**Time Complexity:**
- **O(n * m)** in the worst case, where `n` is the length of `s` and `m` is the length of `part`, due to repeated removals.

**Space Complexity:**
- **O(n)** for storing characters in the stack.

## Usage

```cpp
int main() {
    Solution sol;
    string s = "daabcbaabcbc";
    string part = "abc";
    cout << sol.removeOccurrences(s, part) << endl; // Output: "dab"
    return 0;
}
```


