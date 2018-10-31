class Solution {
public:
    typedef vector<int> permu;
    
    permu nextperm(permu p, int n) {
        for (int i = n - 1; i > 0; --i) {
            if (p[i] > p[i - 1]) {
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
        return p;
    }
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        permu num(n);
        for (int i = 0; i < n; ++i) {
            num[i] = i + 1;
        }
        vector<int> total(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            total[i] *= total[i - 1] * i;
        }
        while (k > total[n]) k -= total[n];
        --k;
        
        string ans = "";
        
        for (int i = 0; i < n; ++i) {
            int index = k / total[n - i - 1];
            ans += num[index] + '0';
            num.erase(num.begin() + index);
            k -= index * total[n - i - 1];
        }
        return ans;
    }
};
