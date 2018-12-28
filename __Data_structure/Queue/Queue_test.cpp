#include "Queue.h"
#include <gtest/gtest.h>
using namespace std;
class QueueTest: public ::testing::Test{
};
TEST_F(QueueTest, InstantZeroQ){//instantiate Q with 0 size
   ASSERT_THROW(MyQueue q(0),std::length_error);
}
TEST_F(QueueTest, InsertToFull){
    MyQueue q(1);
    int item = 1;
    q.insert(item);
    ASSERT_THROW( q.insert(item),std::overflow_error);
}
TEST_F(QueueTest, removeFromEmpty){
    MyQueue q(1);
    int item = 1;
    q.insert(item);
    int a = q.remove();
    ASSERT_THROW(a = q.remove(),std::underflow_error);
}
TEST_F(QueueTest, MultipleAddRemove){
    MyQueue q(10);
    for(int i = 0;i<10;i++)
        q.insert(i);
    ASSERT_THROW( q.insert(10),std::overflow_error);
    for(int i = 0;i<10;i++)
        q.remove();
    ASSERT_THROW( q.remove(),std::underflow_error);
}