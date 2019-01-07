#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <gtest/gtest.h>
using namespace std;
// Another possible solution is using regex. Here we assume we don't have regex
class Solution {
public:
    string trim(string s){
        int i = 0, j = s.size()-1;
        while(s[i]==' ')i++;
        while(s[j]==' ')j--;
        return s.substr(i,j-i+1);
    }
    bool isNumber(string s) {
        if(s.size()==0)
            return false;
        s = trim(s);
        size_t ePos = s.find('e');
        if(string::npos != ePos){// if dot found
            string base = s.substr(0,ePos);
            string exponent = s.substr(ePos+1);
            return (decimalNumber(base)&&integer(exponent));    
        }
        return (decimalNumber(s));   
    }
    bool decimalNumber(string s){
        if(s.size()==0)
            return false;
        size_t dotPos = s.find('.');
        if(string::npos != dotPos){// if dot found
            string dec = s.substr(0,dotPos);
            string frac = s.substr(dotPos+1);
            if(dec =="" && frac == "") return false;
            if(integer(dec)&& frac == "") return true;
            if((dec ==""||dec =="+"||dec =="-") && num(frac)) return true;
            if(integer(dec) && num(frac)) return true;
        }
        return (integer(s));    
    }
    bool integer(string s){// pattern: [+/-][d+]
        if(s.size()==0)
            return false;
        if(s[0] == '-' || s[0] == '+')// if has sign
            s = s.substr(1);//extract number
        return num(s);
    }
    bool num(string s){
        if(s.size()==0)
            return false;
        for(char ch:s)// check for all digit
            if(!(ch >= '0' && ch <= '9')) //if char is not digit return false
                return false;
        return true;
    }
};
//================================== TEST ================================
class testIsNumber :public testing::Test{
    public:
        Solution sol;
};
TEST_F(testIsNumber,trim){
    ASSERT_EQ(sol.trim("   omid    "),"omid");
}
TEST_F(testIsNumber,falseCases){
    ASSERT_FALSE(sol.isNumber("abc"));
    ASSERT_FALSE(sol.isNumber("1 a"));
    ASSERT_FALSE(sol.isNumber(" 1e"));
    ASSERT_FALSE(sol.isNumber("e3"));
    ASSERT_FALSE(sol.isNumber(" 99e2.5 "));//?
    ASSERT_FALSE(sol.isNumber(" --6 "));
    ASSERT_FALSE(sol.isNumber("-+3"));
    ASSERT_FALSE(sol.isNumber("95a54e53"));
    ASSERT_FALSE(sol.isNumber("."));
    ASSERT_FALSE(sol.isNumber("1 ."));
    ASSERT_FALSE(sol.isNumber(".-4"));//!

}
TEST_F(testIsNumber,trueCases){
    ASSERT_TRUE(sol.isNumber("0"));
    ASSERT_TRUE(sol.isNumber(".1"));
    ASSERT_TRUE(sol.isNumber("3."));
    ASSERT_TRUE(sol.isNumber(" 0.1 "));
    ASSERT_TRUE(sol.isNumber("2e10" ));
    ASSERT_TRUE(sol.isNumber(" -90e3   "));
    ASSERT_TRUE(sol.isNumber(" 6e-1"));
    ASSERT_TRUE(sol.isNumber("53.5e93"));
    ASSERT_TRUE(sol.isNumber("+.8"));//!

}