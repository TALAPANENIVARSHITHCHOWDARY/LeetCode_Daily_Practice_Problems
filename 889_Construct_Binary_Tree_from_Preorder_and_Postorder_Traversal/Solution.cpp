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