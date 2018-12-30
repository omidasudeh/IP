#include "treeNode.h"
#ifndef MYBST_H
#define MYBST_H
class MyBST
{
  private:
    TreeNode* root;
    void Insert_helper(int, TreeNode*, TreeNode*);
    void Delete_helper(int, TreeNode*, TreeNode*);
  public:

  //============ Constructor, Destructor============================
    MyBST();
    MyBST(int*,int);
    ~MyBST();
  //============ main operations: build, insert, delete ============

    /*
    - build a BST of and array
    - input an int array
    - O(n)
    */
    TreeNode* buildBST(int*, int, int);
    
    /*
    - insert element to the BST
    - O(h)
    */
   void Insert(int);

   /*
    - Delete element from the BST
    - O(h)
    */
   void Delete(int);

    /*
    -  insert element to the BST
    - O(h)
    */
   TreeNode* Find(int);

  //============ Traversal ========================================
   /*
   in-order,pre-order, post-order traversals
   */
  void inOrder();
  void preOrder();
  void postOrder();

  //============ other: min, max, succ, predec ====================
  /*
  - find the next inorder element
  */
  TreeNode* successor(TreeNode*);

  /*
  - find the previous inorder element
  */
  TreeNode* predecessor(TreeNode*);

  /*
  - find the min element in the subtree
  */
  pair<TreeNode*, TreeNode*> FindMin(TreeNode*,TreeNode*);
  /*
  - find the max element in the subtree
  */
  pair<TreeNode*, TreeNode*> FindMax(TreeNode*,TreeNode*);

};
#endif