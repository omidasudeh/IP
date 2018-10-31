class Solution {
public:
    typedef vector<int> permu;
    typedef vector<permu> permuset;
    int n;
    
    permu nextperm(permu p) {
        bool ok = false;
        for (int i = n - 1; i > 0; --i) {
            if (p[i] > p[i - 1]) {
                ok = true;
                int j;
                int index = i, min = p[i];
                for (j = i + 1; j < n; ++j) {
                    if (p[j] < min && p[j] > p[i - 1]) index = j, min = p[j];
                }
                swap(p[index], p[i - 1]);
                sort(p.begin() + i, p.end());
                break;
            }
        }
        if (!ok) return permu();
        return p;
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        n = num.size();
        sort(num.begin(), num.end());
        permu p = vector<int>(num.begin(), num.end());
        permuset ans;       
        while (p.size()) {
            ans.push_back(p);
            p = nextperm(p);
        }
        return ans;
    }
};
