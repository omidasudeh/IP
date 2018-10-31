#include <vector>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;

class Solution {
public:
   vector<int> findSubstring(string S, vector<string> &L) {
       // Start typing your C/C++ solution below
       // DO NOT write int main() function
       vector<int> res = vector<int>();
       int l = L.size();
       int n = S.length();
       int wl = 0;
       if (l > 0) wl = L[0].length();
       unordered_map<string, int> map;
       unordered_map<string, int>::iterator it;
       vector<int> has(l, 0);

       for (int start = 0; start < wl; ++start) {
           int index = start, num = 0;
            has = vector<int>(l, 0);      
           for (int i = 0; i < l; ++i) {
               if ((it = map.find(L[i])) != map.end()) {
                   has[(*it).second]++;
               }
               else {
                   map[L[i]] = i;
                   has[i]++;
               }         
           }
           for (int i = start; i < n; i += wl) {
               string tomatch = S.substr(i, wl);
               it = map.find(tomatch);
               if (it != map.end()) {
                   int second = (*it).second;
                   if (has[second]) {
                       has[second]--;
                       ++num;
                       if (num == l) {
                           res.push_back(index);
                           string head = S.substr(index, wl);
                           it = map.find(head);
                           has[(*it).second]++;
                           index += wl;
                           num--;                         
                       }
                   }
                   else {
                       string head = S.substr(index, wl);
                       it = map.find(head);
                       has[(*it).second]++;
                       index += wl;
                       --num;
                       i -= wl;
                   }
               }
               else {
                   index = i + wl;
                   num = 0;   
                    has = vector<int>(l, 0);                 
                   for (int j = 0; j < l; ++j) {
                       if ((it = map.find(L[j])) != map.end()) {
                           has[(*it).second]++;
                       }
                       else {
                           map[L[j]] = j;
                           has[j]++;
                       }         
                   }
               }
           }
       }
       return res;
   }
};

int main() {
    // Start typing your code here...
    cout << "Hello world!" << endl;
    Solution S;
    string s = "barfoothefoobarman";
    vector<string> L;
	L.push_back("foo");
	L.push_back("bar");
    vector<int> res = S.findSubstring(s, L);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
    return 0;
}
