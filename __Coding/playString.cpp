#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    Solution()
    {}
    void f()
    {            //01234567890123456789012345678901234567890
        string s ="this is a test! is it? I guess it is not.";
        
        //1. init
        string s1 (s,5,2); // init as substr
        cout<< s1<<endl;
        
        
        //2. append char
        char ch = '-';
        //s.append(ch); // cannot append char to string [fpermissive]
        s.append(1,ch); // use this method instead       
        
        //3. substr & find
        string t = s.substr(5,2);
        int pos = s.find(t);
        while(pos<s.size())
        {
            cout<< pos <<endl;
            pos = s.find(t,pos+1);
        }
        cout<<s<<endl;
        cout<<t<<endl;
        
    }  
};
int main()
{
    Solution s;
    s.f();
    return 0;
}