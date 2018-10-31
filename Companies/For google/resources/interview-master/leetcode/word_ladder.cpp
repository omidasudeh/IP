class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<pair<string, int>> q;
        q.push(pair<string, int>(start, 1));
        int l = start.length();
        while (!q.empty()) {
            string current = q.front().first;
            int step = q.front().second;
            q.pop();
            for (int i = 0; i < l; ++i) {
                string tmp = current;
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (tmp[i] != c) {
                        tmp[i] = c;
                        if (tmp == end) return step + 1;
                        if (dict.count(tmp) > 0) {
                            q.push(pair<string, int>(tmp, step + 1));
                            dict.erase(tmp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
