#include "node.h"
#include "hashMap.h"
#include <iostream>
#include <gtest/gtest.h>
using namespace std;
class HashMapTest: public ::testing::Test{
};
TEST_F(HashMapTest, insert){
    // insert an item empty and non-empty buckets. Expect to be able to find it
    HashMap map(10);

    node* t = new node(1,123);
    map.insert(t);//insert to empty bucket
    ASSERT_EQ(map.search(t->key),t);

    node* t1 = new node(11,123);
    map.insert(t1);//insert to non-empty bucket
    ASSERT_EQ(map.search(t1->key),t1);
}
TEST_F(HashMapTest, search){
    // expect not found return null 
    HashMap map(10);
    node* f = map.search(123);
    ASSERT_TRUE(f == 0);

    // expect finding an item that is only item in the bucket
    node* t = new node(1,123);
    map.insert(t);//insert to empty bucket:1
    ASSERT_EQ(map.search(t->key),t);

    // expect finding an item that is head/tail 
    node* t1 = new node(11,123);
    map.insert(t1);//insert to non-empty bucket:11->1
    ASSERT_EQ(map.search(t->key),t);
    ASSERT_EQ(map.search(t1->key),t1);

    // expect finding an item that is head/tail/mid 
    node* t2 = new node(111,123);
    map.insert(t2);//insert to non-empty bucket:111->11->1
    ASSERT_EQ(map.search(t->key),t);
    ASSERT_EQ(map.search(t1->key),t1);
    ASSERT_EQ(map.search(t2->key),t2);
}
TEST_F(HashMapTest, Delete){
    HashMap map(10);

    // delete an item that is not in the table
    node* t = new node(1,123);
    map.Delete(t);
    ASSERT_TRUE(map.search(t->key) == 0);

    map.insert(t);//insert to empty bucket:1
    node* t1 = new node(11,123);
    map.insert(t1);
    node* t2 = new node(111,123);
    map.insert(t2);
    node* t3 = new node(1111,123);
    map.insert(t3);

    map.Delete(t2);//delete from middle
    map.Delete(t3);//delete head
    map.Delete(t);//delete tail
    map.Delete(t1);//delete tail

    ASSERT_TRUE(map.search(t->key) == 0);
    ASSERT_TRUE(map.search(t1->key) == 0);
    ASSERT_TRUE(map.search(t2->key) == 0);
    ASSERT_TRUE(map.search(t3->key) == 0);
}