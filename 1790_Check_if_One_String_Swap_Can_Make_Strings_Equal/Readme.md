# 1790. Check if One String Swap Can Make Strings Equal

## Problem Statement

You are given two strings `s1` and `s2` of equal length. A string swap operation involves swapping two characters in one of the strings.

Return `true` if it is possible to make `s1` equal to `s2` by performing **at most one swap** operation on `s1`. Otherwise, return `false`.

### Constraints:
- `1 <= s1.length, s2.length <= 100`
- `s1.length == s2.length`
- `s1` and `s2` consist only of lowercase English letters.

## Approach

1. **Check for Length Mismatch:**
   - If the lengths of `s1` and `s2` are not the same, return `false` immediately.

2. **Identify Differences:**
   - Iterate through both strings simultaneously and identify indices where the characters differ.
   - Keep a count of differing positions and store their indices in a vector.

3. **Analyze the Differences:**
   - If there are no differences (`cnt == 0`), the strings are already equal, return `true`.
   - If there are exactly two differences, check if swapping the mismatched characters in `s1` would make the strings equal.
   - If the conditions are satisfied, return `true`. Otherwise, return `false`.
   - If there are more than two differences, return `false` as only one swap won't suffice.

## Code

```cpp
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;
        vector<int> arr;

        if (s1.size() != s2.size()) return false;

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                cnt++;
                if (cnt > 2) return false;
                arr.push_back(i);
            }
        }

        if (cnt == 0) return true;
        if (cnt == 2 && s1[arr[0]] == s2[arr[1]] && s1[arr[1]] == s2[arr[0]]) return true;

        return false;
    }
};
```

## Example

**Input:**  
`s1 = "bank", s2 = "kanb"`

**Output:**  
`true`

**Explanation:**  
- You can swap the characters `'b'` and `'k'` in `s1` to get `"kanb"`, which equals `s2`.

---

**Input:**  
`s1 = "attack", s2 = "defend"`

**Output:**  
`false`

**Explanation:**  
- The strings differ in more than two positions, so one swap isn't enough to make them equal.

## Complexity Analysis

**Time Complexity:**  
- The algorithm iterates through the strings once, leading to a time complexity of **O(n)**, where *n* is the length of the strings.

**Space Complexity:**  
- The algorithm uses a small additional space to store differing indices, leading to a space complexity of **O(1)**.

## Usage

1. Include the header files and define the `Solution` class.
2. Create an object of the `Solution` class.
3. Call the `areAlmostEqual` method by passing two strings.

```cpp
int main() {
    Solution sol;
    string s1 = "bank", s2 = "kanb";
    cout << sol.areAlmostEqual(s1, s2) << endl;  // Output: true
    return 0;
}
```


