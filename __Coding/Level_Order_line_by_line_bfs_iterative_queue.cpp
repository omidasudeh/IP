/* 
Given a binary tree, return the level order traversal of its nodes' values.
 (ie, from left to right, level by level).
 */
/*
using two queues
We can insert the first level in first queue and print it and while
popping from the first queue insert its left and right nodes into the
second queue. Now start printing the second queue and before popping insert
its left and right child nodes into the first queue. Continue this process
till both the queues become empty.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == 0)
            return ans;
        queue<TreeNode*> first;
        queue<TreeNode*> second;
        first.push(root);
        bool first_turn = true;
        vector<int> temp;
        while(!first.empty() || !second.empty()){
            temp.clear();
            if(first_turn){
                while(!first.empty()){
                    TreeNode* t = first.front();
                    temp.push_back(t->val);
                    if(t->left)
                        second.push(t->left);
                    if(t->right)
                        second.push(t->right);
                    first.pop();
                }
                first_turn = false;
            }
            else{//second turn
                while(!second.empty()){
                    TreeNode* t = second.front();
                    temp.push_back(t->val);
                    if(t->left)
                        first.push(t->left);
                    if(t->right)
                        first.push(t->right);
                    second.pop();
                }
                first_turn = true;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};