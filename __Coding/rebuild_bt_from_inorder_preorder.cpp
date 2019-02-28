/* 
105. Construct Binary Tree from Preorder and Inorder Traversal
Medium

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]

Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre_pt = 0;
        return rebuild(preorder,inorder,pre_pt, 0, inorder.size()-1);
    }
    //find a string in a vector of strings within the left and right range
    int find(vector<int>& data, int left, int right, int key){
        if(left<0 || right>=data.size())
            return -2; // boundary error
        for(int i = left; i<=right;i++)
            if(key == data[i])
                return i; // found
        return -1; // not found
    }
    //rebuild the tree from the inorder and preorder traversals
    TreeNode* rebuild(vector<int> & pre, vector<int>& in, int& pre_pt, int in_left, int in_right){
        if(in_left>in_right)
            return 0;
        if(in_left == in_right){
            TreeNode* t = new TreeNode(pre[pre_pt]);
            return t;
        }
        TreeNode* root = new TreeNode(pre[pre_pt]);
        int i = find(in, in_left, in_right, pre[pre_pt]);
        root->left = (in_left<=i-1)?rebuild(pre,in, ++pre_pt, in_left, i-1):0;
        root->right =(i+1<=in_right)? rebuild(pre,in, ++pre_pt, i+1, in_right):0;
        return root;
    }
    
};