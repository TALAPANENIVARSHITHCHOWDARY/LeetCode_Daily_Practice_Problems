# 1415. The k-th Lexicographical String of All Happy Strings of Length n

## Problem Statement
Given two integers `n` and `k`, return the `k`-th lexicographically smallest **happy string** of length `n`. If there is no such string, return an empty string `""`.

A string is called **happy** if it consists only of letters `'a'`, `'b'`, and `'c'` and no two adjacent characters are the same.

### Constraints:
- `1 <= n <= 10`
- `1 <= k <= 3 * 2^(n-1)`

## Approach

1. **Backtracking to Generate Happy Strings**
   - Use a recursive function `func` to generate all valid happy strings of length `n`.
   - Ensure that no two adjacent characters are the same.
   
2. **Sorting and Selecting the k-th Element**
   - Store all generated happy strings in an array.
   - Sort the array lexicographically.
   - Return the `k`-th element if it exists; otherwise, return an empty string.

## Code

```cpp
class Solution {
public:
    void func(int n, string &cur, vector<string> &arr, char lc) {
        if (cur.size() == n) {
            arr.push_back(cur);
            return;
        }
        for (char ch : {'a', 'b', 'c'}) {
            if (ch != lc) {
                cur.push_back(ch);
                func(n, cur, arr, ch);
                cur.pop_back();
            }
        }
    }
    
    string getHappyString(int n, int k) {
        vector<string> arr;
        string cur;
        func(n, cur, arr, '\0');
        if (k > arr.size()) {
            return "";
        }
        sort(arr.begin(), arr.end());
        return arr[k - 1];
    }
};
```

## Example

**Input:**
```cpp
n = 3, k = 9
```

**Output:**
```cpp
"cab"
```

**Explanation:**
- The lexicographically ordered happy strings of length `3` are:
  `"aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"`
- The `9`-th string is `"cab"`.

## Complexity Analysis

**Time Complexity:**
- **O(3 * 2^(n-1))**: The number of happy strings generated is bounded by `3 * 2^(n-1)`, and sorting takes `O(N log N)` time.
- **O(N log N) + O(K)** for selection of the `k`-th element.

**Space Complexity:**
- **O(N)** for recursive function calls.
- **O(N log N)** for storing and sorting the happy strings.

## Usage

```cpp
int main() {
    Solution sol;
    int n = 3, k = 9;
    cout << sol.getHappyString(n, k) << endl; // Output: "cab"
    return 0;
}
```



