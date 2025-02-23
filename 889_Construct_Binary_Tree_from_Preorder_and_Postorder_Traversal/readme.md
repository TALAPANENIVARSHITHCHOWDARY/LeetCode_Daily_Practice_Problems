# 889. Construct Binary Tree from Preorder and Postorder Traversal

## Problem Statement
Given two integer arrays `preorder` and `postorder`, which represent the preorder and postorder traversal of a full binary tree respectively, construct and return the binary tree.

### Constraints:
- `1 <= preorder.length <= 30`
- `preorder.length == postorder.length`
- All values of `preorder` are unique.
- All values of `postorder` are unique.
- It is guaranteed that the given traversals are from a full binary tree.

## Approach

1. **Recursive Construction:**
   - The first element of `preorder` represents the root.
   - The last element of `postorder` represents the root of the subtree being constructed.
   - The left subtree is built first by identifying the left child and recursively constructing the subtree.
   - The right subtree is constructed next if there are remaining elements in `preorder`.
   - This continues until the entire tree is reconstructed.

2. **Tracking Indices:**
   - Maintain indices (`pr_ind` for `preorder` and `pos_ind` for `postorder`) to track progress.
   - Recursively build left and right subtrees based on the order constraints.

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
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        int pr_ind = 0;
        int pos_ind = 0;
        return func(pr_ind, pos_ind, preorder, postorder);
    }
private:
    TreeNode* func(int& pr_ind, int& pos_ind,
                            vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode(preorder[pr_ind]);
        pr_ind++;
        if (root->val != postorder[pos_ind]) {
            root->left =
                func(pr_ind, pos_ind, preorder, postorder);
        }
        if (root->val != postorder[pos_ind]) {
            root->right =
                func(pr_ind, pos_ind, preorder, postorder);
        }
        pos_ind++;
        return root;
    }
};
```

## Example

**Input:**
```cpp
preorder = [1,2,4,5,3,6,7]
postorder = [4,5,2,6,7,3,1]
```

**Output:**
```cpp
    1
   / \
  2   3
 / \  / \
4   5 6  7
```

## Complexity Analysis

- **Time Complexity:** O(n)
  - Each node is visited once in preorder and postorder, leading to a linear time complexity.
- **Space Complexity:** O(n)
  - The recursive stack takes O(n) space in the worst case (skewed tree).

## Usage
```cpp
int main() {
    Solution sol;
    vector<int> preorder = {1,2,4,5,3,6,7};
    vector<int> postorder = {4,5,2,6,7,3,1};
    TreeNode* root = sol.constructFromPrePost(preorder, postorder);
    return 0;
}
```



