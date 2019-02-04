/* 
Given a binary tree, return the zigzag level order traversal of its nodes' values.
 (ie, from left to right, then right to left for the next level and alternate between).
 */
/*
using two stack
We can insert the first level in first stack and print it and while
popping from the first stack insert its "left and right in order" nodes into the
second stack. Now start printing the second stack and before popping insert
its "right and left in order" child nodes into the first stack. Continue this process
till both the stacks become empty.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };		
ZigZag
ZigZag
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == 0)
            return ans;
        vector<TreeNode*> stk1;
        vector<TreeNode*> stk2;
        stk1.push_back(root);
        bool first_turn = true;
        vector<int> temp;
        while(!stk1.empty() || !stk2.empty()){
            temp.clear();
            if(first_turn){
                while(!stk1.empty()){
                    TreeNode* t = stk1.back();
                    temp.push_back(t->val);
                    if(t->left){
                        stk2.push_back(t->left);
                    }
                    if(t->right){
                        stk2.push_back(t->right);
                    }
                    stk1.pop_back();
                }
                first_turn = false;
            }
            else{
                 while(!stk2.empty()){
                    TreeNode* t = stk2.back();
                    temp.push_back(t->val);
                    if(t->right){
                        stk1.push_back(t->right);
                    }
                    if(t->left){
                        stk1.push_back(t->left);
                    }
                    stk2.pop_back();
                }
                first_turn = true;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};