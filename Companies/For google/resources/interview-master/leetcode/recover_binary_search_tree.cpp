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
    void recover(TreeNode *root, TreeNode * &now, TreeNode * &left, TreeNode * &right) {
        if (root == NULL) return;
        recover(root->left, now, left, right);
        if (now && now->val > root->val) {
            if (!left) left = now, right = root;
            else right = root;
        }
        now = root;
        recover(root->right, now, left, right);
    }
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode *left = NULL, *right = NULL, *now = NULL;
        recover(root, now, left, right);
        swap(left->val, right->val);
    }
};
