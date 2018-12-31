#include "BST.h"
#include <iostream>
#include <stdexcept>
#include <bits/stdc++.h> 
#include <utility>// for pair data-structure
using namespace std;
MyBST::MyBST(int* arr,int size){
    if(arr == NULL)
        throw(std::length_error("Can\'t make a BST of a NULL array"));
    if(size<1)
        throw(std::length_error("array size error"));  
    sort(arr, arr+size); 
    root = buildBST(arr, 0, size-1);
}
MyBST::MyBST():root(NULL){
}
MyBST::~MyBST(){
    while(root!=NULL)
        Delete(root->Key);
}
TreeNode* MyBST::buildBST(int* arr, int left, int right){
    if(left == right){
        TreeNode* leaf = new TreeNode(arr[left],0);
        return leaf;
    }

    if(left<right)
    {
        int m = (left+right)>>1;
        TreeNode* newNode = new TreeNode(arr[m],0);
        newNode->left = buildBST(arr, left, m-1);
        newNode->right = buildBST(arr, m+1, right);
        return newNode;
    }
    return NULL;
}
void MyBST::Insert_helper(int key, TreeNode* parent, TreeNode* cur){
    if((cur == NULL) && (parent == NULL))//empty tree
    {
        root = new TreeNode(key,0);
        return;
    }
    if((cur == NULL) && (parent != NULL))//insert node
    {
        TreeNode* newNode = new TreeNode(key,0);
        if(parent->Key > key)
            parent->left = newNode;
        else//if(parent->key < key)
            parent->right = newNode;
        return;
    }
    if(cur->Key > key)
    {
        Insert_helper(key, cur, cur->left);
        return;
    }
    if(cur->Key <= key)
    {
        Insert_helper(key, cur, cur->right);
        return;
    }
}
void MyBST::Insert(int key){
    Insert_helper(key,NULL,root);

}
void MyBST::Delete_helper(int key, TreeNode* parent, TreeNode* cur){
    if(cur == NULL) //not found ==> return
    {
        return;
    }
    if(cur != NULL) //might be found
    {
        if(cur->Key > key)//might be in the left subtree
        {
            Delete_helper(key, cur, cur->left);
            return;
        }
        if(cur->Key < key)//might be in the right subtree
        {
            Delete_helper(key, cur, cur->right);
            return;
        }
        if(cur->Key == key)//found ==> delete
        {
            /*
            Three cases:
            case 1: if the node to remove has no subtree
                - just remove the node
            case 2: if the node to remove has only one subtree
                - successor is the root of the subtree
            case 3: if the node to remove has both two subtree
                - Find the successor
                - replace the node with successor value
                - recursively remove the successor            
            */
            // case1: node is leaf
            if(cur->left == NULL && cur->right == NULL){

                if(parent == NULL)//if root
                {
                    root = NULL;
                    delete cur;
                    return;
                }
                if(cur == parent->left)
                {
                    parent->left = NULL;
                    delete cur;
                    return;
                }
                if(cur == parent->right)
                {
                    parent->right = NULL;
                    delete cur;
                    return;
                }
                __throw_logic_error;
            }
            // case2.1: node has only the left subtree
            if(cur->left != NULL && cur->right == NULL){

                if(parent == NULL)//if cur == root
                {
                    root = cur->left;
                    delete cur;
                    return;
                }
                if(cur == parent->left)
                {
                    parent->left = cur->left;
                    delete cur;
                    return;
                }
                if(cur == parent->right)
                {
                    parent->right = cur->left;
                    delete cur;
                    return;
                }
                __throw_logic_error;
            }
            // case2.2: node has only the right subtree
            if(cur->left == NULL && cur->right != NULL){
                if(parent == NULL)//if cur == root
                {
                    root = cur->right;
                    delete cur;
                    return;
                }
                if(cur == parent->left)
                {
                    parent->left = cur->right;
                    delete cur;
                    return;
                }
                if(cur == parent->right)
                {
                    parent->right = cur->right;
                    delete cur;
                    return;
                }
                __throw_logic_error;
            }
            // case3: node has two subtrees
            pair<TreeNode*, TreeNode*> tmp = FindMin(cur,cur->right);//find successor in the right subtree
            TreeNode* succ = tmp.second;
            TreeNode* succ_parent = tmp.first;
            cur->Key = succ->Key;// replace the node with the successor
            Delete_helper(succ->Key, succ_parent, succ);//delete the successor  
            return;  
        }     
        __throw_logic_error;
    }

}
void MyBST::Delete(int key){
    Delete_helper(key, NULL, root);
}
TreeNode* Find_helper(int key, TreeNode* t){
    if(t == NULL)//empty tree
        return NULL;

    if(t->Key == key)//found in the node
        return t;
    else if(t->Key > key) // might be in the left subtree
        return Find_helper(key,t->left);
    else// might be in the right subtree
        return Find_helper(key,t->right);
}
TreeNode* MyBST::Find(int key){
    if(root==NULL)//empty tree
        return NULL;
    return Find_helper(key, root);
}
void inorder_helper(TreeNode* t){
    if(t == NULL)
        return;
    inorder_helper(t->left);
    cout<<t->Key<<",";
    inorder_helper(t->right);
}
void MyBST::inOrder(){
    inorder_helper(root);
}
void preorder_helper(TreeNode* t){
    if(t == NULL)
        return;
    cout<<t->Key<<",";
    preorder_helper(t->left);
    preorder_helper(t->right);
}
void MyBST::preOrder(){
    preorder_helper(root);
}
void postorder_helper(TreeNode* t){
    if(t == NULL)
        return;
    postorder_helper(t->left);
    postorder_helper(t->right);
    cout<<t->Key<<",";
}
void MyBST::postOrder(){
    postorder_helper(root);
}
pair<TreeNode*,TreeNode*> MyBST::FindMin(TreeNode* parent,TreeNode* current)
{
    TreeNode* par = parent;
    TreeNode* cur = current;
    while(cur->left!=NULL)
    {
        par = cur;
        cur = cur->left;
    }
    pair<TreeNode*, TreeNode*> r(par,cur);
    return r;
}
pair<TreeNode*,TreeNode*> MyBST::FindMax(TreeNode* parent,TreeNode* current)
{
    TreeNode* par = parent;
    TreeNode* cur = current;
    while(cur->right!=NULL)
    {
        par = cur;
        cur = cur->right;
    }
    pair<TreeNode*, TreeNode*> r(par,cur);
    return r;
}

TreeNode* MyBST::successor(TreeNode* node)
{
    if(node == NULL)
        return NULL;
    if(node->right != NULL){
        return (FindMin(node, node->right).second);
    }
    TreeNode* par = NULL;
    TreeNode* cur = root;
    TreeNode* succ = NULL;
    while(cur!=node)
    {
        if(cur->Key > node->Key){
            succ = cur;
            cur = cur->left;
        }
        else
            cur = cur->right;
    }
    return succ;
}