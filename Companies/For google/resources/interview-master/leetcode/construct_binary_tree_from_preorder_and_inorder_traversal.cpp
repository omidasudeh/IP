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
    TreeNode *build(vector<int> &preorder, int l1, int r1, vector<int> &inorder, int l2, int r2) {
        if (l1 >= r1) return NULL;
        TreeNode *now = new TreeNode(preorder[l1]);
        for (int i = l2; i < r2; ++i) {
            if (inorder[i] == preorder[l1]) {
                int left = i - l2, right = r2 - i;
                now->left = build(preorder, l1 + 1, l1 + left + 1, inorder, l2, l2 + left);
                now->right = build(preorder, l1 + left + 1, r1, inorder, l2 + left + 1, r2);
                break;
            }
        }
        return now;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
