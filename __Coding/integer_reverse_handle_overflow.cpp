/*
7. Reverse Integer
Easy

Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321

Example 2:

Input: -123
Output: -321

Example 3:

Input: 120
Output: 21

Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

*/
class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN)
            return 0;
        int sign = (x>=0)?1:-1;
        if(sign == -1)
            x = -x;
        int result = 0;
        while(x>0){
            if((INT_MAX-(x%10))/10>= result)
            {
                result =10*result+(x%10);
                x/=10;
            }
            else{
                return 0;
            }
        }
        return sign*result;
    }
};