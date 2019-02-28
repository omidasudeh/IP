/*
76. Minimum Window Substring
Hard

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"

Note:

    If there is no such window in S that covers all characters in T, return the empty string "".
    If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/
/*
Algorithm

  1  We start with two pointers, leftleftleft and rightrightright initially pointing to the first element of the string SSS.

  2  We use the rightrightright pointer to expand the window until we get a desirable window i.e. a window that contains all of the characters of TTT.

  3  Once we have a window with all the characters, we can move the left pointer ahead one by one. If the window is still a desirable one we keep on updating the minimum window size.

  4  If the window is not desirable any more, we repeat step  2step \; 2step2 onwards.


*/
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() == 0 || t.size() == 0)
            return "";
        int left = 0;
        int right= 0;
        int min_right = -1;
        int min_left = -1;
        
        unordered_map<char,pair<int,int>> map; //key: char in t. val: <need, ready>
        for(char c:t)
            if(map.find(c)==map.end())
                map[c] = pair<int, int>(1,0);
            else
                map[c].first++;
        int satisfied_count = 0;
        int sat_need = map.size(); 
        bool valid = false;
        //================================================
        while(right<s.size()){
            if(map.find(s[right]) != map.end()){//if relevant char
                map[s[right]].second++;
                if(map[s[right]].first == map[s[right]].second ){ // if have enough of char
                    satisfied_count++;
                    if(satisfied_count == sat_need){ // if all need satisfied
                        valid = true;
                        min_left = left;
                        min_right = right;
                    }
                }
            } 
            while(valid){
                if(map.find(s[left]) != map.end()){// if relevant char
                    if(map[s[left]].second > map[s[left]].first){//if left inc. does not hurt validity, increament left
                        map[s[left]].second--;
                        left++;
                        if(right-left<min_right-min_left){
                            min_left = left;
                            min_right = right;
                        }
                    }
                    else{
                        break;
                    }
                }
                else{
                    left++;
                    if(right-left<min_right-min_left){
                            min_left = left;
                            min_right = right;
                    }
                }
            }
            right++;
            if(right-left<min_right-min_left){
                min_right = right;
            }
        }
        return valid?s.substr(min_left, min_right-min_left+1):"";
    }
};