#include "heap.h"
#include <gtest/gtest.h>
class testHeap : public ::testing::Test{
};
TEST_F(testHeap, instant)
{
    vector<int>* vec = new vector<int>;
    (*vec).push_back(12);
    (*vec).push_back(2);
    (*vec).push_back(6);
    (*vec).push_back(8);
    (*vec).push_back(11);
    (*vec).push_back(3);
    (*vec).push_back(5);
    Heap h(vec);
    int premin = h.delete_min();
    for(int i = 1;i<7;i++)//test output is sorted
    {
        int min = h.delete_min();
        ASSERT_TRUE(premin<=min);
        premin = min;
    }
}