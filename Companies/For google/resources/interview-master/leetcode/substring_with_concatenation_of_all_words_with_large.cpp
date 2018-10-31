class Solution {
public:
    typedef unordered_map<string, int> hashtable;
    
    vector<int> findSubstring(string S, vector<string> &L) {
        hashtable A;
        int n = L.size();
        int wordsize = L[0].length();
        vector<int> res;
        for (string word : L) increment(A, word);
        for (int offset = 0; offset < wordsize; ++offset) {
            solve(A, S, n, wordsize, offset, res);
        }
        return res;
    }
private:
    void increment(hashtable &A, const string &x) {
        if (A.find(x) != A.end()) {
            A[x]++;
        }
        else A[x] = 1;
    }
    void solve(hashtable &A, string S, int n, int wordsize, int offset, vector<int> &res) {
        int leftmost = offset;
        hashtable B;
        for (int i = leftmost; i < S.length(); i += wordsize) {
            string word = S.substr(i, wordsize);
            increment(B, word);
            while (count(B, word) > count(A, word)) {
                string d = S.substr(leftmost, wordsize);
                decrement(B, d);
                leftmost += wordsize;
            }
            if (i - leftmost == (n - 1) * wordsize) {
                res.push_back(leftmost);
            }
        }
    }
    void decrement(hashtable &B, const string &x) {
        if (B.find(x) != B.end()) {
            B[x]--;
        }
    }
    int count(hashtable &m, const string &word) {
        if (m.find(word) != m.end()) return m[word];
        return 0;
    }
};
