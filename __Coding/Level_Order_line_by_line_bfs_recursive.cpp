/* 
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
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
    vector<vector<int>> ans;
    vector<int> temp;
public:
    int height(TreeNode* root){
        if(root == 0)
            return 0;
        return 1+max(height(root->left), height(root->right));
    }
    void printGivenLevel(TreeNode* root, int level) 
    { 
        if (root == NULL) 
            return; 
        if (level == 1) 
            temp.push_back(root->val);
        else if (level > 1) 
        { 
            printGivenLevel(root->left, level-1); 
            printGivenLevel(root->right, level-1); 
        } 
    } 
    vector<vector<int>> levelOrder(TreeNode* root) {
        int h = height(root);
        for(int i = 1;i<=h;i++){
            printGivenLevel(root,i);
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};