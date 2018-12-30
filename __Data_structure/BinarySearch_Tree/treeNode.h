#include <iostream>
using namespace std;
#ifndef TREENODE_H
#define TREENODE_H
struct TreeNode
{
  TreeNode* left;
  TreeNode* right;
  int Key;
  int Value;
  TreeNode(int k,int v):Key(k), Value(v),left(NULL),right(NULL){}
};
#endif