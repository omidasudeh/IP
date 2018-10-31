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
    bool pathSum(TreeNode *root, int c, int target) {
        if (!root) return false;
        c += root->val;
        if (root->left == NULL && root->right == NULL) {
            if (c == target) return true;
            else return false;
        }
        return pathSum(root->left, c, target) || pathSum(root->right, c, target);
    }
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root) {
            return pathSum(root, 0, sum);
        }
        else return false;
    }
};
