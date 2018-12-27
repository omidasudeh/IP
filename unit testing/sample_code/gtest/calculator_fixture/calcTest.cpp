#include <gtest/gtest.h>
#include "calc.h"

using namespace std;

class CalcTests : public ::testing::Test {
public:

protected:
	calculator c;
};

//// 1. factorial tests
TEST_F(CalcTests, fact0is1)
{
    ASSERT_EQ(c.fact(0),1);
}
TEST_F(CalcTests, factNeg0)
{
    ASSERT_EQ(c.fact(-1),0);
}
TEST_F(CalcTests, factRecursive)
{
    ASSERT_EQ(c.fact(5),c.fact(4)+c.fact(3));
}

//// 2. factorial tests
TEST_F(CalcTests,DivByZero)
{
    ASSERT_THROW(c.div(1,0),std::domain_error);
}
TEST_F(CalcTests,DivbyNeg)
{
    float r = (c.div(1,-5)+.2);
    r = (r<0)?r:-r;
    ASSERT_LT(r,0.00001);
}