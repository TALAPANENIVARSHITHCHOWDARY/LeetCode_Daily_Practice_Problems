# 1028. Recover a Tree From Preorder Traversal

## Problem Statement
Given a string `traversal` representing a preorder traversal of a binary tree with dashes indicating depth, construct and return the root of the tree.

### Constraints:
- The input string consists of digits (`0-9`) and dashes (`-`).
- The number of nodes in the tree is in the range `[1, 1000]`.
- The depth of the tree is at most `1000`.
- The value of each node is a unique positive integer in the range `[1, 10^9]`.

## Approach

1. **Stack-Based Parsing**:
   - Use a stack to keep track of nodes at different depths.
   - Traverse the input string while extracting node values and their corresponding depth.
   
2. **Determine Parent-Child Relationship**:
   - If the stack size is greater than the current depth, pop elements from the stack until the correct depth is reached.
   - Attach the new node as a left child if the parent does not have one, otherwise attach it as a right child.

3. **Returning the Root**:
   - After processing all nodes, the root of the tree remains at the bottom of the stack.

## Code Implementation

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> s;
        int i = 0;
        while (i < traversal.size()) {
            int level = 0;
            while (i < traversal.size() && traversal[i] == '-') {
                level++;
                i++;
            }
            int value = 0;
            while (i < traversal.size() && isdigit(traversal[i])) {
                value = value * 10 + (traversal[i] - '0');
                i++;
            }
            TreeNode* node = new TreeNode(value);
            while (s.size() > level) {
                s.pop();
            }
            if (!s.empty()) {
                if (!s.top()->left) {
                    s.top()->left = node;
                } else {
                    s.top()->right = node;
                }
            }
            s.push(node);
        }
        while (s.size() > 1) {
            s.pop();
        }
        return s.top();
    }
};
```

## Example

### Input:
```cpp
traversal = "1-2--3--4-5--6--7"
```

### Output:
```cpp
     1
    / \
   2   5
  / \  / \
 3   4 6  7
```

## Complexity Analysis

**Time Complexity:** `O(N)`, where `N` is the length of the input string.
- Each character is processed once.
- Stack operations are efficient (`O(1)` per push/pop).

**Space Complexity:** `O(D)`, where `D` is the depth of the tree.
- The stack stores at most `D` nodes at a time.

## Usage

```cpp
int main() {
    Solution sol;
    string traversal = "1-2--3--4-5--6--7";
    TreeNode* root = sol.recoverFromPreorder(traversal);
    // Perform further operations on the constructed tree
    return 0;
}
```

