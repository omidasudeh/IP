#include "BST.h"
#include <iostream>
#include <gtest/gtest.h>
using namespace std;
class BSTTest: public ::testing::Test{
};
TEST_F(BSTTest, BuildTree_NULLArray){
//- EXCEPT: NULL array
    ASSERT_THROW(MyBST bst(NULL,4), std::length_error);
}
TEST_F(BSTTest, BuildTree){
// - EXCEPT: 0/neg size array   
   int arr[0];
   ASSERT_THROW(MyBST bst(arr,0), std::length_error);
}
TEST_F(BSTTest, NotFindKey){
// - Expect NULL if not found    
    int keys[7] = {2,10,12,6,3,15,9};
    MyBST bst(keys,7); 
    ASSERT_EQ(NULL, bst.Find(22));
}
TEST_F(BSTTest, NotFindKeyEmptyTree){
// -Expect key not found
    MyBST bst;
    ASSERT_EQ(NULL, bst.Find(22));

}
TEST_F(BSTTest, FindKey){
// -Expect key  = found key
    int keys[7] = {2,10,12,6,3,15,9};
    MyBST bst(keys,7);
    for(int i=0;i<7;i++){
        int key = keys[i];
        int foundKey = bst.Find(key)->Key;
        ASSERT_EQ(foundKey, key);
    }
}
TEST_F(BSTTest, InsertKey){
// -Expect key  = found key
    MyBST bst; 
    int keys[7] = {2,10,12,6,3,15,9};   
    bst.Insert(2);
    bst.Insert(10);
    bst.Insert(12);
    bst.Insert(6);
    bst.Insert(3);
    bst.Insert(15);
    bst.Insert(9);
    for(int i=0;i<7;i++){
        int key = keys[i];
        int foundKey = bst.Find(key)->Key;
        ASSERT_EQ(foundKey, key);
    }
}
TEST_F(BSTTest, DeleteLeaf){
//  Delete leaf and then try to find it
// -Expect not found 
    int keys[7] = {2,10,12,6,3,15,9};
    MyBST bst(keys,7);
    bst.Delete(6);
    ASSERT_EQ(NULL, bst.Find(6));
}
TEST_F(BSTTest, DeleteNodeWithOneSubtree){
//  Delete node with one subtree and then try to find it
// -Expect not found 
/*
                            11
                    /                   \
                    2                   15*
                /       \               /
                1       *3             13
                            \          / \
                            7*         12 14
                        /       \
                        4       10
                            \   /   \
                            6   8   9 
                        /     
                        5   
*/
    MyBST bst; 
    bst.Insert(11);
    bst.Insert(15);
    bst.Insert(13);
    bst.Insert(12);
    bst.Insert(14);
    bst.Insert(2);
    bst.Insert(1);
    bst.Insert(3);
    bst.Insert(7);
    bst.Insert(4);
    bst.Insert(6);
    bst.Insert(5);
    bst.Insert(9);
    bst.Insert(8);
    bst.Insert(10);

    bst.Delete(15); //delete node with no right subtree
    ASSERT_EQ(NULL, bst.Find(15));
    bst.Delete(3); //delete node with no left subtree
    ASSERT_EQ(NULL, bst.Find(3));
    
}
TEST_F(BSTTest, DeleteNodeWithTwoSubtrees){
//  Delete node with both subtree and then try to find it
// -Expect not found 
/*
                            11
                    /                   \
                    2                   15*
                /       \               /
                1       *3             13
                            \          / \
                            7*         12 14
                        /       \
                        4       9
                            \   /   \
                            6   8   10 
                        /
                        5       
*/
    MyBST bst; 
    bst.Insert(11);
    bst.Insert(15);
    bst.Insert(13);
    bst.Insert(12);
    bst.Insert(14);
    bst.Insert(2);
    bst.Insert(1);
    bst.Insert(3);
    bst.Insert(7);
    bst.Insert(4);
    bst.Insert(6);
    bst.Insert(5);
    bst.Insert(9);
    bst.Insert(8);
    bst.Insert(10);
    
    bst.Delete(7); //delete node having both subtrees
    ASSERT_EQ(NULL, bst.Find(7));
}

TEST_F(BSTTest, Successor){
//  compute successor for all nodes of the tree and compare it with the actual value
/*
                            11
                    /                   \
                    2                   15*
                /       \               /
                1       *3             13
                            \          / \
                            7*         12 14
                        /       \
                        4       9
                            \   /   \
                            6   8   10 
                        /
                        5       
*/
    MyBST bst; 
    bst.Insert(11);
    bst.Insert(15);
    bst.Insert(13);
    bst.Insert(12);
    bst.Insert(14);
    bst.Insert(2);
    bst.Insert(1);
    bst.Insert(3);
    bst.Insert(7);
    bst.Insert(4);
    bst.Insert(6);
    bst.Insert(5);
    bst.Insert(9);
    bst.Insert(8);
    bst.Insert(10);
    TreeNode* node = bst.Find(6);
    int succ = bst.successor(node)->Key;
    ASSERT_EQ(7,succ);

    for(int i = 1;i<15;i++)
    {
        TreeNode* node = bst.Find(i);
        int succ = bst.successor(node)->Key;
        ASSERT_EQ(i+1,succ);
    }
}