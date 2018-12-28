#include "Stack.h"
#include <gtest/gtest.h>
using namespace std;
class StackTest: public ::testing::Test{
};
TEST_F(StackTest, InstantZeroQ){//instantiate Q with 0 size
   ASSERT_THROW(MyStack stk(0),std::length_error);
}
TEST_F(StackTest, InsertToFull){
    MyStack stk(1);
    int item = 1;
    stk.push(item);
    ASSERT_THROW( stk.push(item),std::overflow_error);
}
TEST_F(StackTest, popFromEmpty){
    MyStack stk(1);
    int item = 1;
    stk.push(item);
    stk.pop();
    ASSERT_THROW(stk.pop(),std::underflow_error);
}
TEST_F(StackTest, MultipleAddRemove){
    // 1. can instantiate stack
    MyStack stk(10);

    // 2. can push to stack
    for(int i = 0;i<10;i++)
        stk.push(i);

    // 3. Expect overflow exception if push to full    
    ASSERT_THROW( stk.push(10),std::overflow_error);

    // 4. can peek,pop from stack
    // 5. Expect reverse order here    
    for(int i = 9;i>=0;i--)
    {
        int item = stk.peek();
        ASSERT_EQ(item,i);
        stk.pop();
    }
    // 6. Expect underflow exception if pop from empty
    ASSERT_THROW( stk.pop(),std::underflow_error);
}