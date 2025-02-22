#include <string>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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