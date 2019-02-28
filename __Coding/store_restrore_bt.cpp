/* 
297. Serialize and Deserialize Binary Tree
Hard

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Example: 

You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"

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
// #include <sstream>
class Codec {
public:
    //preorder
    void preorder(TreeNode* root, string& pre){
        if(root == 0) {
            pre+="- ";  
            return;
        }
        pre+= to_string(root->val)+" ";
        preorder(root->left, pre);
        preorder(root->right,pre);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == 0)
            return "";
        string pre = "";
        preorder(root, pre);
        // cout<<pre<<endl;
        return pre;
    }
    // rebuild the tree from preorder traversals
    TreeNode* rebuild(vector<string> & pre, int& pre_pt){
        cout<<pre_pt<<" ";
        if(pre[pre_pt] == "-"){
            return 0;
        }
        TreeNode* root = new TreeNode(stoi(pre[pre_pt]));
        root->left  = rebuild(pre, ++pre_pt);
        root->right = rebuild(pre, ++pre_pt);
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)
            return 0;
        istringstream iss(data);
        string tmp = "";
        int pre_pt = 0;
        vector<string> dt;
        while(iss>>tmp){
            dt.push_back(tmp);
        }
        return rebuild(dt, pre_pt);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));