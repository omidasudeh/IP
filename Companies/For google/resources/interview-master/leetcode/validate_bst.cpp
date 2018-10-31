/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool checkless(TreeNode *root, int &v) {
        if (!root) return true;
        if (root->val >= v) return false;
        return checkless(root->left, v) && checkless(root->right, v);
    }
    bool checkgreater(TreeNode *root, int &v) {
        if (!root) return true;
        if (root->val <= v) return false;
        return checkgreater(root->left, v) && checkgreater(root->right, v);
    }
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return true;
        if (root->left && !checkless(root->left, root->val)) return false;
        if (root->right && !checkgreater(root->right, root->val)) return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }
};
