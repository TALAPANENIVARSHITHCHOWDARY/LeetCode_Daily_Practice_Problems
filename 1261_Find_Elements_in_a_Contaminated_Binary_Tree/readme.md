# 1261. Find Elements in a Contaminated Binary Tree

## Problem Statement
A binary tree is **contaminated**, meaning that all node values are set to `-1`. You need to recover the tree using the following rules:
- The root node is assigned the value `0`.
- If a node has value `x`, then its left child is assigned `2 * x + 1`.
- If a node has value `x`, then its right child is assigned `2 * x + 2`.

You must implement a class `FindElements` that:
- Recovers the tree upon initialization.
- Provides a `find(int target)` function that returns `true` if the target value exists in the recovered tree, otherwise returns `false`.

### Constraints:
- The number of nodes in the tree is in the range `[1, 10^4]`.
- `TreeNode.val == -1` for all initially given nodes.
- The tree is a valid binary tree.

## Approach

### 1. **Tree Recovery Using DFS**
- We traverse the tree recursively.
- Assign values according to the recovery rules.
- Store recovered values in an `unordered_set` for quick lookup.

### 2. **Efficient Search with Hash Set**
- Instead of searching the tree directly, we use an `unordered_set<int>` to store all recovered values.
- This allows `O(1)` average time complexity for lookups.

## Code Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements {
public:
    unordered_set<int> elements;

    FindElements(TreeNode* root) {
        recover(root, 0);
    }
    
    void recover(TreeNode* node, int val) {
        if (node == nullptr) return;
        node->val = val;
        elements.insert(val);
        recover(node->left, 2 * val + 1);
        recover(node->right, 2 * val + 2);
    }
    
    bool find(int target) {
        return elements.find(target) != elements.end();
    }
};
```

## Example

### **Input:**
```cpp
TreeNode* root = new TreeNode(-1);
root->left = new TreeNode(-1);
root->right = new TreeNode(-1);
FindElements* obj = new FindElements(root);
bool res1 = obj->find(1); // true
bool res2 = obj->find(3); // false
```

### **Output:**
```cpp
true
false
```

### **Explanation:**
The recovered tree looks like:
```
      0
     / \
    1   2
```
- `find(1)` returns `true` because `1` is present.
- `find(3)` returns `false` because `3` is absent.

## Complexity Analysis

**Time Complexity:**
- `O(n)` for tree recovery (DFS traversal).
- `O(1)` average for `find()` using `unordered_set`.

**Space Complexity:**
- `O(n)` for storing node values in `unordered_set`.

## Summary
- **Recover the tree** using DFS traversal.
- **Store values** in a hash set for fast lookups.
- **Efficient `find()`** with `O(1)` average complexity.

