# 3160. Find the Number of Distinct Colors Among the Balls

## Problem Statement

You are given an integer `limit` and a list of `queries`, where each query contains two integers `[ball, color]`.
Each query represents painting a ball with a given color. If the ball was previously painted, it will be repainted.

Return an array where each element represents the number of distinct colors present after each query.

### Constraints:
- `1 <= limit <= 10^5`
- `1 <= queries.length <= 10^5`
- `1 <= ball <= limit`
- `1 <= color <= 10^5`

## Approach

1. **Use Two Hash Maps:**
   - `mppB`: Stores the mapping of each ball to its assigned color.
   - `mppC`: Stores the count of occurrences of each color.
   - Maintain a `cnt` variable to track the number of distinct colors.

2. **Process Each Query:**
   - If the ball was previously painted, decrease the count of its old color.
   - Update the ball with the new color.
   - Increase the count of the new color.
   - Update the `cnt` variable accordingly.
   - Append the current `cnt` to the result.

## Code

```cpp
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> result;
        unordered_map<int, int> mppB; 
        unordered_map<int, int> mppC; 
        int cnt = 0; 
        
        for (const auto& query : queries) {
            int ball = query[0];
            int color = query[1];
            
            if (mppB.find(ball) != mppB.end()) {
                int oldColor = mppB[ball];
                mppC[oldColor]--;
                if (mppC[oldColor] == 0) {
                    cnt--;
                }
            }
            
            mppB[ball] = color;
            mppC[color]++;
            if (mppC[color] == 1) {
                cnt++;
            }
            
            result.push_back(cnt);
        }
        
        return result;
    }
};
```

## Example

**Input:**  
```
limit = 4
queries = [[1, 2], [2, 3], [1, 3], [3, 3]]
```

**Output:**  
```
[1, 2, 1, 1]
```

**Explanation:**
1. Ball `1` is painted with color `2` → Distinct colors: `{2}` → Output: `1`
2. Ball `2` is painted with color `3` → Distinct colors: `{2, 3}` → Output: `2`
3. Ball `1` is repainted with color `3` → Distinct colors: `{3}` → Output: `1`
4. Ball `3` is painted with color `3` → Distinct colors: `{3}` → Output: `1`

## Complexity Analysis

**Time Complexity:**
- Each query is processed in **O(1)** using hash maps.
- Overall complexity: **O(n)**, where *n* is the number of queries.

**Space Complexity:**
- Storing mappings in two hash maps takes **O(n)** space.
- Overall complexity: **O(n)**.

## Usage

1. Include the header files and define the `Solution` class.
2. Create an object of the `Solution` class.
3. Call the `queryResults` method with `limit` and `queries`.

```cpp
int main() {
    Solution sol;
    int limit = 4;
    vector<vector<int>> queries = {{1, 2}, {2, 3}, {1, 3}, {3, 3}};
    vector<int> res = sol.queryResults(limit, queries);
    for (int r : res) {
        cout << r << " ";
    }
    return 0;
}
```

