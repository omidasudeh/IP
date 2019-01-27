/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

Example 1:

Input: "1 + 1"
Output: 2

Example 2:

Input: " 2-1 + 2 "
Output: 3

Example 3:

Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23
*/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        vector<int> operands;
        string operators;
        if(s == "")
            return 0;
        for(int i = 0;i<s.size();){
            int j=i;
            int number = 0;
            for(;j<s.size()&& s[j]>='0' && s[j]<='9';j++){
                number= 10*number+(s[j]-'0');
            }
            if(j>i){// if a number was fetched
                operands.push_back(number);
                i = j;
            }
            else if(s[i] == '(' || s[i] == '*'){
                operators.push_back(s[i]);
                i++;
            }
            else if(s[i] == '+'){
                if( operators.back()== '+' || operators.back()== '('){
                    operators.push_back(s[i]);
                }
                else{
                    while(operators.size()>0 && 
                          operators.back() != '+' && 
                          operators.back() != '('){
                        int op2 = operands.back();operands.pop_back();
                        int op1 = operands.back();operands.pop_back();
                        if(operators.back()=='-'){
                        operands.push_back(op1-op2);
                        }
                        else if(operators.back()=='*'){
                            operands.push_back(op1*op2);
                        }
                        operators.pop_back();
                    }
                    operators.push_back('+');
                }
                i++;
            }
            else if(s[i] == '-'){
                if(operators.empty() ||operators.back()== '('){
                    operators.push_back(s[i]);
                }
                else{
                    while(operators.back() != '(' && operators.size()>0){
                        int op2 = operands.back();operands.pop_back();
                        int op1 = operands.back();operands.pop_back();
                        if(operators.back()=='-'){
                        operands.push_back(op1-op2);
                        }
                        else if(operators.back()=='+'){
                            operands.push_back(op1+op2);
                        }
                        else if(operators.back()=='*'){
                            operands.push_back(op1*op2);
                        }
                        operators.pop_back();
                    }
                    operators.push_back('-');
                }
                i++;
            }
            else if(s[i] == ')'){
                while(operators.back() != '(' && operators.size()>0){
                    int op2 = operands.back();operands.pop_back();
                    int op1 = operands.back();operands.pop_back();
                    if(operators.back()=='+'){
                        operands.push_back(op1+op2);
                    }
                    else if(operators.back()=='-'){
                        operands.push_back(op1-op2);
                    }
                    else if(operators.back()=='*'){
                        operands.push_back(op1*op2);
                    }
                    operators.pop_back();
                }
                if(operators.size()==0)
                    __throw_logic_error("paranthesis does not match");
                operators.pop_back();// pop (
                i++;
            }
            else{//any other char => ignore
                i++;
            }
        }
        while(operators.size()>0){
            int op2 = operands.back();operands.pop_back();
            int op1 = operands.back();operands.pop_back();
            if(operators.back()=='+'){
                operands.push_back(op1+op2);
            }
            else if(operators.back()=='-'){
                operands.push_back(op1-op2);
            }
            else if(operators.back()=='*'){
                operands.push_back(op1*op2);
            }
            operators.pop_back();
        }
        return operands.back();
    }
    
};
int main (){
    Solution s;
    assert((2 == s.calculate("   1 + 1")));
    assert((0 == s.calculate("0")));
    assert((3 == s.calculate(" 2-1 + 2 ")));
    assert((23 == s.calculate("(1+(4+5+2)-3)+(6+8)")));
    cout<<"all test cases passed!\n";
    return 0;
}