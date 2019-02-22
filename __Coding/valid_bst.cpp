/*
98. Validate Binary Search Tree
Medium

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

Example 1:

Input:
    2
   / \
  1   3
Output: true

Example 2:

    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int min(TreeNode* root){
        while(root->left)
            root = root->left;
        return root->val;
    }
    int max(TreeNode* root){
        while(root->right)
            root = root->right;
        return root->val;
    }
    bool isValidBST(TreeNode* root) {
        if(root == 0)
            return true;
        if(isValidBST(root->left)  &&
           isValidBST(root->right)){
            bool left_ok = true;
            bool right_ok = true;
            
            if(root->left){
                left_ok = max(root->left) < root->val;
                // cout<<max(root->left)<<":" << root->val<<":"<<left_ok<<endl;
            }
            if(root->right){
                right_ok = min(root->right) > root->val;
                // cout<<min(root->right)<<":" << root->val<<":"<<right_ok<<endl;
            }
            if(left_ok && right_ok)
                // cout<<root->val<<"is bst\n";
            return left_ok && right_ok;
        }
        return false;
        // left subtree should be BST
        // right subtree should be BST
        // max of left subtree should be less than root value
        // min of right subtree should be greater than root value
    }
};