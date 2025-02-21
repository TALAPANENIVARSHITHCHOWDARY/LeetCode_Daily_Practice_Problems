#include<bits/stdc++.h>
using namespace std;
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
class FindElements {
    public:
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
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */