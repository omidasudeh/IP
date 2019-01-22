/* 
Given a string in infix notation with (,), +,* build the postfix notation
*/
#include <string>
#include <sstream>
#include <vector>
#include <gtest/gtest.h>
#include <iostream>
using namespace std;
bool isNum(string str){
    for(char ch : str){
        if(ch > '9' || ch <'0')
            return false;
    }
    return true;
}
string infixToPostfix(string infix){
    vector<string> stk1;
    vector<string> stk2;

    if(infix == "")
        return "";
    istringstream iss(infix);
    string token = "";
    while(iss>>token){
        if(isNum(token)){
            stk1.push_back(token);
        }
        else if(token == "(" || token == "*"){
            stk2.push_back(token);
        }
        else if(token == "+"){
            if(stk2.empty() || stk2.back()!="*"){
                stk2.push_back(token);
            }
            else{
                while(stk2.back() == "*" && stk2.size()>0){
                    stk2.pop_back();
                    stk1.push_back("*");
                }
            }
        }
        else if(token == ")"){
            while(stk2.back()!="(" && stk2.size()>0){
                stk1.push_back(stk2.back());
                stk2.pop_back();
            }
            if(stk2.size()==0)
                __throw_logic_error("paranthesis does not match");
            stk2.pop_back();// pop (
        }
        else{
            string msg = ("token "+token+" is not defined");
            __throw_logic_error(&msg[0]);
        }
    }
    string result = "";
    for(string str:stk1){
        result = result+((result == "")?"":" ") +str;
    }
    return result;
}
TEST(inToPost, test){
    string infix = "( 4 + ( ( 1 + 2 ) * 3 ) )";
    ASSERT_EQ(infixToPostfix(infix),"4 1 2 + 3 * +");
}