#include <gtest/gtest.h>
#include <iostream>
using namespace std;

int fact(int val)
{
    if(val<0)
        return 0;
    int f0 = 1;
    int f1 = 1;
    int f2 = 2;
    if(val == 0 )
        return f0;
    if(val == 1 )
        return f1;
    if(val == 2)
        return f2;
    for(int i=3 ; i<=val;i++)
    {
        f0 = f1;
        f1 = f2;
        f2 = f1 + f0;
    }
    return f2;
}
TEST(fact_0, fact0is1)
{
    ASSERT_EQ(fact(0),1);
}
TEST(fact_neg, factNeg0)
{
    ASSERT_EQ(fact(-1),0);
}
TEST(factorial, factRecursive)
{
    ASSERT_EQ(fact(5),fact(4)+fact(3));
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}