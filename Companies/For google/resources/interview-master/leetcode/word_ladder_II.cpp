#include <iostream>
#include <vector>
#include <string>
#include <tr1/unordered_set>
#include <tr1/unordered_map>
#include <stack>
#include <queue>

using namespace std;
using namespace tr1;

class Solution {
public:
    void findpath(unordered_map<int, vector<int> > &m, int head, string end, vector<string> &q, vector<vector<string> > &ans, vector<string> &s) {
		if (head == 0) {
			s.push_back(q[head]);
			vector<string> tmp;
	        for (int i = s.size() - 1; i >= 0; --i) {
	            tmp.push_back(s[i]);
	        }
			tmp.push_back(end);
			ans.push_back(tmp);
			s.pop_back();
			return;
		}
        else {
            s.push_back(q[head]);
            for (int i = 0; i < m[head].size(); ++i) findpath(m, m[head][i], end, q, ans, s);
			s.pop_back();
        }
    }
	
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        vector<string> q;
		vector<int> steps;
        vector<vector<string> > ans;
        unordered_map<int, vector<int> > m;
		unordered_map<string, int> hash;
		q.push_back(start);
		steps.push_back(1);
		hash[start] = 1;
		int head = 0;
        int l = start.length();
        int shortest = INT_MAX;
        while (head < q.size()) {
            string current = q[head];
            int step = steps[head];
            if (step >= shortest) break;
            for (int i = 0; i < l; ++i) {
                for (char c = 'a'; c <= 'z'; ++c) {
                	string tmp = current;
                    if (tmp[i] != c) {
                        tmp[i] = c;
                        if (tmp == end) {
                            if (shortest == INT_MAX) shortest = step + 1;
							vector<string> s;
                            findpath(m, head, end, q, ans, s);
                        }
                        else if (dict.count(tmp) > 0) {
							if (hash[tmp] == 0) {
	                            q.push_back(tmp);
								steps.push_back(step + 1);
	                            m[q.size() - 1].push_back(head);
								hash[tmp] = q.size() - 1;
							}
							else if (steps[hash[tmp]] == step + 1) {
								m[hash[tmp]].push_back(head);
							}
                        }
                    }
                }
            }
			++head;
        }
        return ans;
    }
};

int main() {
	Solution s;
	string start = "red", end = "tax";
	unordered_set<string> dict;
	dict.insert("ted"), dict.insert("tex"), dict.insert("red"), dict.insert("tax"), dict.insert("tad"), dict.insert("den"), dict.insert("rex"), dict.insert("pee");
	//dict.insert("a"), dict.insert("b"), dict.insert("c");
	// dict.insert("hot"), dict.insert("dot"), dict.insert("dog"), dict.insert("lot"), dict.insert("log");
	vector<vector<string> > ans = s.findLadders(start, end, dict);
	for (int i = 0; i < ans.size(); ++i) {
		cout << "[ ";
		for (int j = 0; j < ans[i].size(); ++j) {
			cout << ans[i][j] << " ";
		}
		cout << "]\n";
	}
	return 0;
}